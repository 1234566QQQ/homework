
# homework
PowerSet Function:
```cpp
#include <iostream>
#include <string>
using namespace std;

void powerSet(string S, int index, string current) {
    if (index == S.length()) {
        cout << current << endl; 
        return;
    }

    powerSet(S, index + 1, current);

    powerSet(S, index + 1, current + S[index]);
}

int main() {
    string S = "abc";
    powerSet(S, 0, "");
    return 0;
}
```
#時間複雜度（Theoretical）

每個字元都有兩種選擇：

包含 或 不包含

這就像一棵二元樹，每一層代表對某一個字元的選擇分支：

根節點（index = 0）有兩個子節點（包含或不包含 S[0]）

每個節點繼續分成兩個分支，共有 2^n 條路徑（葉節點）

因此，總共有 2ⁿ 個子集合，也就是你會進入遞迴函數 2ⁿ 次，每次最多做 O(n) 的工作
（如果你用 string 做 concat，可能每次都複製一個長度為 k 的子字串，平均約 O(n)，但在大多數語言或情況中可視為 O(1)）。


#解題說明

遞迴公式轉換成code

使用遞迴並配合一個字串 ( 或字元陣列 ) 紀錄可能組合：

Powerset

   • 此函數會需要三個參數 S 、 index 與 current
   • S 為一字串，表示 n 個元素的集合。 e.g. S = { a, b, c } 表示為“ abc”
   • index 是一整數索引值，同時也是當前遞迴深度 -1 。 0 ≤ index ≤ n
   • current 是當前遞迴記錄下的可能組合之一

   在每一層遞迴中，你有兩個選擇：

     包含 S[index] 到 current 裡

     不包含 S[index] 到 current 裡

     當 index == S.length()，代表已經走到集合尾端，可以輸出一個完整的子集合了。


    
    
#測試與驗證
![可愛貓咪](https://github.com/1234566QQQ/homework/blob/main/42%E6%9C%83%E7%88%86%E6%8E%89.png)
![可愛貓咪](https://github.com/1234566QQQ/homework/blob/main/Ackermann(1%2C%201)%20%3D%203.png)
Ackermann(1, 1) = 3
Ackermann(4, 2)會爆掉
使用的IDE: https://www.programiz.com/cpp-programming/online-compiler/
