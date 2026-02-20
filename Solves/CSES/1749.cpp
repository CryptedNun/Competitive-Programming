#include <bits/stdc++.h>
using namespace std;

// ? We use a segment tree to track "Presence" of elements within a range, if present, leaf node is 1, else 0;
// ? Internal nodes store count of elements present in its range
class SegmentTree {
    vector<int> tree;
    int n;
    
    // // Temporary variables to avoid passing them in recursion (Mem efficiency)
    // int target_idx, target_val;
    // int query_l, query_r;

    void build(int node, int start, int end) {
        if(start == end) {
            tree[node] = 1;
            return;
        }

        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    // Removed l and r from parameters
    int query_rec(int node, int start, int end, int p) {
        if(start == end) {
            tree[node] = 0; // ! REMOVED
            return start;
        }
        // if(start >= query_l && end <= query_r) return tree[node];

        int mid = start + (end - start) / 2;
        int res;

        if (tree[2 * node] >= p) res = query_rec(2 * node, start, mid, p);
        else res = query_rec(2 * node + 1, mid + 1, end, p - tree[2 * node]);

        tree[node] = tree[2 * node] + tree[2 * node + 1]; // ! UPDATED NODE
        return res;
    }

public:
    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    int query(int p) {
        return query_rec(1, 0, n - 1, p);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for(auto& e : a) cin >> e;

    SegmentTree presenceTree(n);
    vector<int> idx;
    while(n--) {
        int p; cin >> p;
        idx.push_back(presenceTree.query(p));
    }

    for(auto& e : idx) cout << a[e] << " ";

    return 0;
}