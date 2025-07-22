# homework

Ackermann Function:
```cpp
#include <iostream>

int ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return ackermann(m - 1, 1);
    } else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

int main() {
    int a;
    int b;
    std::cout << "input A number: " << std::endl;
    std::cin >> a; 
    std::cout << "input B number: " << std::endl;
    std::cin >> b; 
    std::cout << "Ackermann(A, B) = " << ackermann(a, b) << std::endl;return 0;
}
```
#時間複雜度（Theoretical）
極快成長，例如：

A(1, n) = n + 2 → 線性 O(n)

A(2, n) = 2n + 3 → 線性 O(n)

A(3, n) = 2^(n+3) - 3 → 指數級 O(n^2)

A(4, 1) ≈ 2^65536 - 3 → 無法實際計算

#解題說明

遞迴公式轉換成code
A(m, n) =
    n + 1                 if m = 0 →         if (m == 0) {return n + 1;}
    
    A(m - 1, 1)           if m > 0 and n = 0 →        else if (n == 0) {return ackermann(m - 1, 1)};
    
    A(m - 1, A(m, n - 1)) if m > 0 and n > 0  →       else {return ackermann(m - 1, ackermann(m, n - 1))};
    
    
#測試與驗證
![可愛貓咪](https://github.com/1234566QQQ/homework/blob/main/42%E6%9C%83%E7%88%86%E6%8E%89.png)
![可愛貓咪](https://github.com/1234566QQQ/homework/blob/main/Ackermann(1%2C%201)%20%3D%203.png)
Ackermann(1, 1) = 3
Ackermann(4, 2)會爆掉

使用的IDE: https://www.programiz.com/cpp-programming/online-compiler/
