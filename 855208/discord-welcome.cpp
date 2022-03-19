#include <iostream>
#include <ctime>

#define KEYWORD 'u'
using std::string;
using std::cin;
using std::cout;

string formatter(string src, string words);
string greetings[] = {
  "野生的 u 出現。",
  "歡迎 u。打聲招呼吧！",
  "大家一起歡迎 u ！",
  "u 跳進了伺服器。",
  "u 剛剛滑入了伺服器中。",
  "u 剛剛著陸下來。",
  "u，恭喜您空降成功！",
  "u 已加入隊伍。",
  "很開心您來了，u。",
  "歡迎，u。 我們希望您帶個披薩來。",
  "u 剛剛出現了！",
  "u 在這裡。",
  "耶，您成功了，u！",
  "很高興見到您，u。",
  "u u u u。",
  "錯誤的使用者名稱：u。"
};

int main() {
  string username = "undefined";
  cout << "使用者名稱:";
  cin >> username;

  srand(time(NULL));
  int arraySize = sizeof(greetings) / sizeof(string);
  int randomIndex = rand() % arraySize;
  cout << "\n" << formatter(greetings[randomIndex], username);
}

string formatter(string src, string words) {
  int wordsLength = words.length();
  for(int i = 0; i < src.length(); i++) {
    if(src[i] == KEYWORD) {
      src[i] = '\0';
      src.insert(i, words);
      i += wordsLength;
    }
  }

  return src;
}
