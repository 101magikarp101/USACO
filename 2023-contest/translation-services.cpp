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

using namespace std;

int N;
double a;

ll gcd(ll a, ll b) {
    if (a == 0) {
        return b;
    }
    return gcd(b%a, a);
}

pair<ll, ll> add(pair<ll, ll> a, pair<ll, ll> b) {
    // cout << a.first << "/" << a.second << " + " << b.first << "/" << b.second << endl;
    pair<ll, ll> c = {a.first*b.second+b.first*a.second, a.second*b.second};
    // cout << c.first << "/" << c.second << endl;
    ll g = gcd(c.first, c.second);
    // cout << g << endl;
    c.first /= g;
    c.second /= g;
    return c;
}

pair<ll, ll> inv(pair<ll, ll> a) {
    return {a.second, a.first};
}

vector<ll> cfrac(double x) {
    vector<ll> v;
    ll a = (ll)x;
    v.push_back(a);
    x -= a;
    for (int i = 0; i < 10; i++) {
        if (abs(x) < 1e-9) {
            break;
        }
        x = 1/x;
        a = (ll)x;
        if (a <= 0 || a > 1e5) {
            break;
        }
        v.push_back(a);
        x -= a;
    }
    return v;
}

double eval(vector<ll> v) {
    double sum = 0;
    for (int i = v.size()-1; i > 0; i--) {
        sum = 1.0/(sum+v[i]);
    }
    sum += v[0];
    return sum;
}

pair<ll, ll> hmm(vector<ll> v) {
    pair<ll, ll> sum = {1, 0};
    for (int i = v.size()-1; i >= 0; i--) {
        sum = add(inv(sum), {v[i], 1});
    }
    return sum;
}

bool check(double b) {
    // check if the first 3 decimal places of a and b are the same
    // cout << setprecision(10) << a << " " << b << endl;
    // cout << setprecision(10) << b-a << endl;
    return (int)(a*1000) == (int)(b*1000) || abs(b-a) < 1e-9;
}

int main(){
    //start timer
    auto start = chrono::high_resolution_clock::now();
    // freopen("in1.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin >> N;
    ll high = 0;
    for (int i = 0; i < N; i++) {
        ll m = 1e18, n = 1e18;
        cin >> a;
        vector<ll> v = cfrac(a);
        bool flag = false;
        vector<ll> v1;
        for (int j = 0; j < v.size(); j++) {
            if (j > 0) v1.push_back(v[j-1]);
            for (int k = (v[j]+1)/2; k <= v[j]; k++) {
                v1.push_back(k);
                // cout << "v1: ";
                // for (int l = 0; l < v1.size(); l++) {
                //     cout << v1[l] << " ";
                // }
                // cout << endl;
                // cout << eval(v1) << endl;
                if (check(eval(v1))) {
                    pair<ll, ll> res = hmm(v1);
                    // cout << res.first << "/" << res.second << endl;
                    if (res.second < n) {
                        m = res.first;
                        n = res.second;
                    }
                }
                v1.pop_back();
            }
        }
        cout << m << " " << n << endl;
        high = max(high, n);
    }
    //end timer
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
}