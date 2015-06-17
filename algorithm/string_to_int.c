#include <stdio.h>
#include <string.h>
int stringToInt(char* s) {
    int ret = 0;
    int times = 1;
    for(int i=strlen(s)-1;i>=0;i--){
        int digit = s[i]-'0';
        ret += digit*times;
        times = times*10;
    }
    return ret;
}

int main()
{
    char* roman = "1234";
    int iroman = stringToInt(roman);
    printf("%d\n", iroman);
    return 0;
}
