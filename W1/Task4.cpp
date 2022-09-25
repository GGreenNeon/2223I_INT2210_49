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

    sort (a.begin (), a.end ());

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

    return 0;
}