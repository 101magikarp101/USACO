#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int diffs[400005];
int widths[400005];
int vals[400005];
int prefixSums[400005];
pair<pair<int, int>, int> differences[100005];
pair<int, int> queries[100005];
vector<int> indices;

int getCompressedIndex(int x)
{
    return lower_bound(indices.begin(), indices.end(), x) - indices.begin();
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int l, r, n;
        cin >> l >> r >> n;
        indices.push_back(l);
        indices.push_back(r);
        differences[i] = {{l, r}, n};
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        indices.push_back(l);
        indices.push_back(r);
        queries[i] = {l, r};
    }
    sort(indices.begin(), indices.end());
    indices.erase(unique(indices.begin(), indices.end()), indices.end());
    for (int i = 0; i < n; i++)
    {
        int l = getCompressedIndex(differences[i].first.first);
        int r = getCompressedIndex(differences[i].first.second);
        int n = differences[i].second;
        diffs[l] += n;
        diffs[r] -= n;
    }
    cout << "indices: ";
    for (int i = 0; i < indices.size(); i++)
    {
        cout << indices[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < indices.size(); i++)
    {
        widths[i] = indices[i] - indices[i - 1];
    }
    cout << "widths: ";
    for (int i = 0; i < indices.size(); i++)
    {
        cout << widths[i] << " ";
    }
    cout << endl;
    cout << "diffs: ";
    for (int i = 0; i < indices.size(); i++)
    {
        cout << diffs[i] << " ";
    }
    cout << endl;
    vals[0] = diffs[0];
    for (int i = 1; i < indices.size(); i++)
    {
        vals[i] = vals[i - 1] + diffs[i];
    }
    cout << "vals: ";
    for (int i = 0; i < indices.size(); i++)
    {
        cout << vals[i] << " ";
    }
    cout << endl;
    prefixSums[0] = vals[0];
    for (int i = 1; i < indices.size(); i++)
    {
        prefixSums[i] = prefixSums[i - 1] + widths[i] * vals[i];
    }
    cout << "prefixSums: ";
    for (int i = 0; i < indices.size(); i++)
    {
        cout << prefixSums[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < q; i++)
    {
        int l = getCompressedIndex(queries[i].first);
        int r = getCompressedIndex(queries[i].second);
        cout << prefixSums[r] - prefixSums[l] << endl;
    }
}