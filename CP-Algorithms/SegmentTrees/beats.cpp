// ? https://www.youtube.com/watch?v=NwkO73jGSPA
// ? https://codeforces.com/problemset/problem/438/D

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class SegmentTree {
    int n;
    struct Node {
        long long sum;
        int max;
    };
    vector<Node> tree;
    vector<int> arr;
    vector<int> lazy;

    int ql, qr, x, i;

    inline int __mid(int l, int r) { return l + (r - l)/2; }

    void build(int node, int l, int r) {
        if(l == r) {
            tree[node].sum = tree[node].max = 1LL * arr[l];
            return;
        }
        int m = __mid(l, r);
        build(2 * node, l, m);
        build(2 * node + 1, m + 1, r);

        tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
        tree[node].max = max(tree[2 * node].max, tree[2 * node + 1].max);
    }

    void update_rec(int node, int l, int r) {
        if(ql > r || qr < l || tree[node].max < x) return;
        if(l == r && tree[node].sum >= x) {
            // Base case
            tree[node].max = tree[node].sum %= x;
            return;
        }

        int m = __mid(l, r);
        update_rec(2 * node, l, m);
        update_rec(2 * node + 1, m + 1, r);

        tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
        tree[node].max = max(tree[2 * node].max, tree[2 * node + 1].max);
    }

    void point_update(int node, int l, int r) {
        if(l > i || r < i) return;
        if(l == r) {
            tree[node].max = tree[node].sum = x;
            return;
        }

        int m = __mid(l, r);
        point_update(2 * node, l, m);
        point_update(2 * node + 1, m + 1, r);

        tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
        tree[node].max = max(tree[2 * node].max, tree[2 * node + 1].max);
    }

    long long query_rec(int node, int l, int r) {
        if(ql > r || qr < l) return 0LL;
        if(ql <= l && r <= qr) {
            return tree[node].sum;
        }

        int m = __mid(l, r);
        long long ans = 0;
        ans += query_rec(2 * node, l, m);
        ans += query_rec(2 * node + 1, m + 1, r);

        return ans;
    }

public:
    SegmentTree(const vector<int>& a) {
        n = a.size();
        arr = a;
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void update(int l, int r, int x) {
        ql = l, qr = r;
        this->x = x;

        update_rec(1, 0, n - 1);
    }

    void p_update(int idx, int x) {
        i = idx, this->x = x;

        point_update(1, 0, n - 1);
    }

    long long query(int l, int r) {
        ql = l, qr = r;

        return query_rec(1, 0, n - 1);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(auto& e : a) cin >> e;

    SegmentTree st(a);
    while(m--) {
        int type; cin >> type;
        int l, r, k, x;
        switch (type) {
            case 1:
                cin >> l >> r;
                cout << st.query(l-1, r-1) << endl;
                break;
            case 2:
                cin >> l >> r >> x;
                st.update(l-1, r-1, x);
                break;
            case 3:
                cin >> k >> x;
                st.p_update(k - 1, x);
                break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--) solve();
}