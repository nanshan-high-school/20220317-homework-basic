#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void welcome(string);

int main() {
    string name;
    cin >> name;
    welcome(name);
}

void welcome(string name) {
    string welcomes [7][2] {
        "野生的", "出現。",
        "歡迎", "打聲招呼吧！",
        "大家一起歡迎", " 跳進了伺服器。",
        "歡迎，", "。 我們希望您帶個披薩來。",
        "", "跳進了伺服器。",
        "很高興見到您，", "",
        "耶，您成功了，", "!",
    };
    srand(time(NULL));
    int a = rand() % 7;
    cout << welcomes[a][0] << name << welcomes[a][1];
}