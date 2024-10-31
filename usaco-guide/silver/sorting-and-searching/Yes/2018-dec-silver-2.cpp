#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

#define ll long long

using namespace std;

struct cmp
{
    bool operator()(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b)
    {
        return get<2>(a) < get<2>(b);
    }
};

int main()
{
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int N;
    cin >> N;
    map<ll, vector<pair<ll, ll>>> milk; // arrive -> wait, index
    for (int i = 0; i < N; i++)
    {
        ll a, b;
        cin >> a >> b;
        milk[a].push_back({b, i});
    }
    ll maxWait = 0;
    ll time = 0;
    set<tuple<ll, ll, ll>, cmp> queue; // arrive, wait, index
    tuple<ll, ll, ll> current = {0, 0, 0};
    while (true)
    {
        if (queue.empty() && milk.empty())
        {
            break;
        }
        if (queue.empty())
        {
            auto it = milk.begin();
            ll arrive = it->first;
            for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
            {
                queue.insert({arrive, it2->first, it2->second});
                //cout << "Pushed: " << arrive << " " << it2->first << " " << it2->second << endl;
            }
            milk.erase(it);
        }
        current = *queue.begin();
        queue.erase(queue.begin());
        time = max(time, get<0>(current));
        maxWait = max(maxWait, time - get<0>(current));
        time += get<1>(current);
        // cout << "Popped: " << get<0>(current) << " " << get<1>(current) << " " << get<2>(current) << endl;
        // cout << "Time: " << time << endl;
        // cout << "MaxWait: " << maxWait << endl;
        while (!milk.empty() && milk.begin()->first <= time)
        {
            auto it = milk.begin();
            ll arrive = it->first;
            for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
            {
                queue.insert({arrive, it2->first, it2->second});
                //cout << "Pushed: " << arrive << " " << it2->first << " " << it2->second << endl;
            }
            milk.erase(it);
        }
    }
    cout << maxWait << endl;
}