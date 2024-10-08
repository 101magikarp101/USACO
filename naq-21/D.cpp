#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
#define mset multiset
struct pii {
    int x, y;
    bool operator<(const pii &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pii &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pii &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pii &a) const { return x != a.x || y != a.y; }
    pii operator+(const pii &a) const { return {x+a.x, y+a.y}; }
    pii operator-(const pii &a) const { return {x-a.x, y-a.y}; }
    pii operator*(const int &a) const { return {x*a, y*a}; }
    pii operator/(const int &a) const { return {x/a, y/a}; }
};
struct pll {
    ll x, y;
    bool operator<(const pll &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pll &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pll &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pll &a) const { return x != a.x || y != a.y; }
    pll operator+(const pll &a) const { return {x+a.x, y+a.y}; }
    pll operator-(const pll &a) const { return {x-a.x, y-a.y}; }
    pll operator*(const ll &a) const { return {x*a, y*a}; }
    pll operator/(const ll &a) const { return {x/a, y/a}; }
};

int T, N;
int a[200005];
map<string,vt<int>> m;
vt<int> primes;
vt<int> mods = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103, 1000000123, 1000000181, 1000000207, 1000000223, 1000000241, 1000000271, 1000000289, 1000000297, 1000000321, 1000000349};

int ad(int a, int b, int M) {
    return (a+b)%M;
}

int sub(int a, int b, int M) {
    return (a-b+M)%M;
}

int mul(int a, int b, int M) {
    return (int)(((ll)a*b)%(ll)M);
}

int binpow(int a, int b, int M) {
    int res = 1;
    while (b) {
        if (b%2) res = mul(res, a, M);
        a = mul(a, a, M);
        b /= 2;
    }
    return res;
}

int inv(int a, int M) {
    return binpow(a, M-2, M);
}

int di(int a, int b, int M) {
    return mul(a, inv(b, M), M);
}

void init() {
    int i = 2;
    while (primes.size() < 105) {
        bool prime = true;
        for (int j = 2; j*j <= i; j++) {
            if (i%j == 0) {
                prime = false;
                break;
            }
        }
        if (prime) primes.pb(i);
        i++;
    }
}

