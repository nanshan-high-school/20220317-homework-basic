#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void ugc(void);
void cgu(void);
void ugccgu(void);

int main() {
    cout << "按1使用猜電腦選的數字,按2使用讓電腦猜你選的數字,按3使用你和電腦互猜\n";
    int a;
    cin >> a;
    if (a == 1) {
        ugc();
    } else if (a == 2) {
        cgu();
    } else {
        ugccgu();
    }
}

void ugc(void) {
    int myans;
    int max = 100, min = 0;
    cout << "請輸入從0~100的數字" << "\n";
    
    srand(time(NULL));
    int cans = rand() % 101;

    bool a = 1;
    while (a){
    cin >> myans;
        if (myans < cans) {
            min = myans;
            cout << min << "~" << max << "\n";
        } else if (myans > cans) {
            max = myans;
            cout << min << "~" << max << "\n";
        } else {
            cout << "你猜到了!";
            a = 0;
    }
    }
}

void cgu(void) {
    srand(time(NULL));
    cout << "Please think a number from 0 to 100 in your mind\n";
    bool a = 1;
    string identify;
    int min = 0, max = 100;
    while (a) {
        int ans = rand() % (max - min + 1) + min;
        cout << ans << "\nlower, higher, or correct\n";
        cin >> identify;
        if (identify == "lower") {
            max = ans + 1;
        } else if (identify == "higher") {
            min = ans - 1;
        } else if (identify == "correct"){
            a = 0;
        } else {
            cout << "lower, higher, or correct\n";
            cin >> identify;
        }
    }
}

void ugccgu(void) {
    string identify;
    int myans;
    srand(time(NULL));
    int max = 101;
    int min = 0;
    int cans = rand() % 101;
    bool a = 1;
    while (a) {
        int ans = rand() % (max - min + 1) + min;
        cout << "請想一個從0~100的數並輸入一個從0~100的數";
        cin >> myans;
        cout << ans << "\n";
        if (myans < cans) {
            min = myans;
            cout << min << "~" << max << "\n";
        } else if (myans > cans) {
            max = myans;
            cout << min << "~" << max << "\n";
        } else {
            cout << "你贏了!";
            a = 0;
        }
        cin >> identify;
        if (identify == "lower") {
            max = ans + 1;
        } else if (identify == "higher") {
            min = ans - 1;
        } else if (identify == "correct"){
            a = 0;
            cout << "我贏了!";
        } else {
            cout << "lower, higher, or correct\n";
            cin >> identify;
        }
    }
}