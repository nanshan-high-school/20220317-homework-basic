#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void welcome(string user){
    srand(time(0));  
    int gay = rand() % 3;
    string prefix[4] = {"" , "歡迎! " , "Yooo " , "很高興見到您， " };
    string suffix[4] = {" 滑入了伺服器" , " 我們希望你帶個pizza來" , " Wassup!" , ""};
    cout << prefix[gay] <<　user　<< suffix[gay];
}
int main() {
    string name;
    cout << "請輸入使用者名稱 : ";
    cin >> name;
    welcome(name);
}