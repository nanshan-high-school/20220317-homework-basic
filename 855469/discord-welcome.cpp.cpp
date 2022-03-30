#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
string welcome(string);

int main() {
  
  srand(time(NULL));
  string Name;
  cin >> Name;
  cout << welcome(Name);
}

string welcome(string Name){
  string Welcomes[][2]{
    {"歡迎","你好帥"},
    {"你媽媽好漂亮,",""}
  };
  int N = rand() % (sizeof(Welcomes)/sizeof(Welcomes[0]));
  return Welcomes[N][0] + Name + Welcomes[N][1];
}