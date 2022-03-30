#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
  srand(time(NULL));  
  int answer = rand() % 100 + 1;
  int N, max = 100, min = 1;
  cout << "1~100\n";
  cin >> N;
  while(N != answer){
    if(N < answer){
      min = N;
      cout << min << '~' << max << '\n';
    }else{
      max = N;
      cout << min << '~' << max << '\n';
    }
    cin >> N;
    }
  cout << "yes";
}
