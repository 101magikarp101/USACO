#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main()
{
    // freopen("diamond.in", "r", stdin);
    // freopen("diamond.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int rocks[50005];
    for (int i = 0; i < n; i++)
    {
        cin >> rocks[i];
    }
    sort(rocks, rocks + n);
    int l = 0;
    int r = 0;
    vector<pair<int, int>> intervals;
    int longest[50005];
    while (true)
    {
        if (r < n - 1 && rocks[r + 1] - rocks[l] <= k)
        {
            intervals.push_back({l, r});
            longest[l] = max(longest[l], r - l + 1);
            r++;
        }
        else if (r >= n - 1)
        {
            while (l <= r)
            {
                intervals.push_back({l, r});
                longest[l] = max(longest[l], r - l + 1);
                l++;
            }
            break;
        }
        else if (r < n - 1 && rocks[r + 1] - rocks[l] > k)
        {
            intervals.push_back({l, r});
            longest[l] = max(longest[l], r - l + 1);
            if (l == r)
            {
                l++;
                r++;
            }
            else
            {
                l++;
            }
        }
        cout << l << " " << r << endl;
        cout << "intervals: ";
        for (int i = 0; i < intervals.size(); i++)
        {
            cout << intervals[i].first << " " << intervals[i].second << " " << endl;
        }
    }
    cout << "longest: ";
    for (int i = 0; i < intervals.size(); i++)
    {
        cout << longest[i] << " ";
    }
    cout << endl;
    int max = 0;
    for (int i = 0; i < intervals.size(); i++)
    {
        int l = intervals[i].first;
        int r = intervals[i].second;
        int len = r - l + 1;
        if (len > max)
        {
            max = len;
        }
    }
}