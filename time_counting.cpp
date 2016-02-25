#include <ctime>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
  clock_t begin_clock = clock();
  time_t begin_time = clock();

  vector<string> str;
  for(int i=0;i<1000000;i++)
      str.push_back("hello world");

  clock_t end_clock = clock();
  time_t end_time = clock();
  double elapsed_secs = double(end_clock - begin_clock)/CLOCKS_PER_SEC;
  cout << "cpu  time(sec) "<< elapsed_secs << endl;
  cout << "real time(sec) "<< difftime(end_time,begin_time)/1000/1000 << endl;
}
