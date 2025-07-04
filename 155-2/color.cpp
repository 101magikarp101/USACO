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
#include <chrono>

#define ll long long
#define pii pair<int, int>

using namespace std;

struct node {
    int val;
    int col;
    vector<node*> c;
};

int N;
node* p[101];
vector<int> v[101];

int longestchain(node* n) {
    int ans = 0;
    if (n->c.size() == 0) {
        return 0;
    } 
    if (n->c.size() == 1) {
        return longestchain(n->c[0])+1;
    }
    if (n->c.size() >= 2) {
        for (int i = 0; i < n->c.size(); i++) {
            ans = max(ans, longestchain(n->c[i]));
        }
    }
    return ans;
}
void fill(node* n, int idx, int cols) {
    n->col = v[cols][idx];
    idx++;
    idx %= v[cols].size();
    for (int i = 0; i < n->c.size(); i++) {
        fill(n->c[i], idx+1, cols);
    }
}

int main() {
    v[1].push_back(1);
    v[2].push_back(1);
    v[2].push_back(2);
    for (int i = 3; i < 101; i++) {
        if (i%2 == 1) {
            for (int j = 1; j <= i/2; j++) {
                int k = j;
                for (int c = 1; c<=i; c++) {
                    v[i].push_back(k%i);
                    k+=j;
                }
            }
        } else {
            for (int j = 1; j <= i/2-1; j++) {
                int k = j;
                for (int c = 1; c<=i; c++) {
                    v[i].push_back(k%i);
                    k+=j;
                }
            }
        }
    }
    p[1] = new node;
    p[1]->val = 1;
    cin >> N;
    bool solo = true;
    for (int i = 2; i <= N; i++) {
        int temp;
        cin >> temp;
        if (temp != 1) {
            solo = false;
        }
        p[i] = new node;
        p[i]->val = i;
        p[temp]->c.push_back(p[i]);
    }
    int chain = longestchain(p[1]);
    int colors = 0;
    if (solo) {
        colors = 1;
    } else if (chain == 1) {
        colors = 2;
    } else {
        colors = 3;
        while (v[colors].size() < chain) {
            colors++;
        }
    }
    fill(p[1], 0, colors);
    cout << colors << endl;
    for (int i = 2; i <= N; i++) {
        cout << p[i]->col << " ";
    }
    cout << endl;
    flush(cout);
    while (true) {
        int res;
        cin >> res;
        if (res == 1 || res == -1) {
            break;
        }
        int tot = 0;
        int a[101];
        vector<pii> co;
        for (int i = 1; i <= colors; i++) {
            cin >> a[i];
            tot += a[i];
            co.push_back({a[i], i});
        }
        if (tot == 2) {
            for (int i = 0; i < v[colors].size()-1; i++) {
                if (v[colors][i] == co[0].second) {
                    cout << co[0].second << endl;
                    flush(cout);
                    break;
                } else if (v[colors][i] == co[1].second) {
                    cout << co[1].second << endl;
                    flush(cout);
                    break;
                }
            }
        } else {
            if (co[0].second == 1) {
                cout << co[0].second << endl;
                flush(cout);
            } else {
                cout << co[1].second << endl;
                flush(cout);
            }
        }
    }
    return 0;
}