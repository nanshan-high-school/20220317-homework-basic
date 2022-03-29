# 20220317 本週作業

## 作業一：終極密碼（guess-num.cpp）

難度（至少）三選一，請以自己的實力繳交

  * 基礎版：電腦隨機選 0~100 的數字當題目，讓使用者猜
  * 中階版：使用者心裡出題，讓電腦隨機在合理範圍內猜，使用者要提供給電腦正確的猜數範圍
  * 進階版：使用者跟電腦以上述規則互猜，誰先猜到誰獲勝。

## 作業二：Discord 歡迎訊息（discord-welcome.cpp）
使用 welcome function 來處理 Discord 歡迎訊息字串，回傳（`return`）一個完整的歡迎訊息到 main function，並在 main function 中輸出歡迎訊息的結果。

請在 welcome function 中指定一個 string 二維陣列，定義歡迎詞的前綴（prefix）與後綴（suffix），並搭配 `rand()` 來實現隨機歡迎訊息的結果。

`main` function 的範例如下：

```cpp
int main() {
  string name;
  cin >> name;
  
  cout << welcome(name);
}
```

`welcome` function 回傳的範例如下：

```cpp
return prefix + name + suffix;
```

輸出範例：

* 名字出現在字串中間
  * `耶，您成功了，小克！`
  * `歡迎，小克。我們希望您帶個披薩來。`
* 名字出現在前面
  * `小克跳進了伺服器。`
* 名字出現在後面
  * `很高興見到您，小克`

:bulb: 小提示：可以透過空字串來讓名字看起來是在句首或句尾。
