#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vt vector
#define endl '\n'
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define sz(s) (int)s.size()
#define all(x) begin(x), end(x)
typedef pair<int,int> pii;
typedef vector<int> vi;

struct SuffixArray {
    vi sa, lcp;
    SuffixArray(string& s, int lim = 256) {
        int n = sz(s) + 1, k = 0, a, b;
        vi x(all(s) + 1), y(n), ws(max(n, lim)), rank(n);
        sa = lcp = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            rep(i, 0, n) if (sa[i] >= j) y[p++]  = sa[i] - j;
            fill(all(ws), 0);
            rep(i, 0, n) ws[x[i]]++;
            rep(i, 1, lim) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            rep(i, 1, n) a = sa[i - 1], b = sa[i], x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        rep(i, 1, n) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k && k--, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; k++);
    }
};

template<class T>
struct RMQ {
    vector<vector<int>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j, 0, sz(jmp[k])) {
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
            }
        }
    }
    T query(int a, int b) {
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    for (int i = 0; i < n; i++) {
        s += (a[i] < a[(i + 1) % n]) ? '0' : '1';
    }
    s += s;
    SuffixArray sa(s);
    RMQ st(sa.lcp);
    vector<int> pos;
    for (int i = 1; i <= 2 * n; i++) {
        if (sa.sa[i] < n) {
            pos.push_back(i);
        }
    }
    vector<int> ans(n);
    for (int j = 0; j < n; j++) {
        int mx = 0;
        if (j) {
            mx = max(mx, st.query(pos[j - 1] + 1, pos[j] + 1));
        }
        if (j < n - 1) {
            mx = max(mx, st.query(pos[j] + 1, pos[j + 1] + 1));
        }
        ans[sa.sa[pos[j]]] = mx + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << (ans[i] > n ? -1 : ans[i]) << '\n';
    }
}