#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ordered_set of PBDS, a 'supercharged' version of set, refer to GfG site
template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ordered_set<pair<int,int>> window;

    // first window
    for (int i = 0; i < k; i++) window.insert({a[i], i});
    cout << window.find_by_order((k-1)/2)->first;

    // slide window
    for (int i = k; i < n; i++) {
        window.insert({a[i], i});
        window.erase({a[i-k], i-k});
        cout << " " << window.find_by_order((k-1)/2)->first;
    }
    cout << "\n";
}