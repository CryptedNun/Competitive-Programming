#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;
    
    // Temporary variables to avoid passing them in recursion (Mem efficiency)
    int target_idx, target_val;
    int query_l, query_r;

    void build(const vector<int>& arr, int node, int start, int end) {
        if(start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = start + (end - start) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update_rec(int node, int start, int end) {
        if(start == end) {
            tree[node] = target_val;
            return;
        }

        int mid = start + (end - start) / 2;
        
        if(target_idx <= mid) update_rec(2 * node, start, mid);
        else update_rec(2 * node + 1, mid + 1, end);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    // Removed l and r from parameters
    int query_rec(int node, int start, int end) const {
        if(start >= query_l && end <= query_r) return tree[node];

        int mid = start + (end - start) / 2;
        int res = 0;

        if (query_l <= mid) res += query_rec(2 * node, start, mid);
        if (query_r > mid) res += query_rec(2 * node + 1, mid + 1, end);

        return res;
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void update(int idx, int newVal) {
        target_idx = idx;
        target_val = newVal;
        update_rec(1, 0, n - 1);
    }

    int query(int l, int r) {
        query_l = l;
        query_r = r;
        return query_rec(1, 0, n - 1);
    }
};

int main() {

    cout << "Enter array size and elements: ";
    int n; cin >> n;
    vector<int> a(n); for(auto& elem : a) cin >> elem;

    SegmentTree aTree(a);
    cout << "Input what type of query you want to do: 1 = Update, 2 = rangeQuery\n";
    int input;
    while(true) {
        cin >> input;
        if(input == 1) {
            int idx, val; cin >> idx >> val;
            a[idx] = val;
            aTree.update(idx, val);
        } else if(input == 2) {
            int l, r; cin >> l >> r;
            cout << aTree.query(l, r) << endl;
        } else break;
    }

    return 0;
}