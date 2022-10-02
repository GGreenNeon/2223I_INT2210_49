#include <iostream>
#include <string>
using namespace std;

int main() {
    int maxLength = 1 , occurCount = 1;
    string S;
    cin >> S;
    
    for (int i = 0; i < S.length(); i++) {
        for (int j = 1; j < S.length() - i; j++) {
            for (int k = i + 1; k < S.length() + 1 - j; k++) {
                if (S.substr(i, j) == S.substr(k, j)) occurCount++;
                //cout << S.substr(i, j) << ' ' << S.substr(k, j) << endl;
            }
            if (occurCount > 1 && j > maxLength) maxLength = j;
            occurCount = 1;
        }
    }
    cout << maxLength;
    
    return 0;
}