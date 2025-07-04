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

map<int, int> ma;

struct DSU {
	vector<int> e;
    map<int, set<int>> m;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
        if (m.find(y) != m.end()) {
            m[x].first = min(ma[m[x].first], ma[m[y].first]);
            m[x].second = max(ma[m[x].second], ma[m[y].second]);
            m.erase(y);
        } else {
            m[x] = {min(x, y), max(x, y)};
        }
		e[y] = x;
		return true;
	}
};

int N;

int main() {
    cin >> N;
    DSU d(N+1);
    int arr[1000001];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        ma[arr[i]] = i;
    }
    pair<int, int> edge[1000001];
    for (int i = 0; i < N-1; i++) {
        edge[i] = {arr[i], arr[i+1]};
        if (edge[i].first < edge[i].second) {
            swap(edge[i].first, edge[i].second);
        }
    }
    sort(edge, edge+N-1);
    int ans = 0;
    for (int i = 0; i < N-1; i++) {
        
    }
    cout << ans << endl;
}