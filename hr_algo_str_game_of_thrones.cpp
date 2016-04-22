#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
  string s;
  cin >> s;

  int flag = 0;
  int stat[26] = {0};
  for (size_t i = 0; i < s.length(); i++) {
    int idx = s[i] - 'a';
    if (stat[idx] == 0)
      stat[idx] += 1;
    else
      stat[idx] -= 1;
  }
  for (size_t i = 0; i < 26; i++) {
    flag += stat[i];
  }

  //cout << flag << endl;
  if (flag > 1) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  return 0;
}
