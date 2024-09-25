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

using namespace std;

struct Node {
    int val;
    vector<pair<Node*, int>> children; // node, index
    Node(int v) {
        val = v;
    }
};

int search(Node* node, int parent, int index, int depth) {
    // cout << node->val << " " << parent << " " << index << " " << depth << endl;
    int ans = depth;
    for (int i = 0; i < node->children.size(); i++) {
        if (node->children[i].first->val != parent) {
            bool flag = node->children[i].second < index;
            ans = max(search(node->children[i].first, node->val, node->children[i].second, depth + (flag ? 1 : 0)), ans);
        }
    }
    return ans;
}

int T, N;
Node* nodes[200001];

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int j = 1; j < N; j++) {
            int a, b;
            cin >> a >> b;
            if (nodes[a] == NULL) {
                nodes[a] = new Node(a);
            }
            if (nodes[b] == NULL) {
                nodes[b] = new Node(b);
            }
            nodes[a]->children.push_back(make_pair(nodes[b], j));
            nodes[b]->children.push_back(make_pair(nodes[a], j));
        }
        // for (int j = 1; j <= N; j++) {
        //     cout << nodes[j]->val << ": ";
        //     for (int k = 0; k < nodes[j]->children.size(); k++) {
        //         cout << nodes[j]->children[k].first->val << " " << nodes[j]->children[k].second << ", ";
        //     }
        //     cout << endl;
        // }
        Node* root = nodes[1];
        int ans = search(root, 1, 0, 1);
        cout << ans << endl;
        memset(nodes, NULL, sizeof(nodes));
    }
    return 0;
}