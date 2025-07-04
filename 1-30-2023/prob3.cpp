//USACO Silver 2023 Jan Problem 3
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    string S = "";
    int count = 0;
    int index = 0;
    string dir = "R";
    while (count < 100) {
        if (A[index] % 2 == 0) {
            S += dir;
            A[index]--;
            if (index + 1 >= N || (index + 1 < N && A[index + 1] == 0)) {
                dir = "L";
            } else {
                index++;
            }
        } else {
            S += dir;
            A[index]--;
            if (index - 1 >= 0 && A[index - 1] == 1 && A[index] > 1) {
                dir = "R";
            } else if (index - 1 < 0) {
                dir = "R";
            } else {
                index--;
            }
        }
        if (A[0] == 0) {
            break;
        }
        // count++;
        // for (int i = 0; i < N; i++) {
        //     cout << A[i] << " ";
        // }
        // cout << endl;
        // cout << dir << " " << index << " " << S << endl;
    }
    cout << S << endl;
}