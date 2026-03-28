// ? given an array and q many queries of t, l, r, x;
// ? if t = 2, then set all elems within range of l,r to x
// ? if t = 1 add x to all elems of range l,r
// ? if t = 3, return the sum of [l,r], x won't be given.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long sum = 0;
    long long lazySet = 0;
    long long lazyAdd = 0;
    bool hasSet = false;
};


class SegmentTree {
    int n;
    vector<Node> tree;
    vector<long long> arr;

    int type, ql, qr, value;

    // ? MAIN CODE LOGIC-------------------------------------------------------------------------------------
    void applySet(int node, int start, int end, long long val) {
        tree[node].sum = (1LL * end - start + 1) * val; 

        tree[node].hasSet = true;
        tree[node].lazySet = val;

        // !!___CRITICAL___!! //
        tree[node].lazyAdd = 0;
    }

    void applyAdd(int node, int start, int end, long long val) {
        tree[node].sum += (1LL * end - start + 1) * val;

        if(tree[node].hasSet) tree[node].lazySet += val;
        else tree[node].lazyAdd += val;
        // tree[node].lazyAdd += val;
        // * just using tree[node].lazyAdd += val; will also do just fine, 
        // * given that you first check .hasSet in push(), then check .lazyAdd != 0
    }

    void push(int node, int start, int end) {
        if(start == end) return; // Guardrail for not pushing on leafnodes

        int mid = start + (end - start)/2;
        if(tree[node].hasSet) {
            applySet(2 * node, start, mid, tree[node].lazySet);
            applySet(2 * node + 1, mid + 1, end, tree[node].lazySet);

            tree[node].hasSet = false;
            tree[node].lazySet = 0;
        }

        if (tree[node].lazyAdd != 0) {
            applyAdd(2 * node, start, mid, tree[node].lazyAdd);
            applyAdd(2 * node + 1, mid + 1, end, tree[node].lazyAdd);
        
            tree[node].lazyAdd = 0;
        }
    }
    // ? END-------------------------------------------------------------------------------------------------

    void build(int node, int start, int end) {
        if(start == end) {
            tree[node].sum = arr[start];
            tree[node].hasSet = false;
            tree[node].lazySet = tree[node].lazyAdd = 0;

            return;
        }

        int mid = start + (end-start)/2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
    }

    void update_range(int node, int start, int end) {
        if(ql <= start && end <= qr) {
            if(type == 2) applySet(node, start, end, value);
            else applyAdd(node, start, end, value);
            return;
        }
        push(node, start, end);

        int mid = start + (end - start)/2;
        if(ql <= mid) update_range(2 * node, start, mid);
        if(qr > mid) update_range(2 * node + 1, mid + 1, end);

        tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
    }

    long long query_rec(int node, int start, int end) {
        if(ql <= start && end <= qr) {
            return tree[node].sum;
        }
        push(node, start, end);

        int mid = start + (end - start) / 2;
        long long ans = 0;
        if(ql <= mid) ans += query_rec(2 * node, start, mid);
        if(qr > mid) ans += query_rec(2 * node + 1, mid + 1, end);

        return ans;
    }

public:
    SegmentTree(const vector<long long>& a) {
        n = a.size();
        tree.resize(4 * n);
        arr = a;
        build(1, 0, n - 1);
    }

    void update(int t, int l, int r, int x) {
        type = t;
        ql = l, qr = r;
        value = x;

        update_range(1, 0, n - 1);
    }

    long long query(int l, int r) {
        ql = l, qr = r;
        return query_rec(1, 0, n - 1);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<long long> t(n); for(auto&e:t) cin>>e;

    SegmentTree st(t);
    while(q--) {
        int t, l, r, x;  cin >> t >> l >> r;
        --l, --r;
        if(t == 1) {
            cin >> x;
            st.update(1, l, r, x);
        }
        else if(t == 2) {
            cin >> x;
            st.update(2, l, r, x);
        }
        else {
            cout << st.query(l, r) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}