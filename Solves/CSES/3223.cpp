#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

typedef tree<
            pair<int, int>,
            null_type,
            less<pair<int, int>>,
            rb_tree_tag,
            tree_order_statistics_node_update>
ordered_set;
// find_by_order(), order_of_key()
// ? BEHAVES LIKE SET, DOESN'T CONTAIN DUPLICATES, SO USE {elem, idx} PAIR FOR UNIQUE ELEMENTS

long long countInversions(vector<int>& arr, int k) {
    ordered_set st;
    for(int i = 0; i < k; i++) st.insert({arr[i], i});

    long long inversions = 0;
    for(int i = 0; i < k; i++) {
        inversions += st.order_of_key({arr[i], -1});
        st.erase({arr[i], i});
        // -1, because I only care of the element, not idx. I want ONLY # of elems STRICTLY less than a[i]
    }

    return inversions;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> x(n);
    for(auto& e : x) cin >> e;

    ordered_set pos, neg;
    for(int i = 0; i < k; i++) {
        pos.insert({x[i], i}); // For exiting elem
        neg.insert({-x[i], i}); // For entering elem
    }

    long long curr_inversion_count;
    curr_inversion_count = countInversions(x, k);
    cout << curr_inversion_count << " ";

    for(int j = 1; j < n - k + 1; j++) {
        // exiting: j - 1, entering: j - 1 + k
        int exiting = x[j - 1], entering = x[j - 1 + k];

        curr_inversion_count -= pos.order_of_key({exiting, -1});
        pos.erase({exiting, j - 1});
        neg.erase({-exiting, j - 1});

        pos.insert({entering, j - 1 + k});
        neg.insert({-entering, j - 1 + k});
        curr_inversion_count += neg.order_of_key({-entering, -1});

        cout << curr_inversion_count << " ";
    }

    return 0;
}