#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    string time;
    cout << "input:";
    cin >> time;

    int h,m,s;
    char sign[8];
    sscanf(time.c_str(), "%d:%d:%d%s", &h, &m, &s, sign);

    if (strcmp(sign, "PM") == 0)
        h = h%12 + 12;
    else if (strcmp(sign, "AM") == 0)
        h = h%12;
    else
        return 1;

    printf("%02d:%02d:%02d", h, m, s);
    return 0;
}
