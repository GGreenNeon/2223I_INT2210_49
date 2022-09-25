#include <iostream>
#include <stack>
using namespace std;

#include <iostream>
#include <queue>
using namespace std;

void reverse_stack (stack <int>& s) {
    stack <int> stemp = s, snew;
    while (!stemp.empty()) {
        snew.push(stemp.top());
        stemp.pop();
    }
    s = snew;
}

void print_stack (stack <int> s) {
    stack <int> temp = s;
    while (!temp.empty ()) {
        cout << temp.top () << " ";
        temp.pop ();
    }
}

int main () {
    stack <int> test;
    int n, value;
    cin >> n;
    string command;

    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "push") {
            cin >> value;
            test.push (value);
        }
        if (command == "pop") {
            test.pop ();
        }
    }

    reverse_stack (test);
    print_stack (test);
}