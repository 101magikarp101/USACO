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

#define ll long long
#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

int main() {
    int c, n;
	cin >> c >> n;

	vector<int> teams(n);
	vector<int> min_edits(1 << c, INT32_MAX);

	for (int i = 0; i < n; i++) {
		string breeds;
		cin >> breeds;

		// convert teams to bitmasks
		for (int j = 0; j < c; j++) {
			if (breeds[j] == 'G') { teams[i] += 1 << (c - j - 1); }
		}

		min_edits[teams[i]] = 0;
	}

	for (int edit = 0; edit < c; edit++) {
		for (int mask = 0; mask < (1 << c); mask++) {
			// mask ^ (1 << edit) flips the edit-th bit of mask
			if (min_edits[mask] != INT32_MAX) {
				min_edits[mask ^ (1 << edit)] =
				    min(min_edits[mask ^ (1 << edit)], min_edits[mask] + 1);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		// teams[i] ^ ((1 << c) - 1) flips all the bits of teams[i]
		cout << c - min_edits[teams[i] ^ ((1 << c) - 1)] << endl;
	}
}