vt<string> split(string s, string delim) {
    vt<string> res;
    int start = 0;
    int end = s.find(delim);
    while (end != string::npos) {
        res.pb(s.substr(start, end-start));
        start = end+delim.size();
        end = s.find(delim, start);
    }
    res.pb(s.substr(start, end-start));
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    cout << sz(mods) << endl;
    cin >> N;
    string susomega;
    getline(cin, susomega);
    int cur = 0;
    for (int i = 0; i < N; i++) {
        // cout << "map" << endl;
        // for (auto x : m) {
        //     cout << x.first << " ";
        //     for (int i = 0; i < sz(mods); i++) {
        //         cout << x.second[i] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        string line;
        getline(cin, line);
        // cout << line << endl;
        vt<string> sides = split(line, " = ");
        vt<string> lhs = split(sides[0], " ");
        vt<string> rhs = split(sides[1], " ");
        map<string,int> lm, rm;
        for (int i = 0; i < sz(lhs); i++) {
            if (lhs[i] == "*") {
                i++;
                if (lhs[i] != "1") lm[lhs[i]]++;
            } else if (lhs[i] == "/") {
                i++;
                if (lhs[i] != "1") rm[lhs[i]]++;
            } else {
                if (lhs[i] != "1") lm[lhs[i]]++;
            }
        }
        for (int i = 0; i < sz(rhs); i++) {
            if (rhs[i] == "*") {
                i++;
                if (rhs[i] != "1") rm[rhs[i]]++;
            } else if (rhs[i] == "/") {
                i++;
                if (rhs[i] != "1") lm[rhs[i]]++;
            } else {
                if (rhs[i] != "1") rm[rhs[i]]++;
            }
        }
        vt<string> rem;
        for (auto x : lm) {
            string s = x.first;
            int d = min(lm[s], rm[s]);
            lm[s] -= d;
            rm[s] -= d;
            if (rm[s] == 0) {
                rm.erase(s);
            }
            if (lm[s] == 0) {
                rem.pb(s);
            }
        }
        for (string s : rem) {
            lm.erase(s);
        }
        int tot = 0;
        for (auto x : lm) {
            if (m.count(x.first)) {
                tot++;
            }
        }
        for (auto x : rm) {
            if (m.count(x.first)) {
                tot++;
            }
        }
        if (tot == sz(lm)+sz(rm)) {
            vt<int> val(sz(mods), 1);
            for (auto x : lm) {
                for (int i = 0; i < sz(mods); i++) {
                    val[i] = mul(val[i], binpow(m[x.first][i], x.second, mods[i]), mods[i]);
                }
            }
            for (auto x : rm) {
                for (int i = 0; i < sz(mods); i++) {
                    val[i] = di(val[i], binpow(m[x.first][i], x.second, mods[i]), mods[i]);
                }
            }
            for (int i = 0; i < sz(val); i++) {
                if (val[i] != 1) {
                    cout << "invalid" << endl;
                    return 0;
                }
            }
        } else {
            for (auto e : lm) {
                if (m.count(e.first)) continue;
                if (tot == sz(lm)+sz(rm)) break;
                if (tot+1 == sz(lm)+sz(rm)) {
                    vt<int> val(sz(mods), 1);
                    for (auto x : lm) {
                        if (e.first != x.first) {
                            for (int i = 0; i < sz(mods); i++) {
                                val[i] = di(val[i], binpow(m[x.first][i], x.second, mods[i]), mods[i]);
                            }
                        }
                    }
                    for (auto x : rm) {
                        for (int i = 0; i < sz(mods); i++) {
                            // cout << x.first << " " << x.second << endl;
                            val[i] = mul(val[i], binpow(m[x.first][i], x.second, mods[i]), mods[i]);
                        }
                    }
                    bool allone = 1;
                    for (int i = 0; i < sz(val); i++) {
                        if (val[i] != 1) {
                            allone = 0;
                            break;
                        }
                    }
                    if (allone) {
                        cout << "invalid" << endl;
                        return 0;
                    }
                    m[e.first] = val;
                    tot++;
                } else {
                    vt<int> val(sz(mods), primes[cur++]);
                    // cout << e.first << " " << val[0] << endl;
                    m[e.first] = val;
                    tot++;
                }
            }
            for (auto e : rm) {
                if (m.count(e.first)) continue;
                if (tot == sz(lm)+sz(rm)) break;
                if (tot+1 == sz(lm)+sz(rm)) {
                    vt<int> val(sz(mods), 1);
                    for (auto x : lm) {
                        for (int i = 0; i < sz(mods); i++) {
                            val[i] = mul(val[i], binpow(m[x.first][i], x.second, mods[i]), mods[i]);
                        }
                    }
                    for (auto x : rm) {
                        if (e.first != x.first) {
                            for (int i = 0; i < sz(mods); i++) {
                                // cout << x.first << " " << x.second << endl;
                                val[i] = di(val[i], binpow(m[x.first][i], x.second, mods[i]), mods[i]);
                            }
                        }
                    }
                    bool allone = 1;
                    for (int i = 0; i < sz(val); i++) {
                        if (val[i] != 1) {
                            allone = 0;
                            break;
                        }
                    }
                    if (allone) {
                        cout << "invalid" << endl;
                        return 0;
                    }
                    m[e.first] = val;
                    tot++;
                } else {
                    vt<int> val(sz(mods), primes[cur++]);
                    // cout << e.first << " " << val[0] << endl;
                    m[e.first] = val;
                    tot++;
                }
            }
        }
    }
    cout << "valid" << endl;
    return 0;
}