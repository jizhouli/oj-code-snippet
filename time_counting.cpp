#include <ctime>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]){
  clock_t begin_clock = clock();
  time_t begin_time = time(NULL);

  vector<string> str;
  for(int i=0;i<1000000*100;i++)
      str.push_back("hello world");

  clock_t end_clock = clock();
  time_t end_time = time(NULL);
  double cpu_secs = double(end_clock - begin_clock)/CLOCKS_PER_SEC;
  cout << "cpu  time(sec) "<< cpu_secs << endl;
  double elapsed_secs = difftime(end_time,begin_time);
  cout << "real time(sec) "<< fixed << setprecision(5) <<  elapsed_secs << endl;
}
