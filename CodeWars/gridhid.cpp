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
#include <unordered_map>
#include <deque>
#include <climits>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int M, N;
char grid[13][13];
vt<string> v;

int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {1,0,-1,1,-1,1,0,-1};

bool good(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < M;
}

bool check(int n) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j]==v[n][0]) {
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < v[n].size(); l++) {
                        int ni = i+dx[k]*l;
                        int nj = j+dy[k]*l;
                        if (!good(ni,nj)) {
                            break;
                        }
                        if (grid[ni][nj]!=v[n][l]) {
                            break;
                        }
                        if (l==v[n].size()-1) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main () {
    cin >> M >> N;
    while (true) {
        string s; cin >> s;
        if (s=="END") break;
        v.push_back(s);
    }
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            grid[i][j] = s[j];
        }
    }
    // cout << "grid: " << endl;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }
    vt<string> yes, no;
    for (int i = 0; i < v.size(); i++) {
        bool b = check(i);
        if (b) {
            yes.push_back(v[i]);
        } else {
            no.push_back(v[i]);
        }
    }
    sort(yes.begin(),yes.end());
    sort(no.begin(),no.end());
    cout << "FOUND: ";
    for (int i = 0; i < yes.size(); i++) {
        cout << yes[i];
        if (i!=yes.size()-1) {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "MISSING: ";
    for (int i = 0; i < no.size(); i++) {
        cout << no[i];
        if (i!=no.size()-1) {
            cout << ", ";
        }
    }
}