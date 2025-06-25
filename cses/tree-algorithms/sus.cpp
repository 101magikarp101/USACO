#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = (1LL<<60);

struct SegTree {
    int n;
    vector<ll> t;
    SegTree(int _n): n(_n), t(2*_n, -INF) {}
    // build from base array a[0..n-1]
    void build(const vector<ll>& a){
        for(int i = 0; i < n; i++) t[n+i] = a[i];
        for(int i = n-1; i > 0; --i)
            t[i] = max(t[i<<1], t[i<<1|1]);
    }
    // point update: a[p] = x
    void update(int p, ll x){
        p += n;
        t[p] = x;
        for(p >>= 1; p; p >>= 1)
            t[p] = max(t[p<<1], t[p<<1|1]);
    }
    // range max on [l..r] inclusive
    ll query(int l, int r){
        ll res = -INF;
        for(l += n, r += n+1; l < r; l >>= 1, r >>= 1){
            if(l&1)  res = max(res, t[l++]);
            if(r&1)  res = max(res, t[--r]);
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<ll> val(n+1);
    for(int i = 1; i <= n; i++) 
        cin >> val[i];

    vector<vector<int>> adj(n+1);
    for(int i = 0, u, v; i < n-1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // HLD arrays
    vector<int> parent(n+1), depth(n+1), sz(n+1), heavy(n+1,-1);
    // 1) dfs to compute parent, depth, sz, heavy child
    function<int(int,int)> dfs = [&](int u, int p){
        parent[u] = p;
        depth[u] = (p<0?0:depth[p]+1);
        sz[u] = 1;
        int maxSub = 0;
        for(int w: adj[u]) if(w!=p){
            int subsz = dfs(w,u);
            if(subsz > maxSub){
                maxSub = subsz;
                heavy[u] = w;
            }
            sz[u] += subsz;
        }
        return sz[u];
    };
    dfs(1,-1);

    // 2) decompose: assign head[u] and pos[u]
    vector<int> head(n+1), pos(n+1);
    int curPos = 0;
    function<void(int,int)> decomp = [&](int u, int h){
        head[u] = h;
        pos[u]  = curPos++;
        if(heavy[u] != -1)
            decomp(heavy[u], h);
        for(int w: adj[u]) if(w!=parent[u] && w!=heavy[u]){
            decomp(w, w);
        }
    };
    decomp(1,1);

    // 3) build segment tree on base array
    vector<ll> base(n);
    for(int u = 1; u <= n; u++){
        base[pos[u]] = val[u];
    }
    SegTree seg(n);
    seg.build(base);

    // function to query max on path u–v
    auto pathMax = [&](int u, int v){
        ll ans = -INF;
        while(head[u] != head[v]){
            if(depth[head[u]] > depth[head[v]]){
                ans = max(ans, seg.query(pos[head[u]], pos[u]));
                u   = parent[head[u]];
            } else {
                ans = max(ans, seg.query(pos[head[v]], pos[v]));
                v   = parent[head[v]];
            }
        }
        // now on same head
        int L = min(pos[u], pos[v]);
        int R = max(pos[u], pos[v]);
        ans = max(ans, seg.query(L, R));
        return ans;
    };

    // process queries
    while(q--){
        int t; 
        cin >> t;
        if(t == 1){
            int s; ll x;
            cin >> s >> x;
            seg.update(pos[s], x);
        } else {
            int a, b;
            cin >> a >> b;
            cout << pathMax(a, b) << " ";
        }
        cout << endl;
    }
    return 0;
}
