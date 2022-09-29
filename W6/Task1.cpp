#include <iostream>
#include <vector>

using namespace std;

bool primeCheck (int n) {
    int Count = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (n%i == 0) {
            Count++;
        }
    }
    if (Count == 2) return true;
    return false;
}

int main() {
    int T, N, k, p, temp, constraint = 0;
    vector<int> Count;
    cin >> T;
    if (T < 1 || T > 1000) {
        cout << "Input value is off limit.";
        return 0;
    }
    for (int i = 0 ; i < T ; i++) {
        Count.push_back(0);
        vector<int> A;
        cin >> N >> k >> p;
        constraint += N;
        if (N < 1 || N > 500000 || p < 1 || p > 1000000000 || !primeCheck(p) || k < 0 || k >= p || constraint > 1000000) {
            cout << "Input value is off limit.";
            return 0;
        }
        for (int j = 0 ; j < N ; j++) {
            cin >> temp;
            if (T < 0 || T > 1000000000) {
                cout << "Input value is off limit.";
                return 0;
            }
            A.push_back(temp);
        }
        for (int j = 0 ; j < N ; j++) {
            for (int l = j + 1 ; l < N ; l++) {
                if ((A[j]*A[j] + A[l]*A[l] + A[j]*A[l])%p == k) Count[i]++;
            }
        }
    }
    for (int i = 0 ; i < T ; i++) {
        cout << Count[i] << endl;
    }
    return 0;
}