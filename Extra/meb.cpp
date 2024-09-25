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
    ll val = 0;
    vector<node*> c = vector<node*>(2);
    node(ll v) {
        val = v;
    }
};

int N;
node* root;

ll search(ll n) {
    ll cnt = 0;
    node* curr = root;
    for (int i = 0; i < 32; i++) {
        if (curr->c[((n>>i)&1)]!=NULL) {
            cnt += (i+1)*(curr->c[((n>>i)&1)]->val);
        }
        if (curr->c[!((n>>i)&1)]!=NULL) {
            curr = curr->c[!((n>>i)&1)];
        } else {
            break;
        }
    }
    return cnt;
}

void add(ll n) {
    node* curr = root;
    for (int i = 0; i < 32; i++) {
        if (curr->c[(n>>i)&1]==NULL) {
            curr->c[(n>>i)&1] = new node(1);
        } else {
            curr->c[(n>>i)&1]->val++;
        }
        curr = curr->c[(n>>i)&1];
    }
}

int main() {
    cin >> N;
    ll ans = 0;
    ll curr = 0;
    root = new node(0);
    add(0);
    for (int i = 0; i < N; i++) {
        ll temp;
        cin >> temp;
        curr ^= temp;
        ans += search(curr);
        add(curr);
    }
    cout << ans << endl;
}