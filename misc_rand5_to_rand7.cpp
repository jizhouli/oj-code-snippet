/*
 * 给定一个能够生成均匀1~5随机枚举数的函数，请设计一个能够生成均匀1~7随机枚举数的函数。
 * http://stackoverflow.com/questions/137783/expand-a-random-range-from-1-5-to-1-7
 */

#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int rand5(){
  return rand() % 5 + 1;
}

int _rand7a(){
  int i = 0;
  do {
    i = (rand5()-1)*5 + rand5();
  } while(i>21);
  return i % 7 + 1;
}

int _rand7b(){
  int rand_map[5][5] = {
    { 1, 2, 3, 4, 5 },
    { 6, 7, 1, 2, 3 },
    { 4, 5, 6, 7, 1 },
    { 2, 3, 4, 5, 6 },
    { 7, 0, 0, 0, 0 }
  };

  int r = 0;
  while (r == 0) {
    int i = rand5() - 1;
    int j = rand5() - 1;
    r = rand_map[i][j];
  }
  return r;
}

int rand7(){
  return _rand7a();
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  int stat[7] = {0};

  for (size_t i = 0; i < 10*1000*1000; i++) {
    stat[rand7()-1]++;
  }

  for (size_t i = 0; i < sizeof(stat)/sizeof(stat[0]); i++) {
    cout << i+1 << ":\t" << stat[i] << endl;
  }
  return 0;
}
