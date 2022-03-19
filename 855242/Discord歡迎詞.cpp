#include <iostream>
using namespace std;

string welcome(string);

int main() {
  string name;
  cout << "請輸入名字:";
  cin >> name;
  cout << welcome(name);
}

string welcome (string name) {
  string arr[3][2] = {{"你好，","，我們希望你帶個披薩來"},{"","已加入隊伍"},{"野生的","出現了"}};
  srand(time(NULL));
  int random;
  random = rand() % 3;
  return arr[random][0] + name + arr[random][1];
}
