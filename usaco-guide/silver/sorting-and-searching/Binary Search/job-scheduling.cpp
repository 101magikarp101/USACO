#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>

#define ll long long

using namespace std;

int N, D, M;
pair<int, int> arr[1000000];

bool check (int val) {
    //cout << "val: " << val << endl;
    int index = 1;
    for (int day = 1; day <= N; day++) {
        int max = index + val;
        for (int i = index; i < max && i <= M; i++) {
            //cout << "day: " << day << " index: " << index << " i: " << i << " arr[i].first: " << arr[i].first << " arr[i].second: " << arr[i].second << endl;
            if (arr[i].first > day) {
                break;
            } else if (arr[i].first + D < day) {
                return false;
            }
            index++;
        }

    }
    if (index >= M) {
        return true;
    } else {
        return false;
    }
}

void printAns (int val) {
    int index = 1;
    for (int day = 1; day <= N; day++) {
        for (int i = index; i < index + val && i <= M; i++) {
            cout << arr[i].second << " ";
        }
        index += val;
        cout << "0" << endl;
    }
}

int main() {
    cin >> N >> D >> M;
    for (int i = 1; i <= M; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr+1, arr + M+1, [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });
    // cout << "arr: " << endl;
    // for (int i = 1; i <= M; i++) {
    //     cout << arr[i].first << " " << arr[i].second << endl;
    // }
    int low = 1;
    int high = 1e7;
    while (low < high) {
        int mid = (low + high) / 2;
        if (check(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
    printAns(low);
}