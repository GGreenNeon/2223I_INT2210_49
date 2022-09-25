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
    for (int i = 1; i < n - 1; i++) {
        if (a[i-1] + a[i] + a[i+1] == 0) {
            count++;
        }
    }

    cout << count;
    
    return 0;
}