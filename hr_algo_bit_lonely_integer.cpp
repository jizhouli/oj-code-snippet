#include <vector>
#include <iostream>
#include <limits>
using namespace std;

int lonelyinteger(vector<int> inputs){
    int li = 0;
    for(vector<int>::iterator it=inputs.begin(); it!=inputs.end(); it++)
        li^=(*it);
    return li;
}

int main(int argc, char* argv[]){
    int res;

    int input_size;
    cin >> input_size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> inputs;
    int input;
    for(int i=0;i<input_size;i++){
        cin >> input;
        inputs.push_back(input);
    }

    res = lonelyinteger(inputs);
    cout << res;

    return 0;
}
