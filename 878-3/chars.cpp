#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <string>

using namespace std;

int T;
int t, q;
int N;
int falses;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        bool same[200001];
        string s[2];
        cin >> s[0] >> s[1];
        N = s[0].length();
        cin >> t >> q;
        falses = 0;
        queue<pair<int, int>> que;
        for (int j = 0; j < N; j++) {
            if (s[0][j] != s[1][j]) {
                falses++;
            }
            same[j] = s[0][j] == s[1][j];
        }
        for (int j = 0; j < q; j++) {
            int temp;
            cin >> temp;
            if (!que.empty() && que.front().first == j) {
                int pos = que.front().second;
                // cout << "pos: " << pos << endl;
                que.pop();
                if (s[0][pos] != s[1][pos]) {
                    falses++;
                }
                same[pos] = s[0][pos] == s[1][pos];
            }
            if (temp == 1) {
                int pos;
                cin >> pos;
                que.push(make_pair(j+t, pos-1));
                if (!same[pos-1]) {
                    falses--;
                }
            } else if (temp == 2) {
                int id1, pos1, id2, pos2;
                cin >> id1 >> pos1 >> id2 >> pos2;
                char temp = s[id1-1][pos1-1];
                s[id1-1][pos1-1] = s[id2-1][pos2-1];
                s[id2-1][pos2-1] = temp;
                if (s[0][pos1-1] == s[1][pos1-1]) {
                    if (!same[pos1-1]) {
                        falses--;
                    }
                    same[pos1-1] = true;
                } else {
                    if (same[pos1-1]) {
                        falses++;
                    }
                    same[pos1-1] = false;
                }
                if (s[0][pos2-1] == s[1][pos2-1]) {
                    if (!same[pos2-1]) {
                        falses--;
                    }
                    same[pos2-1] = true;
                } else {
                    if (same[pos2-1]) {
                        falses++;
                    }
                    same[pos2-1] = false;
                }
                // cout << "s1: " << s[0] << " s2: " << s[1] << endl;
            } else if (temp == 3) {
                if (falses == 0) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
            // cout << "false: " << falses << " j: " << j << " que: " << que.front().first << " " << que.front().second << endl;
        }
    }
}