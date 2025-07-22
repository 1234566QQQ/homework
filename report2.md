
# homework
PowerSet Function:
```cpp
#include <iostream>
using namespace std;

const int MAX = 1000;

string results[MAX];
int resultCount = 0;

bool isDuplicate(string current) {
    for (int i = 0; i < resultCount; ++i) {
        if (results[i] == current) {
            return true;
        }
    }
    return false;
}

void powerSet(string S, int index, string current) {
    if (index == S.length()) {
        if (!isDuplicate(current)) {
            cout << current << endl;
            results[resultCount++] = current;
        }
        return;
    }

    powerSet(S, index + 1, current);

    powerSet(S, index + 1, current + S[index]);
}

int main() {
   cout << "Input a string" << endl; 
   std::string S; 
   getline(cin, S);
    for (int i = 0; i < S.length(); ++i) {
        for (int j = i + 1; j < S.length(); ++j) {
            if (S[i] > S[j]) {
                char temp = S[i];
                S[i] = S[j];
                S[j] = temp;
            }
        }
    }

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

使用遞迴並配合一個字串紀錄可能組合

Powerset

   • 此函數會需要三個參數 S 、 index 與 current, MAX
   • S 為一字串，表示 n 個元素的集合。 e.g. S = { a, b, c } 表示為“ abc”
   • index 是一整數索引值，同時也是當前遞迴深度 -1 。 0 ≤ index ≤ n
   • current 是當前遞迴記錄下的可能組合之一
   • MAX 是最多組合數
   
   在每一層遞迴中，你有兩個選擇：

     包含 S[index] 到 current 裡

     不包含 S[index] 到 current 裡

     當 index == S.length()，代表已經走到集合尾端，可以輸出一個完整的子集合了。

     處理「重複組合」的問題。

     舉例:

     原本的遞迴會產生這些結果
     
     string S "aab"  
     b  
     a  
     ab  
     a  
     ab  
     aa  
     aab= "aab";  出現重複組合
     
     方法:

     先把 String裡面每個字元排序 方便尋找相同字元
     
     之後建立 Array results[] 存所有組合
     
     檢查字串是否已經存在於 results[] 中
     
     之後去除重複

    
    
#測試與驗證
![可愛貓咪](https://github.com/1234566QQQ/homework/blob/main/42%E6%9C%83%E7%88%86%E6%8E%89.png)
![可愛貓咪](https://github.com/1234566QQQ/homework/blob/main/Ackermann(1%2C%201)%20%3D%203.png)
Ackermann(1, 1) = 3
Ackermann(4, 2)會爆掉
使用的IDE: https://www.programiz.com/cpp-programming/online-compiler/
