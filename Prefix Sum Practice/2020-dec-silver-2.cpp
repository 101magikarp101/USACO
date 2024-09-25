#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main () {
    int n;
    cin >> n;
    pair<long, long> cows[2500];
    long xarr[2500];
    long yarr[2500];
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
        xarr[i] = cows[i].first;
        yarr[i] = cows[i].second;
    }
    sort(xarr, xarr + n);
    sort(yarr, yarr + n);
    // cout << "xarr: ";
    // for (int i = 0; i < n; i++) {
    //     cout << xarr[i] << " ";
    // }
    // cout << endl;
    // cout << "yarr: ";
    // for (int i = 0; i < n; i++) {
    //     cout << yarr[i] << " ";
    // }
    // cout << endl;
    map<long, long> xmap;
    map<long, long> ymap;
    for (int i = 0; i < n; i++) {
        xmap[xarr[i]] = i;
        ymap[yarr[i]] = i;
    }
    long points[2500][2500];
    long prefix[2500][2500];
    for (int i = 0; i < n; i++) {
        points[ymap[cows[i].second]][xmap[cows[i].first]] = 1;
        cows[i].first = xmap[cows[i].first];
        cows[i].second = ymap[cows[i].second];
    }
    // for (int i = 0; i < n; i++) {
    //     cout << cows[i].first << " " << cows[i].second << endl;
    // }
    sort(cows, cows + n, [](pair<long, long> a, pair<long, long> b) {
        return a.first < b.first;
    });
    
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << points[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            prefix[i][j] = points[i][j];
            if (i > 0) {
                prefix[i][j] += prefix[i - 1][j];
            }
            if (j > 0) {
                prefix[i][j] += prefix[i][j - 1];
            }
            if (i > 0 && j > 0) {
                prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }
    }
    // cout << "prefix: " << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << prefix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    long long total = 1;
    for (int i = 0; i < n; i++) {
        long long x = cows[i].first;
        long long y = cows[i].second;
        for (int j = i; j >= 0; j--) {
            long long x2 = cows[j].first;
            long long y2 = cows[j].second;
            //bottom right
            long long x3 = x;
            long long y3 = min(y-1, y2-1);
            //top left
            long long x4 = x2;
            long long y4 = 0;
            //bottom right
            long long x5 = x;
            long long y5 = n - 1;
            //top left
            long long x6 = x2;
            long long y6 = max(y+1, y2+1);
            long long sum1 = 0;
            long long sum2 = 0;
            // cout << "x: " << x << " y: " << y << endl;
            // cout << "x2: " << x2 << " y2: " << y2 << endl;
            // cout << "x3: " << x3 << " y3: " << y3 << endl;
            // cout << "x4: " << x4 << " y4: " << y4 << endl;
            // cout << "x5: " << x5 << " y5: " << y5 << endl;
            // cout << "x6: " << x6 << " y6: " << y6 << endl;
            if (x3 >= 0 && y3 >= 0) {
                sum1 = prefix[y3][x3];
                if (x4 > 0) {
                    sum1 -= prefix[y3][x4 - 1];
                }
                if (y4 > 0) {
                    sum1 -= prefix[y4 - 1][x3];
                }
                if (x4 > 0 && y4 > 0) {
                    sum1 += prefix[y4 - 1][x4 - 1];
                }
            }
            if (x5 < n && y5 < n) {
                sum2 = prefix[y5][x5];
                if (x6 > 0) {
                    sum2 -= prefix[y5][x6 - 1];
                }
                if (y6 > 0) {
                    sum2 -= prefix[y6 - 1][x5];
                }
                if (x6 > 0 && y6 > 0) {
                    sum2 += prefix[y6 - 1][x6 - 1];
                }
            }
            //cout << "i: " << i << " j: " << j << " sum1: " << sum1 << " sum2: " << sum2 << endl;
            total += (sum1 + 1) * (sum2 + 1);
        }
    }
    cout << total << endl;
}