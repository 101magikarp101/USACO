#include <bits/stdc++.h> // optional
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<
    pair<int,int>,
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> omset;

int main() {
    omset ms;
    ms.insert({10, 0});
    ms.insert({5, 0});
    ms.insert({7, 0});

    auto it = ms.find_by_order(1); // 0-based index
    if (it != ms.end()) {
        cout << "Element at index 1: (" << it->first << ", " << it->second << ")\n";
    }

    cout << "Number of elements less than {7,0}: " 
         << ms.order_of_key({7, 0}) << endl;

    return 0;
}
