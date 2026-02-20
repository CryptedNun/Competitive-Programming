#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n; // original array size

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(2 * n);

        build(arr);
    }
    void build(const vector<int>& arr) {
        for(int i = 0; i < n; i++) tree[n + i] = arr[i];                    // n -> 2n-1
        for(int i = n - 1; i > 0; i--) tree[i] = tree[i << 1] + tree[(i << 1) ^ 1]; // n-1 -> 1
    }
    void update(int i, int newVal) {
        for (tree[i += n] = newVal; i > 1; i >>= 1) {
            tree[i >> 1] = tree[i] + tree[i ^ 1];
        }
    }
    int query(int l ,int r) const {
        l += n, r += n;
        int ret = 0;

        while(l <= r) {
            if(l & 1) { ret += tree[l]; l++; }
            if(!(r & 1)) { ret += tree[r]; r--; }
            l >>= 1, r >>= 1;
        }
        return ret;
    }
};

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

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