#include <iostream>
#include <vector>
using namespace std;

bool findElementInVector (vector <int> arr, int value) {
    int n = arr.size ();
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int maximumSubarraySum (vector <int> arr) {
    int n = arr.size ();
    int maxSum = INT_MIN;

    for (int i = 0; i <= n - 1; i++) {
        int currSum = 0;
        for (int j = i; j <= n - 1; j++) {
            currSum += arr[j];
            if (currSum > maxSum) {
            maxSum = currSum;
            }
        }
    }
    return maxSum;
}

void outputSumVector (vector <int> arr) {
    int n = arr.size (), sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    cout << sum;
}

int main () {
    int n;
    cin >> n;
    vector <int> array;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        array.push_back (temp);
    }

    vector <int> uniqueMaximumSum;
    vector <int> temparray;
    int value;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            temparray.push_back (array[j]);
            value = maximumSubarraySum (temparray);
            if (uniqueMaximumSum.size () == 0 || !findElementInVector (uniqueMaximumSum, value)) {
                uniqueMaximumSum.push_back (value);
            }
        }
        temparray.clear ();
    }

    outputSumVector (uniqueMaximumSum);

    return 0;
}