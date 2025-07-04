#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int64> ns(t);
    int64 nmax = 0;
    for(int i = 0; i < t; i++){
        cin >> ns[i];
        nmax = max(nmax, ns[i]);
    }

    // 1) Precompute all triangular numbers <= nmax
    vector<int64> tri;
    tri.reserve((int)sqrt(2.0 * nmax) + 5);
    for(int64 k = 1; ; k++){
        int64 v = k*(k+1)/2;
        if(v > nmax) break;
        tri.push_back(v);
    }

    // Helper: test if x is triangular
    auto isTri = [&](int64 x){
        // check 1 + 8x is perfect square
        int64 D = 1 + 8*x;
        int64 s = (int64)floor(sqrt((long double)D));
        if(s*s != D) return false;
        // check that (-1 + s) is even
        return ((s - 1) & 1) == 0;
    };

    // Answer each query
    for(int i = 0; i < t; i++){
        int64 n = ns[i];

        // 1?
        if(isTri(n)){
            cout << 1 << "\n";
            continue;
        }

        // 2? two-pointer on tri[]
        bool two = false;
        int l = 0, r = int(tri.size()) - 1;
        while(l <= r){
            int64 s = tri[l] + tri[r];
            if(s == n){
                two = true;
                break;
            }
            if(s < n) 
                l++;
            else 
                r--;
        }
        if(two){
            cout << 2 << "\n";
        } else {
            // by Gauss’s theorem, at most 3 are ever needed
            cout << 3 << "\n";
        }
    }
    return 0;
}
