#include <iostream>
using namespace std;

const int MAX = 1000

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
    string S = "aab";


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



