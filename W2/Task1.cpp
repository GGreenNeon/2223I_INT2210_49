#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n <= 0) {
        exit (0);
    }
    vector <int> a; int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back (temp);
    }

    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                count++;
            }
        }
    }

    cout << count;
    
    return 0;
}