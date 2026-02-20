//! https://cses.fi/problemset/task/1651/

#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<long long> tree, lazy;
    int n;

    // extra variables
    int target_l, target_r;
    long long val_to_add;

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (long long)(end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void build(const vector<long long>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update_range_rec(int node, int start, int end) {
        push(node, start, end);
        if (start >= target_l && end <= target_r) {
            lazy[node] += val_to_add;
            push(node, start, end);
            return;
        }

        int mid = start + (end - start) / 2;
        if (target_l <= mid) update_range_rec(2 * node, start, mid);
        // else push(2 * node, start, mid);    

        if (target_r > mid) update_range_rec(2 * node + 1, mid + 1, end);
        // else push(2 * node + 1, mid + 1, end);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }       

    long long query_range_rec(int node, int start, int end) {
        push(node, start, end);
        if (start >= target_l && end <= target_r) return tree[node];

        int mid = start + (end - start) / 2;
        long long res = 0;

        if (target_l <= mid) res += query_range_rec(2 * node, start, mid);
        if (target_r > mid) res += query_range_rec(2 * node + 1, mid + 1, end);

        return res;
    }

public:
    SegmentTree(const vector<long long>& arr) : n(arr.size()) {
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    void update(int l, int r, int val) {
        target_l = l; target_r = r; val_to_add = val;
        update_range_rec(1, 0, n - 1);
    }

    long long query(int l, int r) {
        target_l = l; target_r = r;
        return query_range_rec(1, 0, n - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<long long> a(n);
    for(auto& e : a) cin >> e;

    SegmentTree tree(a);
    while(q--) {
        int type; cin >> type;
        if(type == 2) {
            int i; cin >> i;
            cout << tree.query(i - 1, i - 1) << '\n';
        } else {
            int a, b, u; cin >> a >> b >> u;
            tree.update(a - 1, b - 1, u);
        }
    }
}