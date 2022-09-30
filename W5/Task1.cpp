#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <vector <char>> matrix;
    char temp;
    for (int i = 0; i < n; i++) {
        vector <char> matrix1d;
        for (int j = 0; j < n; j++) {
            temp = 'O';
            matrix1d.push_back (temp);
        }
        matrix.push_back (matrix1d);
    }
    int empty = n * n;

    int K;
    cin >> K;
    int result[K];
    int x, y;
    for (int step = 0; step < K; step++) {
        cin >> x >> y;
        for (int i = 0; i < n; i++) {
            if (matrix[x - 1][i] == 'O') {
                matrix[x - 1][i] = 'X';
                empty--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (matrix[i][y - 1] == 'O') {
                matrix[i][y - 1] = 'X';
                empty--;
            }
        }
        result[step] = empty;
    }

    for (int i = 0; i < K; i++) {
        cout << result[i] << " ";
    }
    return 0;
}