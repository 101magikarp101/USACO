#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

using namespace std;

struct node {
    vector<node*> prev = {};
    node *next = nullptr;
    int index;
};


int main() {
    int N;
    cin >> N;
    bool stopped[1000];
    int furthest[1000]; //furthest position that each cow reached
    int culprit[1000];
    for (int i = 0; i < N; i++) {
        stopped[i] = false;
        furthest[i] = -1;
        culprit[i] = 0;
    }
    node *nodes[1000];
    vector<tuple<int, int, int>> e; // x, y, index
    vector<tuple<int, int, int>> n; // x, y, index
    for (int i = 0; i < N; i++) {
        char dir;
        int x, y;
        cin >> dir >> x >> y;
        if (dir == 'E') {
            e.push_back(make_tuple(x, y, i));
        } else {
            n.push_back(make_tuple(x, y, i));
        }
        nodes[i] = new node;
        nodes[i]->index = i;
    }
    // cout << "e: " << endl;
    // for (int i = 0; i < e.size(); i++) {
    //     cout << get<0>(e[i]) << " " << get<1>(e[i]) << " " << get<2>(e[i]) << endl;
    // }
    // cout << endl;
    // cout << "n: " << endl;
    // for (int i = 0; i < n.size(); i++) {
    //     cout << get<0>(n[i]) << " " << get<1>(n[i]) << " " << get<2>(n[i]) << endl;
    // }
    // cout << endl;
    vector<tuple<int, int, int, int>> events; // time, winner cow, loser cow, total (x+y)
    for (int i = 0; i < e.size(); i++) {
        for (int j = 0; j < n.size(); j++) {
            if (get<0>(e[i]) <= get<0>(n[j]) && get<1>(e[i]) >= get<1>(n[j])) {
                int _max = max(get<0>(n[j])-get<0>(e[i]), get<1>(e[i])-get<1>(n[j]));
                if (get<0>(n[j])-get<0>(e[i]) == get<1>(e[i])-get<1>(n[j])) {
                    continue;
                } else if (_max == get<0>(n[j])-get<0>(e[i])) {
                    events.push_back(make_tuple(_max, get<2>(n[j]), get<2>(e[i]), get<0>(n[j])+get<1>(e[i])));
                } else {
                    events.push_back(make_tuple(_max, get<2>(e[i]), get<2>(n[j]), get<0>(n[j])+get<1>(e[i])));
                }
            }
        }
    }
    sort(events.begin(), events.end(), [](tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
        return get<0>(a) < get<0>(b);
    });
    
    for (int i = 0; i < N; i++) {
        stopped[i] = false;
    }
    for (int i = 0; i < events.size(); i++) {
        if (!stopped[get<2>(events[i])]) {
            if (!stopped[get<1>(events[i])]) {
                nodes[get<2>(events[i])]->next = nodes[get<1>(events[i])];
                nodes[get<1>(events[i])]->prev.push_back(nodes[get<2>(events[i])]);
                stopped[get<2>(events[i])] = true;
                furthest[get<2>(events[i])] = get<3>(events[i]);
            } else if (furthest[get<1>(events[i])] != -1 && furthest[get<1>(events[i])] >= get<3>(events[i])) {
                nodes[get<2>(events[i])]->next = nodes[get<1>(events[i])];
                nodes[get<1>(events[i])]->prev.push_back(nodes[get<2>(events[i])]);
                stopped[get<2>(events[i])] = true;
                furthest[get<2>(events[i])] = get<3>(events[i]);
            }
        }
        // cout << "event: " << get<0>(events[i]) << " " << get<1>(events[i]) << " " << get<2>(events[i]) << " " << get<3>(events[i]) << endl;
        // cout << "stopped: " << endl;
        // for (int i = 0; i < N; i++) {
        //     cout << stopped[i] << endl;
        // }
        // cout << endl;
        // cout << "furthest: " << endl;
        // for (int i = 0; i < N; i++) {
        //     cout << furthest[i] << endl;
        // }
        // cout << endl;
        // cout << "nodes: " << endl;
        // for (int i = 0; i < N; i++) {
        //     cout << nodes[i]->index << " " << (nodes[i]->next != nullptr ? nodes[i]->next->index : -1) << " [";
        //     for (int j = 0; j < nodes[i]->prev.size(); j++) {
        //         cout << nodes[i]->prev[j]->index << " ";
        //     }
        //     cout << "]" << endl;
        // }
        // cout << endl;
    }
    // cout << "events: " << endl;
    // for (int i = 0; i < events.size(); i++) {
    //     cout << get<0>(events[i]) << " " << get<1>(events[i]) << " " << get<2>(events[i]) << endl;
    // }
    // cout << endl;
    // cout << "furthest: " << endl;
    // for (int i = 0; i < N; i++) {
    //     cout << furthest[i] << endl;
    // }
    // cout << endl;
    // cout << "nodes: " << endl;
    // for (int i = 0; i < N; i++) {
    //     cout << nodes[i]->index << " " << (nodes[i]->next != nullptr ? nodes[i]->next->index : -1) << " [";
    //     for (int j = 0; j < nodes[i]->prev.size(); j++) {
    //         cout << nodes[i]->prev[j]->index << " ";
    //     }
    //     cout << "]" << endl;
    // }
    // cout << endl;
    for (int i = 0; i < N; i++) {
        node currNode = *nodes[i];
        while (currNode.next != nullptr) {
            currNode = *currNode.next;
            culprit[currNode.index]++;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << culprit[i] << endl;
    }
}