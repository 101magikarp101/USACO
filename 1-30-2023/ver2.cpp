#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <chrono>
using namespace std;

struct Node {
    int r;
    int c;
    int cost;
    int children = 1;
    Node *parent;
    Node *left;
    Node *right;
    Node(int r, int c, int cost) {
        this->r = r;
        this->c = c;
        this->cost = cost;
        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int main() {
    int N;
    cin >> N;
    vector<vector<int>> grid(N+1, vector<int>(N+1));
    vector<vector<Node*>> tree_refs(N+1, vector<Ndde*>(N+1));
    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;
        int part2;
        cin >> part2;
        for (int j = 0; j < N; j++)
        {
            if (line[j] == 'R')
            {
                grid[i][j] = 1;
            }
            else
            {
                grid[i][j] = 0;
            }
        }
        grid[i][N] = part2;
    }
    for (int i = 0; i < N; i++)
    {
        int cost;
        cin >> cost;
        grid[N][i] = cost;
    }
    int total = 0;
    vector<Node*> roots = {};
    for (int i = 0; i < N; i++)
    {
        if (grid[i][N-1] == 1)
        {
            Node *node = new Node(i, N-1, grid[i][N]);
            roots.push_back(node);
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (grid[N-1][i] == 0)
        {
            Node *node = new Node(N-1, i, grid[N][i]);
            roots.push_back(node);
        }
    }
    for (Node *root : roots) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            int r = node->r;
            int c = node->c;
            total += node->cost;
            //store a pointer to the node in the tree_refs array
            tree_refs[r][c] = node;
            cout << r << " " << c << " " << node->cost << endl;
            if (c - 1 >= 0 && grid[r][c-1] == 1) {
                Node *left = new Node(r, c - 1, node->cost);
                left->parent = node;
                node->left = left;
                node->children++;
                q.push(left);
            }
            if (r - 1 >= 0 && grid[r-1][c] == 0) {
                Node *right = new Node(r - 1, c, node->cost);
                right->parent = node;
                node->right = right;
                node->children++;
                q.push(right);
            }
        }
    }
    cout << total << endl;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        Node *node = tree_refs[r][c];
        grid[r][c] = 1 - grid[r][c];
        if (grid[r][c] == 1)
        {
            //add node to tree
            if (c+1 < N) {
                Node *parent = tree_refs[r][c+1];
            } else {
                node->cost = grid[r][N];
                roots.push_back(node);
            }
        }
        else
        {
            
        }
    }
}