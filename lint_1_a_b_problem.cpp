#include <iostream>
using namespace std;

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        return add_iterative(a, b);
    }

    int add_recursive(int a, int b){
        if(b == 0)
            return a;
        else
            return add_recursive(a^b, (a&b)<<1);
    }

    int add_iterative(int a, int b){
        int sum = 0;
        int carry = 0;
        while(b!=0){
            sum = a^b;
            carry = a&b;
            a = sum;
            b = carry << 1;
        }
        return a;
    }
};

int main(int argc, char* argv[]){
    Solution sol;
    int a = 3;
    int b = 5;
    int sum = sol.aplusb(a, b);
    cout << a << " + " << b << " = " << sum << endl;
    return 0;
}
