#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K, N, temp;
    vector <int> A;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        A.push_back(temp);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i] + A[j] == K) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";

    return 0;
}