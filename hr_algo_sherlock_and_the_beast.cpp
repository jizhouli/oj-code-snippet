#include <vector>
#include <iostream>
#include <climits>
using namespace std;

// dynamic programming
void int_decompose(vector<int> splits, int remain, int tries, vector<int> &results){
    if(remain == 0 && tries != 0){
        results.push_back(tries);
        return;
    }

    for(vector<int>::iterator it=splits.begin(); it!=splits.end(); it++){
        if(remain >= *it){
            int_decompose(splits, remain-(*it), tries*10+(*it), results);
        }
    }
}



//greedy algorithm for specific problem of 3 and 5
string greedy_int_decompose(int n){
    string s = "-1";
    int max_multiple = n/3;
    for(int i=max_multiple; i>=0; i--){
        int remain = n - i*3;
        if (remain%5 != 0)
            continue;

        string s1(i*3, '5');
        string s2(remain, '3');
        s = s1 + s2;
        break;
    }
    return s;
}

int main(int argc, char* argv[]){
    int t;
    vector<int> decent_number;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        decent_number.push_back(n);
    }

    for(vector<int>::iterator it=decent_number.begin(); it!=decent_number.end(); it++){
        cout << greedy_int_decompose(*it) << endl;
    }

    /*
    vector<int> splits;
    splits.push_back(3);
    splits.push_back(5);
    for(vector<int>::iterator it=decent_number.begin(); it!=decent_number.end(); it++){
        vector<int> results;
        int_decompose(splits, *it, 0, results);

        cout << *it << " : ";
        for(vector<int>::iterator it=results.begin(); it!=results.end(); it++)
            cout << *it << " ";
        cout << endl;

        int min = INT_MAX;
        for(vector<int>::iterator it=results.begin(); it!=results.end(); it++){
            if(min > *it)
                min = *it;
        }

        string output;
        if(min == INT_MAX)
            cout << "-1" << endl;
        else{
            cout << min << endl;
            while(min > 0){
                if(min%10 == 3){
                    string s(3, '5');
                    output = s + output;
                    min = min/10;
                }
                else if(min%10 == 5){
                    string s(5, '3');
                    output = s + output;
                    min = min/10;
                }
                else{
                    cout << "error" << endl;
                    return 1;
                }
            }
            cout << output << endl;
        }
    }
    */

    return 0;
}

