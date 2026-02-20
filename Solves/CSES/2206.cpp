#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    vector<int> arr;
    int n;

    // ? Extra vars
    int l, r; // * query
    int i, val; // * update

    void build(int node, int start, int end) {
        if(start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = start + (end - start)/2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end) {
        if(start == end) {
            tree[node] = arr[i] = val;
            return;
        }

        int mid = start + (end - start)/2;
        if(i <= mid) update(2 * node, start, mid);
        else update(2 * node + 1, mid + 1, end);

        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end) {
        if(l <= start && end <= r) return tree[node];

        int mid = start + (end - start) / 2;
        int ret = INT_MAX;

        if(l <= mid) ret = min(ret, query(2 * node, start, mid));
        if(r > mid) ret = min(ret, query(2 * node + 1, mid + 1, end));

        return ret;
    }

public:
    SegmentTree(const vector<int>& a) {
        n = a.size();
        arr.resize(n);
        arr = a;
        tree.resize(4 * n);

        build(1, 0, n - 1);
    }

    void update(int idx, int newVal) {
        i = idx, val = newVal;

        update(1, 0, n - 1);
    }

    int query(int l, int r) {
        this->l = l, this->r = r;

        return query(1, 0 , n - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> p(n);
    for(auto& e : p) cin >> e;

    vector<int> plus, minus;
    for(int i = 0; i < n; i++) {
        plus.push_back(p[i] + (i + 1));
        minus.push_back(p[i] - (i + 1));
    }

    SegmentTree st_plus(plus), st_minus(minus);

    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int k, x; cin >> k >> x;
            k--;

            p[k] = x;
            st_plus.update(k, p[k] + (k + 1));
            st_minus.update(k, p[k] - (k + 1));
        } else {
            int k; cin >> k;
            k--;

            int min_right = (k == n - 1) ? INT_MAX : st_plus.query(k + 1, n - 1) - (k + 1);
            int min_left = st_minus.query(0, k) + (k + 1);

            cout << min(min_left, min_right) << endl;
        }
    }
}