#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int del_cnt = 0;
  int diff[26] = {0};
  string s1, s2;
  cin >> s1 >> s2;
  for (size_t i = 0; i < s1.length(); i++) {
    int idx = s1[i] - 'a';
    diff[idx]+=1;
  }
  for (size_t i = 0; i < s2.length(); i++) {
    int idx = s2[i] - 'a';
    diff[idx]-=1;
  }
  for (size_t i = 0; i < 26; i++) {
    //cout << diff[i] << endl;
    if (diff[i] != 0) {
      del_cnt += abs(diff[i]);
    }
  }
  cout << del_cnt;
  return 0;
}
