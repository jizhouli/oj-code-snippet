#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int base = 26;
        int times = 1;
        int ret = 0;
        for (string::reverse_iterator rit=s.rbegin(); rit<s.rend(); rit++) {
            int i = (*rit)-'A'+1;
            ret+=(i*times);
            times*=base;
        }
        
        return ret;
    }
};
