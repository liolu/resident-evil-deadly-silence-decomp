/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* Ov005_GetCoListEntryColumn from https://github.com/sturmds/advance-wars-dual-strike-decomp
 * src/game/ov005/ov005_get_co_list_entry_column.c (license: CC0-1.0), reused by tools/donor_match.py */
typedef unsigned char u8;
extern u8 data_02122ef2[][4];
u8 func_020b5818(int index) {
    return data_02122ef2[index][0];
}
