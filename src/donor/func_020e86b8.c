/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* mfci_str_to_uint from https://github.com/Yotona/twewy libs/cri/src/mfci.c (license: CC0-1.0), reused by tools/donor_match.py
 */
unsigned long func_020e86b8(const char *str, char **end, int base) {
    unsigned long val = 0;
    int digit;

    while (1) {
        if (*str >= '0' && *str <= '9') {
            digit = *str - '0';
        } else if (*str >= 'a' && *str <= 'f') {
            digit = *str - 'a' + 10;
        } else if (*str >= 'A' && *str <= 'F') {
            digit = *str - 'A' + 10;
        } else {
            break;
        }
        val = val * base + digit;
        str++;
    }
    *end = (char *) str;
    return val;
}
