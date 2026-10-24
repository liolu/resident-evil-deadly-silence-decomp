#!/usr/bin/env python3
"""Run mwcc through macOS Wibo for strictly ASCII source trees.

sjiswrap's in-process PE loader needs FormatMessageA, absent in macOS Wibo.
ASCII has identical UTF-8 and Shift-JIS bytes. Reject other input instead of
silently compiling it with a different encoding. Compiler flags are forwarded.
"""
import os
from pathlib import Path
import sys

TEXT_SUFFIXES = {'.c', '.cc', '.cp', '.cpp', '.cxx', '.c++', '.h', '.hh', '.hp',
                 '.hpp', '.hxx', '.h++', '.pch', '.pch++', '.inc'}


def validate(argv):
    if argv.count('-c') != 1:
        raise ValueError('expected exactly one source argument')
    source = Path(argv[argv.index('-c') + 1])
    paths = {source}
    # Scan the source directory as well as every include directory. This covers
    # local quoted headers and nested includes, including scratch assignments.
    paths.update(p for p in source.parent.rglob('*')
                 if p.suffix.lower() in TEXT_SUFFIXES - {'.c', '.cc', '.cp', '.cpp', '.cxx', '.c++'})
    directories = set()
    for i, arg in enumerate(argv):
        if arg == '-i':
            directories.add(Path(argv[i + 1]))
        elif arg.startswith('-i') and arg not in ('-inline', '-interworking', '-ipa'):
            # Only configure.py's documented '-i DIR' form is supported.
            raise ValueError('use separate -i DIR include arguments')
        if arg.startswith('@'):
            raise ValueError('response files require the Windows Shift-JIS wrapper')
    for directory in directories:
        paths.update(p for p in directory.rglob('*') if p.is_file() and p.suffix.lower() in TEXT_SUFFIXES)
    for path in sorted(paths):
        if not path.read_bytes().isascii():
            raise ValueError(f'non-ASCII compiler input: {path}; macOS requires ASCII sources/headers')


def main():
    if len(sys.argv) < 4:
        raise SystemExit('usage: macos_compiler.py WIBO COMPILER [compiler arguments]')
    try:
        validate(sys.argv[3:])
    except (ValueError, OSError, IndexError) as exc:
        raise SystemExit(str(exc))
    os.execv(sys.argv[1], sys.argv[1:])


if __name__ == '__main__':
    main()
