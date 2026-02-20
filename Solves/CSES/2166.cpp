// * Main logic: Each node stores its range_sum and range_max_pref.
// * the two child nodes are merged as follows: 
// * parent.sum = left_child.sum + right_child.sum
// * parent.pref_max = max(left_child.pref_max, left_child.sum + right_child.pref_max)
// * For example: [2, -1] * [3, -2]; left_child.pref_max = 2, left_child.sum + right.pref_max = 1 + 3
// * The neutral/identity element is {0, 0}, for sum it's obvious and 0 for pref_max since 0 prefixsum (empty prefix) is allowed.

#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    struct Node {
        long long sum;
        long long max_pref;
    };
    int n;
    vector<Node> tree;
    vector<int> arr;

    // ? Extra vars for update and query respectively, reduces mem overhead of recursive function calls
    int idx, update_val;
    int l, r;

    Node merge(Node l, Node r) {
        Node ret;
        ret.sum = l.sum + r.sum;
        ret.max_pref = max(l.max_pref, l.sum + r.max_pref);

        return ret;
    }

    void build (int node, int start, int end) {
        if(start == end) {
            tree[node] = {arr[start], max(0LL, (long long)arr[start])};
            return;
        }

        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update_rec(int node, int start, int end) {
        if(start == end) {
            tree[node] = {update_val, max(0LL, (long long)update_val)};
            return;
        }

        int mid = start + (end - start) / 2;
        if(idx <= mid) update_rec(2 * node, start, mid);
        else update_rec(2 * node + 1, mid + 1, end);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query_rec(int node, int start, int end) {
        // ? Return neutral elem when out-of-range
        if(end < l || start > r) return {0LL, 0LL};

        if(start >= l && end <= r) return tree[node];

        int mid = start + (end - start) / 2;
        return merge(query_rec(2 * node, start, mid), query_rec(2 * node + 1, mid + 1, end));
    }

public:
    SegmentTree(const vector<int>& a) {
        n = a.size();
        arr = a;
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void update(int i, int newVal) {
        idx = i;
        update_val = newVal;

        update_rec(1, 0, n - 1);
    }

    long long query(int l, int r) {
        this->l = l, this->r = r;

        return query_rec(1, 0, n - 1).max_pref;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (auto& e : a) cin >> e;

    SegmentTree st(a);

    while(q--) {
        int type; cin >> type;
        if (type == 1) {
            int k, u; cin >> k >> u;
            st.update(k - 1, u);
        } else {
            int a, b; cin >> a >> b;
            cout << st.query(a - 1, b - 1) << '\n';
        }
    }
}