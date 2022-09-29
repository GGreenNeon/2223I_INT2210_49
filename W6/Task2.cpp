#include <iostream>
#include <vector>

using namespace std;

int main() {
    int K, N, temp;
    vector<int> A;
    cin >> N >> K;
    if (N < 1 || N > 1000000 || K < 1 || K > 2000000) {
        cout << "Input value is off limit.";
        return 0;
    }
    for (int i = 0 ; i < N ; i++) {
        cin >> temp;
        if (temp < 1 || temp > 1000000) {
            cout << "Input value is off limit.";
            return 0;
        }
        A.push_back(temp);
    }
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            if (A[i] + A[j] == K) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}