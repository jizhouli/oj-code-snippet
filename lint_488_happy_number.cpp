#include <iostream>
#include <set>

using namespace std;

bool isHappy(int n) {
    if (n < 0)
        return false;

    set<int> history;
    //cout << n << " check" << endl;
    while (true) {
        int oldn = n; 
        int newn = 0;
        for (int i=n%10; n!=0; n=n/10) {
            i = n % 10;
            newn += (i*i);
        }
        //cout << " " << oldn << " -> " << newn << endl;
        n = newn;

        if (n==1 || history.find(n) != history.end() || n<0)
            break;
        history.insert(n);
    }

    if (n==1)
        return true;
    else
        return false;
}

int main(int argc, char* argv[]) {
    int n;
    bool is;

    for (n=0;n<100;n++) {
        is = isHappy(n);
        cout << "happy num " << n << " - " << is << endl;
    }
}
