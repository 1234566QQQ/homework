# homework
ackermann function 
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
    std::cout << "Ackermann(A, B) = " << ackermann(a, b) << std::endl;

    return 0;
}
