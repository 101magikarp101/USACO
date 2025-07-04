#include <bits/stdc++.h>
#include "testlib.h"
#define ll long long
#define vt vector
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(1, 20, "N");
    inf.readEoln();
    vt<ll> a(N+1);
    for (int i = 1; i <= N; i++) {
        a[i] = inf.readLong(-9LL, 9LL, "a_i");
        if (i < N) {
            inf.readSpace();
        } else {
            inf.readEoln();
        }
    }
    vt<vt<int>> adj(N+1);
    for (int i = 1; i < N; i++) {
        int u = inf.readInt(1, N, "u");
        inf.readSpace();
        int v = inf.readInt(1, N, "v");
        inf.readEoln();
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //check if tree is valid
    vt<bool> vis(N+1, false);
    function<void(int, int)> dfs = [&](int u, int p) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (v == p) continue;
            if (vis[v]) {
                quitf(_wa, "Graph is not a tree");
            }
            dfs(v, u);
        }
    };
    dfs(1, 0);
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            quitf(_wa, "Graph is not a tree");
        }
    }
    inf.readEof();
}