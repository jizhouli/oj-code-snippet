#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> strs;
  for (size_t i = 0; i < n; i++) {
    string s;
    cin >> s;
    strs.push_back(s);
  }

  int gems[26] = {0};
  for(vector<string>::iterator it=strs.begin(); it!=strs.end(); it++){
    string s = *it;
    int _gems[26] = {0};
    for (size_t i = 0; i < s.length(); i++) {
      _gems[s[i] - 'a'] += 1;
    }
    for (size_t i = 0; i < 26; i++) {
      if (_gems[i] > 0) {
        gems[i] += 1;
      }
    }
  }

  int gem_cnt = 0;
  for (size_t i = 0; i < 26; i++) {
    //cout << i << ": " << gems[i] << endl;
    if(gems[i] == n)
      gem_cnt++;
  }
  cout << gem_cnt << endl;
  return 0;
}
