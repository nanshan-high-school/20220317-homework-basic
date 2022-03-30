#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void word(string user);

int main() {
    string name;
    cout << "使用者名稱: ";
    cin >> name;
    word(name);
} 
void word(string user){
    srand(time(0));  
    int jack = rand() % 4;
    string f[5] = {"耶，您成功了，" , "" , "很高興見到您， " , "歡迎，" , "野生的 " };
    string b[5] = {"!" , " 剛剛著陸下來。" , "。" , "。 我們希望您帶個披薩來。" , " 出現。"};
    cout << f[jack] <<　user　<< b[jack];
}