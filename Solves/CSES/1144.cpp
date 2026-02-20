#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

// Defining the Ordered Set
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> 
        ordered_set;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    vector<int> salaries(n + 1);
    ordered_set st;

    for (int i = 1; i <= n; i++) {
        cin >> salaries[i];
        st.insert({salaries[i], i});
    }

    while (q--) {
        char type; cin >> type;
        if (type == '!') {
            int k, x; cin >> k >> x;
            st.erase({salaries[k], k}); // Remove old
            salaries[k] = x;
            st.insert({salaries[k], k}); // Insert new
        } else {
            int a, b; cin >> a >> b;
            // Number of elements <= b , minus number of elements < a
            int ans = st.order_of_key({b, 1e9}) - st.order_of_key({a, -1});
            cout << ans << "\n";
        }
    }
}