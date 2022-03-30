#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
  int min = 0, max = 100;
  srand(time(NULL));
  int answer = -1;
  while (true){
    int N = (rand() % (max - min)) + min + 1;
    cout << N << "?\n";
    char A;
    cin >> A;
    if (A == 'y'){
      answer = N;
      break;
    }else if (A == 'u'){
      max = N;
    }else if (A == 'd'){
      min = N;
    }
  }
  cout << answer;
}
