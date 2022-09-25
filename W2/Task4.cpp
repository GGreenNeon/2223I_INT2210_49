#include <iostream>
#include <queue>
using namespace std;

void print_queue (queue <int> q) {
    queue <int> temp = q;
    while (!temp.empty ()) {
        cout << temp.front () << " ";
        temp.pop ();
    }
}

int main () {
    queue <int> test;
    int n, value;
    cin >> n;
    string command;

    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "enqueue") {
            cin >> value;
            test.push (value);
        }
        if (command == "dequeue") {
            test.pop ();
        }
    }

    print_queue (test);
}