#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> events;
    map<int, int> m;
    vector<int> compression;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, b});
        m[a]++;
        m[b]--;
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        v.push_back(it->second);
        compression.push_back(it->first);
    }
    int total = 0;
    vector<int> prefix(v.size());
    vector<int> intervalSize(v.size());
    intervalSize[0] = compression[0] - 1;
    for (int i = 1; i < v.size(); i++) {
        intervalSize[i] = compression[i] - compression[i - 1];
    }
    prefix[0] = v[0];
    for (int i = 1; i < v.size(); i++) {
        prefix[i] = prefix[i - 1] + v[i];
        if (prefix[i-1] != 0) {
            total += intervalSize[i];
        }
    }
    
    vector<int> numOfOnes(v.size());
    numOfOnes[0] = 0;
    for (int i = 1; i < v.size(); i++) {
        numOfOnes[i] = numOfOnes[i - 1] + (prefix[i-1] == 1 ? 1 : 0) * intervalSize[i];
    }
    // cout << "prefix: ";
    // for (int i = 0; i < prefix.size(); i++) {
    //     cout << prefix[i] << " ";
    // }
    // cout << endl;
    // cout << "total: " << total << endl;
    // cout << "numOfOnes: ";
    // for (int i = 0; i < numOfOnes.size(); i++) {
    //     cout << numOfOnes[i] << " ";
    // }
    // cout << endl;
    int min = INT32_MAX;
    for (int i = 0; i < events.size(); i++) {
        int a = events[i].first;
        int b = events[i].second;
        int aIndex = lower_bound(compression.begin(), compression.end(), a) - compression.begin();
        int bIndex = lower_bound(compression.begin(), compression.end(), b) - compression.begin();
        int curr = 0;
        if (aIndex == 0) {
            curr = numOfOnes[bIndex];
        } else {
            curr = numOfOnes[bIndex] - numOfOnes[aIndex];
        }
        //cout << "a: " << a << " b: " << b << " aIndex: " << aIndex << " bIndex: " << bIndex << " curr: " << curr << endl;
        if (curr < min) {
            min = curr;
        }
    }
    cout << total - min << endl;
}