// ? Given an array a, answer how many elements are <= x in [L, R].
// ? You will have Q many queries, with `L R x` given, answer for each query.
// ? [NOTE] : This implementation can be further improvised to avoid cache misses,
// ?          by clearing all nodes' values array except for the root node, at the end of the constructor function.
// ?          since queries don't require those internal arrays except the root array.
// ? {Check Solves/CSES/1734.cpp for its implementation}

#include <bits/stdc++.h>
using namespace std;

class MergeSortTree {
    struct Node {
        vector<int> values;
        vector<int> l_ptr;
        vector<int> r_ptr;
    };
    int n;
    vector<int> arr;
    vector<Node> tree;

    int l, r;

    void merger(int node) {
        int left_idx = 2 * node;
        int right_idx = 2 * node + 1;

        auto& v = tree[node].values;
        auto& lv = tree[left_idx].values;
        auto& rv = tree[right_idx].values;

        v.resize(lv.size() + rv.size());

        merge(lv.begin(), lv.end(), rv.begin(), rv.end(), v.begin());
    }

    void populate_l_r(int node) {
        int left_idx = 2 * node;
        int right_idx = 2 * node + 1;

        auto& v = tree[node].values;
        auto& lv = tree[left_idx].values;
        auto& rv = tree[right_idx].values;

        tree[node].l_ptr.resize(v.size() + 1);
        tree[node].r_ptr.resize(v.size() + 1);

        // ? tree[node].l_ptr[i] = the idx of the first(smallest) elem >= tree[node].values[i] in leftchild
        // ? tree[node].r_ptr[i] = the idx of the first(smallest) elem >= tree[node].values[i] in rightchild
        int l_idx = 0, r_idx = 0;
        for(int i = 0; i <= v.size(); i++) {
            int val = (i < v.size()) ? v[i] : INT_MAX;

            while(l_idx < lv.size() && lv[l_idx] < val) l_idx++;
            while(r_idx < rv.size() && rv[r_idx] < val) r_idx++;

            tree[node].l_ptr[i] = l_idx;
            tree[node].r_ptr[i] = r_idx;
        }
    }

    void build(int node, int start, int end) {
        if(start == end) {
            tree[node].values.push_back(arr[start]);
            return;
        }

        int mid = start + (end - start)/2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        merger(node);

        populate_l_r(node);
    }

    int query_rec(int node, int start, int end, int pos) {
        if(start >= l && end <= r) {
            return pos;
        }
        
        int mid = start + (end - start)/2;
        int ans = 0;
        if(l <= mid) ans += query_rec(2 * node, start, mid, tree[node].l_ptr[pos]);
        if(r > mid) ans += query_rec(2 * node + 1, mid + 1, end, tree[node].r_ptr[pos]);

        return ans;
    }

public:
    MergeSortTree(const vector<int>& a) {
        n = a.size();
        arr.resize(n);
        tree.resize(4 * n);
        arr = a;

        build(1, 0, n - 1);
    }

    int query(int l, int r, int x) {
        this->l = l;
        this->r = r;

        auto it = upper_bound(tree[1].values.begin(), tree[1].values.end(), x);
        int pos = it - tree[1].values.begin();

        return query_rec(1, 0, n - 1, pos);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;

    mt19937 rng(random_device{}()); 
    uniform_int_distribution<int> val_dist(1, 1e9); 
    uniform_int_distribution<int> idx_dist(0, n - 1);

    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = val_dist(rng);
    
    auto build_start = chrono::high_resolution_clock::now();
    MergeSortTree mst(a);
    auto build_end = chrono::high_resolution_clock::now();
    auto build_dur = chrono::duration_cast<chrono::milliseconds>(build_end - build_start);
    
    cout << "Tree built in: " << build_dur.count() << " ms\n\n";

    long long total_ns = 0;

    for(int i = 1; i <= q; i++) {
        int u = idx_dist(rng);
        int v = idx_dist(rng);
        int l = min(u, v);
        int r = max(u, v);
        
        int x = val_dist(rng);

        auto q_start = chrono::high_resolution_clock::now();
        int result = mst.query(l, r, x);
        auto q_end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(q_end - q_start);
        total_ns += duration.count();

        if (q <= 20 || i % (q/10) == 0) {
            cout << "Query " << i << ": [L=" << l << ", R=" << r << ", x=" << x << "]"
                 << " | Result: " << result << " | Time: " << duration.count() << " ns" << endl;
        }
    }

    cout << "\nTotal Query Time: " << total_ns / 1000000.0 << " ms" << endl;
    cout << "\nAverage Query Time: " << total_ns / q << " ns" << endl;

    return 0;
}