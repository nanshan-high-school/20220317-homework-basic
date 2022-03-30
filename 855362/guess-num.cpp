#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
  int t = 0 ;
  int s = 0 ;
  cout << "1.odd or 2.even: ";
  cin >> t ;
  system("clear");
  if(t == 1){
    srand(time(0));
    for(int i = 0 ;i < 500 ;i++ ){
      s = rand()%6+1;
      system("clear");
    }
    cout << s << "\n";
    if(s%2 == 0){
      int cmax = 1000, cmin = 0,  hmax = 1000, hmin = 0, hguess = 0, cguess = 0 ; 
      srand(time(0));
      int cans = rand()%1001; 
      cout << cans;
      while(true){
        cguess = rand()%(hmax - hmin) + hmin;
        cout <<"computer's turn: "<<cguess <<" 1.down 2.up 3.right: ";
        cin >> hguess;
        if (hguess == 1){
          hmax = cguess -1 ;
        }else if (hguess == 2){
          hmin = cguess +1 ;
        }else if (hguess == 3){
          cout << "you're lose";
          break;
        }
        cout <<"your turn : "<< cmin << " ~ " << cmax << ": ";
        cin >> hguess;
        if(hguess == cans){
          cout << "you're win";
          break;
        }else if(hguess > cans){
          cmax = hguess ;
        }else if(hguess < cans){
          cmin = hguess ;
        }
      }
    }else if(s%2 == 1){
      int cmax = 1000, cmin = 0,  hmax = 1000, hmin = 0, hguess = 0, cguess = 0 ; 
      srand(time(0));
      int cans = rand()%50 + 50; 
      while(true){
        cout <<"your turn : "<< cmin << " ~ " << cmax << ": ";
        cin >> hguess;
        if(hguess == cans){
          cout << "you're win";
          break;
        }else if(hguess > cans){
          cmax = hguess ;
        }else if(hguess < cans){
          cmin = hguess ;
        }
        cguess = rand()%(hmax - hmin) + hmin;
        cout <<"computer's turn: "<<cguess <<" 1.down 2.up 3.right: ";
        cin >> hguess;
        if (hguess == 1){
          hmax = cguess -1 ;
        }else if (hguess == 2){
          hmin = cguess +1 ;
        }else if (hguess == 3){
          cout << "you're lose";
          break;
        }
      }
    }
  }else if(t == 2){
    for(int i = 0 ;i < 500 ;i++ ){
      s = rand()%6+1;
      system("clear");
    }
    cout << s << "\n";
    if(s%2 == 0){
      int cmax = 1000, cmin = 0,  hmax = 1000, hmin = 0, hguess = 0, cguess = 0 ; 
      srand(time(0));
      int cans = rand()%50 + 50; 
      while(true){
        cout <<"your turn : "<< cmin << " ~ " << cmax << ": ";
        cin >> hguess;
        if(hguess == cans){
          cout << "you're win";
          break;
        }else if(hguess > cans){
          cmax = hguess ;
        }else if(hguess < cans){
          cmin = hguess ;
        }
        cguess = rand()%(hmax - hmin) + hmin;
        cout <<"computer's turn: "<<cguess <<" 1.down 2.up 3.right: ";
        cin >> hguess;
        if (hguess == 1){
          hmax = cguess -1 ;
        }else if (hguess == 2){
          hmin = cguess +1 ;
        }else if (hguess == 3){
          cout << "you're lose";
          break;
        }
      }
    }else if(s%2 == 1){
      int cmax = 1000, cmin = 0,  hmax = 1000, hmin = 0, hguess = 0, cguess = 0 ; 
      srand(time(0));
      int cans = rand()%1001; 
      cout << cans;
      while(true){
        cguess = rand()%(hmax - hmin) + hmin;
        cout <<"computer's turn: "<<cguess <<" 1.down 2.up 3.right: ";
        cin >> hguess;
        if (hguess == 1){
          hmax = cguess -1 ;
        }else if (hguess == 2){
          hmin = cguess +1 ;
        }else if (hguess == 3){
          cout << "you're lose";
          break;
        }
        cout <<"your turn : "<< cmin << " ~ " << cmax << ": ";
        cin >> hguess;
        if(hguess == cans){
          cout << "you're win";
          break;
        }else if(hguess > cans){
          cmax = hguess ;
        }else if(hguess < cans){
          cmin = hguess ;
        }
      }
    }
  }
}