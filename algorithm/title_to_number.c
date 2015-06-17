#include <string.h>
int titleToNumber(char* s) {
    int times = 1;
    int ret = 0;
    for (int i=strlen(s)-1;i>=0;i--) {
        int v = s[i]-'A'+1;
        ret += (v*times);
        times*=26;
    }
    return ret;
}
