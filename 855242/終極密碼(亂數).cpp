#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void Ask();
int Comparing(int*, int*, int*);
int maximum, minimum = 1, playerGuess, computerGuess, answer = 0;
bool abstain = false;

int main() {
  cout << "請設定遊戲的最大值(100~10000，若不在範圍內，預設為100):";
  cin >> maximum;  
  if (maximum < 100) {
    maximum = 100;
    cout << "輸入值太小，改為原預設值\n";
  }
  if (maximum > 10000) {
    maximum = 100;
    cout << "輸入值太大，改為原預設值\n";
  }
  
  int choice = 0;
  cout << "\n請輸入要遊玩的模式\n";
  AGAIN:
  cout << "(1) 普通模式\n";
  cout << "(2) 與電腦對戰模式\n";
  cout << "(3) 電腦猜題模式\n";
  cin >> choice;
  cout << "\n";

  int times = 0;
  srand(time(NULL));
  switch(choice){
    case 1:
      answer = rand() % (maximum - minimum - 1) + minimum + 1;
      do {
        Ask();
        Comparing(&playerGuess, &maximum, &minimum);
        if (abstain) {
          abstain = false;
          continue;
        }
        times ++;
      } while (answer != playerGuess);
      cout << "恭喜答對，共花了" << times << "次答對，遊戲結束";
      break;
    
    case 2:{
      answer = rand() % (maximum - minimum - 1) + minimum + 1;
      string winner = "電腦";
      do {
        Ask();
        Comparing(&playerGuess, &maximum, &minimum);
        if (abstain) {
          cout << "此回合視為棄權\n";
          abstain = false;
        }
        if (answer != playerGuess) {
          cout << "輪到電腦猜測:";
          computerGuess = rand() % (maximum - minimum - 1) + minimum + 1;
          cout << computerGuess << "\n";
          Comparing(&computerGuess, &maximum, &minimum);
        } else {
          winner = "你";
        }
      } while (answer != playerGuess && answer != computerGuess);
      cout << winner << "答對了，遊戲結束";
      break;
    }
    
    case 3:
      cout << "請輸入答案:";
      cin >> answer;
      while (answer <= 1 || answer >= maximum) {
        cout << "不在範圍內，請重新輸入答案:";
        cin >> answer;
      }
      do {
        cout << "電腦猜測(目前範圍:" << minimum << "~" << maximum << "):";
        computerGuess = rand() % (maximum - minimum - 1) + minimum + 1;
        cout << computerGuess << "\n";
        Comparing(&computerGuess, &maximum, &minimum);
        times ++;
        this_thread::sleep_for(chrono::milliseconds(500)); 
      } while (answer != computerGuess);
      cout << "電腦花了" << times << "次猜測，遊戲結束";
      break;

    default:
      cout << "\n並沒有此模式，請重新輸入要遊玩的模式\n";
      goto AGAIN;
  }  
}

void Ask() {
  cout << "從" << minimum << "到" << maximum << "輸入你要猜的數字:";
  cin >> playerGuess;
}

int Comparing(int *guess_p, int *maximum_p, int *minimum_p) {
  if (*guess_p >= *maximum_p || *guess_p <= *minimum_p) {
    abstain = true;
    cout << "請輸入範圍內數字!\n";
    return 0;
  } else if (*guess_p < answer) {
    *minimum_p = *guess_p;
    return *minimum_p;
  } else if (*guess_p > answer) {
    *maximum_p = *guess_p;
    return *maximum_p;
  } else {
    return 0;
  }
}
