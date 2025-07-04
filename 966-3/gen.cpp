#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = (ll)1e9;
const ll inf2 = (ll)2e5;

struct B {
	ll u, v, l1, l2;
};

vector<B> edges;

void add_edge(ll u, ll v, ll l1, ll l2)
{
	edges.push_back({ u, v, l1, l2 });
}

mt19937_64 rnd(1);

void hack()
{
	ll i, j;
	
	ll n;
	n = 50002;

	ll t0 = inf, t1 = inf - 2, t2 = inf - 1;

	for (i = 2; i <= n - 2; i++)
	{
		add_edge(n, i, i, inf2);
		add_edge(i, n - 1, inf2 - i * 2, inf2);
	}
	add_edge(n - 1, 1, inf2 - 1, inf2);

	shuffle(edges.begin(), edges.end(), rnd);

	cout << n << ' ' << edges.size() << '\n';
	cout << t0 << ' ' << t1 << ' ' << t2 << '\n';
	for (B& x : edges)
		cout << x.u << ' ' << x.v << ' ' << x.l1 << ' ' << x.l2 << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll t = 1;
	cout << t << '\n';
	while (t--)
		hack();
}