#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    tuple<int, int, int> people[200000];
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        people[i] = {a, b, i};
    }
    sort(people, people + n);
    set<pair<int, int>> rooms; // end time, room number
    rooms.insert({0, 1});
    int allocations[200000];
    for (int i = 0; i < n; i++) {
        if (get<0>(people[i]) <= rooms.begin()->first) {
            rooms.insert({get<1>(people[i]), rooms.size() + 1});
            allocations[get<2>(people[i])] = rooms.size();
        } else {
            rooms.insert({get<1>(people[i]), rooms.begin()->second});
            allocations[get<2>(people[i])] = rooms.begin()->second;
            rooms.erase(rooms.begin());
        }
        // cout << "Allocated room " << allocations[i] << " to " << get<2>(people[i]) << " from " << get<0>(people[i]) << " to " << get<1>(people[i]) << endl;
        // for (auto it = rooms.begin(); it != rooms.end(); it++) {
        //     cout << it->first << " " << it->second << endl;
        // }
    }
    cout << rooms.size() << endl;
    for (int i = 0; i < n; i++) {
        cout << allocations[i] << " ";
    }
}