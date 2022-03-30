#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
  int min_p = 1, max_p = 100;
  int min_c = 1, max_c = 100; 
  srand(time(NULL));
  int answer_p = -1;
  int answer_c = rand() % 100 + 1;
  bool player_win = false;
  
  while (true){
    int N = (rand() % (max_p - min_p)) + min_p;
    cout << N << "?\n";
    char A;
    cin >> A;
    if (A == 'y'){
      answer_p = N;
      break;
    }else if (A == 'u'){
      max_p = N;
    }else if (A == 'd'){
      min_p = N;
    }

    cout << min_c << '~' << max_c << '\n';
    cin >> N;
    if (N == answer_c){
      player_win = true;
      break;
    }else if (N < answer_c){
      min_c = N;
    }else if (N > answer_c){
      max_c = N;
    }
  }
  
  if (player_win){
    cout << "You Win!";
  }else{
    cout << "You Lose!";
  }
}
