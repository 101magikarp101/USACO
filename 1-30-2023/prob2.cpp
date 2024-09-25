//USACO Silver 2023 Jan Problem 2
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <chrono>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> grid(N+1, vector<int>(N+1));
    vector<vector<int>> costs(N+1, vector<int>(N+1));
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
        costs[i][N] = part2;
    }
    for (int i = 0; i < N; i++)
    {
        int cost;
        cin >> cost;
        grid[N][i] = cost;
        costs[N][i] = cost;
    }
    int total = 0;
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < N; i++)
    {
        if (grid[i][N-1] == 1)
        {
            q.push({i, N-1, grid[i][N]});
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (grid[N-1][i] == 0)
        {
            q.push({N-1, i, grid[N][i]});
        }
    }
    while (!q.empty())
    {
        auto tup = q.front();
        int r = get<0>(tup);
        int c = get<1>(tup);
        int cost = get<2>(tup);
        costs[r][c] = cost;
        q.pop();
        total += cost;
        if (c-1 >= 0 && grid[r][c-1] == 1)
        {
            q.push({r, c-1, cost});
        }
        if (r-1 >= 0 && grid[r-1][c] == 0)
        {
            q.push({r-1, c, cost});
        }
    }
    int Q;
    cin >> Q;
    cout << total << endl;
    queue<tuple<int, int>> q2;
    for (int i = 0; i < Q; i++)
    {
        int r, c;
        cin >> r >> c;
        // auto start = chrono::high_resolution_clock::now();
        r--;
        c--;
        grid[r][c] = 1 - grid[r][c];
        int visited = 0;
        int cost = grid[r][c] == 1 ? costs[r][c+1] : costs[r+1][c];
        q2.push({r, c});
        while (!q2.empty())
        {
            auto tup = q2.front();
            int r = get<0>(tup);
            int c = get<1>(tup);
            visited++;
            total -= costs[r][c];
            costs[r][c] = cost;
            q2.pop();
            if (c-1 >= 0 && grid[r][c-1] == 1)
            {
                q2.push({r, c-1});
            }
            if (r-1 >= 0 && grid[r-1][c] == 0)
            {
                q2.push({r-1, c});
            }
        }
        total += cost * visited;
        cout << total << endl;
        // auto end = chrono::high_resolution_clock::now();
        // auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        // cout << "time" << duration.count() << endl;
    }
}