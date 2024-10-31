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

#define ll long long

using namespace std;

struct node {
    int val = 0;
    node* c[2] = {NULL, NULL};
};

int N, M, Q, t;
int W[13];
node* root;

void insert(int x) {
    node* cur = root;
    for (int i = N-1; i >= 0; i--) {
        int b = (x >> i) & 1;
        if (cur->c[b] == NULL) {
            cur->c[b] = new node();
        }
        cur = cur->c[b];
        if (i == 0) {
            cur->val++;
        }
    }
}

int solve(node* cur, int k, int i) {
    int b = (x >> i) & 1;
}

int main() {
    cin >> N >> M >> Q;
    node* root = new node();
    node* cur = root;
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        insert(x);
    }
    for (int i = 0; i < Q; i++) {
        int k;
        cin >> t >> k;
        node* cur = root;
        int ans = solve(cur, k, N-1);
    }
}