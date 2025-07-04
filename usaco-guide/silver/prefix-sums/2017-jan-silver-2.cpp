#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int N;
    cin >> N;
    int H[100000], P[100000], S[100000];
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (i == 0) {
            if (c == 'H') {
                H[i] = 1;
                P[i] = 0;
                S[i] = 0;
            }
            else if (c == 'P') {
                H[i] = 0;
                P[i] = 1;
                S[i] = 0;
            }
            else {
                H[i] = 0;
                P[i] = 0;
                S[i] = 1;
            }
        }
        else {
            if (c == 'H') {
                H[i] = H[i - 1] + 1;
                P[i] = P[i - 1];
                S[i] = S[i - 1];
            }
            else if (c == 'P') {
                H[i] = H[i - 1];
                P[i] = P[i - 1] + 1;
                S[i] = S[i - 1];
            }
            else {
                H[i] = H[i - 1];
                P[i] = P[i - 1];
                S[i] = S[i - 1] + 1;
            }
        }            
    }
    int max = 0;
    for (int i = 0; i < N; i++) {
        int h = H[i];
        int p = P[i];
        int s = S[i];
        int h2 = H[N - 1] - H[i];
        int p2 = P[N - 1] - P[i];
        int s2 = S[N - 1] - S[i];
        int max2 = 0;
        //paper, hoof
        if (h + s2 > max2) {
            max2 = h + s2;
        }
        //paper, scissors
        if (s + h2 > max2) {
            max2 = s + h2;
        }
        //scissors, paper
        if (p + h2 > max2) {
            max2 = p + h2;
        }
        //scissors, hoof
        if (h + p2 > max2) {
            max2 = h + p2;
        }
        //hoof, scissors
        if (s + p2 > max2) {
            max2 = s + p2;
        }
        //hoof, paper
        if (p + s2 > max2) {
            max2 = p + s2;
        }
        if (max2 > max) {
            max = max2;
        }
    }
    if (H[N - 1] > max) {
        max = H[N - 1];
    }
    if (P[N - 1] > max) {
        max = P[N - 1];
    }
    if (S[N - 1] > max) {
        max = S[N - 1];
    }
    cout << max << endl;
}