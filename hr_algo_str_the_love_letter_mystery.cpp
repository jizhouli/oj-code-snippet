#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]){
  int n;
  cin >> n;
  vector<string> strs;
  for (size_t i = 0; i < n; i++) {
    string s;
    cin >> s;
    strs.push_back(s);
  }

  for(vector<string>::iterator it=strs.begin(); it!=strs.end(); ++it){
    string s = *it;
    int mod_cnt = 0;
    for (size_t i = 0; i < s.length()/2; i++) {
      int l=i;
      int r=s.length()-i-1;
      mod_cnt += abs(s[l] - s[r]);
    }
    cout << mod_cnt << endl;
  }
  return 0;
}
