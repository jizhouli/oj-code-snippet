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

  for (vector<string>::iterator it=strs.begin(); it!=strs.end(); it++){
    string s = *it;
    int len = s.length();
    if (len%2 == 1) {
      cout << -1 << endl;
      continue;
    }

    int cnt = 0;
    int signs[26] = {0};
    for (size_t i = 0; i < len/2; i++) {
      signs[s[i] - 'a'] += 1;
    }

    for (size_t i = len/2; i < len; i++) {
      if (signs[s[i] - 'a'] <= 0){
        cnt += 1;
      }
      signs[s[i] - 'a'] -= 1;
    }
    cout << cnt << endl;
  }
  return 0;
}
