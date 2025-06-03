#include <bits/stdc++.h>
using namespace std;

int main() {

  int n, W;  // n is the number of items, W is the capacity of the knapsack.
  cin >> W >> n;

  int weights[n], values[n];
  for (int i = 0; i < n; i++) 
    cin >> weights[i] >> values[i];

  int dp[W + 1];
  fill_n(dp, W + 1, 0);

  for (int max_index = 0; max_index < n; max_index++) {
    for (int capacity = W; capacity >= weights[max_index]; capacity--) {
      dp[capacity] = max(dp[capacity],dp[capacity - weights[max_index]] + values[max_index]);
    }
  }

  cout << dp[W];
}

/*
dp[n+1] = {1e9};
dp[0] = 0;

for (auto c : coins) {
  for (int tot = c; tot <= n; tot++) {
    dp[tot] = min(dp[tot], dp[tot - c] + 1);
  }
}

*/