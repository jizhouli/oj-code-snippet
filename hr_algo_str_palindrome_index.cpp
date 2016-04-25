#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

bool is_palindrome(string s){
  int i = 0;
  int len = s.length();
  while (i < len-i-1) {
    if (s[i] != s[len-i-1])
      return false;
    i++;
  }
  return true;
}

int main(){
  int n;
  cin >>n;

  std::vector<string> strs;
  for (size_t i = 0; i < n; i++) {
    string s;
    cin >> s;
    strs.push_back(s);
  }

  for (vector<string>::iterator it=strs.begin(); it!=strs.end(); it++){
    string s = *it;
    // find palindrome index
    int i = 0;
    int len = s.length();
    int palindrome_index = -1;
    while (i < len-i-1) {
      if (s[i] != s[len-i-1]){
        if (is_palindrome(s.substr(i+1, len-i-1-i))) {
          palindrome_index = i;
        } else if (is_palindrome(s.substr(i, len-i-1-i))) {
          palindrome_index = len-i-1;
        } else {
          palindrome_index = INT_MAX;
        }
        break;
      }
      i++;
    }
    cout << palindrome_index << endl;
  }
  return 0;
}
