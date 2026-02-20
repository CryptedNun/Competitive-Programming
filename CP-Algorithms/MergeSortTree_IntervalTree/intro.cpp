// ? Given an array a, answer how many elements are <= x in [L, R].
// ? You will have Q many queries, with `L R x` given, answer for each query.

// * The time complexity for each query is O(lg^2 n), but can be optimized to O(lg n) using `Fractional Cascading`
// * 

#include <bits/stdc++.h>
using namespace std;

class MergeSortTree {
    int n;
    vector<int> arr;
    vector<vector<int>> tree;

    // ? EXTRA VARS
    int l, r, x;

    // Merge `node`'s `left_child` and `right_child` arrays into `node` array
    void merger(int node) {
        int left_idx = 2 * node;
        int right_idx = 2 * node + 1;

        tree[node].resize(tree[left_idx].size() + tree[right_idx].size());

        merge(tree[left_idx].begin(), tree[left_idx].end(),
                tree[right_idx].begin(), tree[right_idx].end(),
                tree[node].begin());
    }

    void build(int node, int start, int end) {
        if(start == end) {
            tree[node]
            .push_back(arr[start]);
            return;
        }

        int mid = start + (end-start)/2;
        build(2*node, start, mid);
        build(2*node + 1, mid + 1, end);

        merger(node);
    }

    int query_rec(int node, int start, int end) {
        if(start >= l && end <= r) {
            // ! Find number of elem <= x.
            // ? upper_bound() = returns iterator to smallest elem > x.
            auto it = upper_bound(tree[node].begin(), tree[node].end(), x);

            return (int)(it - tree[node].begin());
        }

        int mid = start + (end-start)/2;
        int ans = 0;
        if(l <= mid) ans += query_rec(2 * node, start, mid);
        if(r > mid) ans += query_rec(2 * node + 1, mid + 1, end);

        return ans;
    }

public:
    MergeSortTree(const vector<int>& arr) {
        n = arr.size();
        this->arr.resize(n);
        this->arr = arr;
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    int query(int l, int r, int x) {
        this->l = l;
        this->r = r;
        this->x = x;

        return query_rec(1, 0, n - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;

    // 1. Initialize Random Engine (Mersenne Twister)
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    // Define ranges for random values and indices
    uniform_int_distribution<int> val_dist(1, 1000000000); // Values up to 10^9
    uniform_int_distribution<int> idx_dist(0, n - 1);

    // 2. Generate Random Array
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = val_dist(rng);

    // 3. Measure Build Time
    auto build_start = chrono::high_resolution_clock::now();
    MergeSortTree mst(a);
    auto build_end = chrono::high_resolution_clock::now();
    
    auto build_duration = chrono::duration_cast<chrono::milliseconds>(build_end - build_start);
    cout << "Standard MST built in: " << build_duration.count() << " ms\n\n";

    // 4. Generate Random Queries and Measure Time
    long long total_ns = 0;

    for (int i = 1; i <= q; i++) {
        // Generate random l and r such that 0 <= l <= r < n
        int u = idx_dist(rng);
        int v = idx_dist(rng);
        int l = min(u, v);
        int r = max(u, v);
        
        // Generate random x
        int x = val_dist(rng);

        // --- Time Measurement Start ---
        auto q_start = chrono::high_resolution_clock::now();
        int result = mst.query(l, r, x);
        auto q_end = chrono::high_resolution_clock::now();
        // --- Time Measurement End ---

        auto duration = chrono::duration_cast<chrono::nanoseconds>(q_end - q_start);
        total_ns += duration.count();

        // Print sample queries to avoid flooding the console
        if (q <= 15 || i % (q / 10) == 0) {
            cout << "Query " << i << ": [L=" << l << ", R=" << r << ", x=" << x << "]"
                 << " | Result: " << result << " | Time: " << duration.count() << " ns" << endl;
        }
    }

    cout << "\nTotal Query Time: " << total_ns / 1000000.0 << " ms" << endl;
    cout << "Average Time per Standard Query: " << total_ns / q << " ns" << endl;

    return 0;
}