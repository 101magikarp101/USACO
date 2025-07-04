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
    bool val;
    node* c[2];
};

int T, N, K;
int arr[200001];
map<int, int> m;
node* root;

//add to trie (number, level)
void add(int n) {
    node* curr = root;
    for (int i = K-1; i >= 0; i--) {
        int b = (n >> i) & 1;
        if (curr->c[b] == NULL) {
            curr->c[b] = new node();
        }
        curr = curr->c[b];
    }
    curr->val = true;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        root = new node();
        m.clear();
        memset(arr, 0, sizeof(arr));
        bool flag = false;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            if (m.find(arr[i]) != m.end() && !flag) {
                cout << m[arr[i]] << " " << i << " ";
                int res = 0;
                for (int j = 0; j < K; j++) {
                    int b = (arr[i] >> j) & 1;
                    if (b == 0) {
                        res += 1 << j;
                    }
                }
                cout << res << endl;
                flag = true;
            }
            m[arr[i]] = i;
            add(arr[i]);
        }
        if (flag) {
            continue;
        }
        int ans = -1;
        int num = 0;
        int index = -1;
        int res = 0;
        for (int i = 1; i <= N; i++) {
            node* curr = root;
            int lastfork = -1;
            int temp = 0;
            int n = 0;
            int x = 0;
            for (int j = K-1; j >= 0; j--) {
                int b = (arr[i] >> j) & 1;
                if (curr->c[1-b] != NULL) {
                    lastfork = j;
                }
                curr = curr->c[b];
            }
            curr = root;
            for (int j = K-1; j >= 0; j--) {
                int b = (arr[i] >> j) & 1;
                if (j == lastfork) {
                    curr = curr->c[1-b];
                    n += (1-b) << j;
                } else {
                    if (curr->c[b] != NULL) {
                        curr = curr->c[b];
                        temp += 1 << j;
                        n += b << j;
                        x += (1-b) << j;
                    } else {
                        curr = curr->c[1-b];
                        n += (1-b) << j;
                    }
                }
            }
            // cout << "temp: " << temp << " n: " << n << " x: " << x << endl;
            if (temp > ans) {
                ans = temp;
                num = n;
                index = i;
                res = x;
            }
        }
        cout << m[num] << " " << index << " " << res << endl;
    }
}