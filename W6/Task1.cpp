#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T, N, k, p, temp;
    int count;
    cin >> T;
    for (int i = 0; i < T; i++) {
        count = 0;
        vector <int> A;
        cin >> N >> k >> p;
        for (int j = 0; j < N; j++) {
            cin >> temp;
            A.push_back(temp);
        }
        
        for (int j = 0; j < N; j++) {
            for (int l = j + 1; l < N; l++) {
                if ((A[j] * A[j] + A[l] * A[l] + A[j] * A[l]) % p == k) count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}