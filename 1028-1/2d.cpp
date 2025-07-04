#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, n, string_num;
  cin >> m >> n >> string_num;
  string input_strings[string_num + 1];
  input_string[0] = “”;
  for (int i = 1; i <= string_num; i++) cin >> input_strings[i];
  int ones[string_num + 1], zeros[string_num + 1];
  for (int i = 0; i <= string_num; i++) {
    // go through all strings, and update ones[i], zeros[i]
  }

  int dp[m + 1][n + 1];
  fill_n(dp[0], (m + 1) * (n + 1), 0);

  for (int max_index = 1; max_index <= n; max_index++) {
    for (int zero_capacity = m; zero_capacity >= zero_nums[max_index]; zero_capacity--) {
      for (int one_capacity = n; one_capacity >= one_nums[max_index]; one_capacity--) {
            dp[zero_capacity][one_capacity] = max(dp[zero_capacity][one_capacity], dp[zero_capacity - zeros[max_index]][one_capacity - ones[max_index]]+1);
       }
    }
  }

  cout << dp[m][n];
}

/*

for (id in group_ids) {
  for (capacity = W; capacity >= 0; capacity--) {
    for (int item : group_items[id]) {
      if (capacity >= weights[item]) {
        dp[capacity] = max(dp[capacity], dp[capacity - weights[item]] + values[item]);
      }
    }
  }
}


*/