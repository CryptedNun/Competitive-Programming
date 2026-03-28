// ? Given an array 
// ? you can do (min= x) operation on a segment [l, r], and return a segment's sum

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class SegmentTree {
    const int INF = 2e9;

    int n;
    struct Node {
        long long sum;
        int max;
        int mcnt;
        int smax;
    };
    vector<Node> tree;
    vector<int> lazy;
    vector<int> arr;

    int x, ql, qr;

    inline int __mid(int l, int r) { return l + (r - l)/2; }

    Node merge(const Node& N1, const Node& N2) {
        Node ret;
        ret.sum = N1.sum + N2.sum;
        ret.max = max(N1.max, N2.max);

        ret.mcnt = 0;
        if(ret.max == N1.max) ret.mcnt += N1.mcnt;
        if(ret.max == N2.max) ret.mcnt += N2.mcnt;

        ret.smax = -1;
        if(N1.smax > ret.smax && N1.smax < ret.max) ret.smax = N1.smax;
        if(N2.smax > ret.smax && N2.smax < ret.max) ret.smax = N2.smax;
        if(N1.max > ret.smax && N1.max < ret.max) ret.smax = N1.max;
        if(N2.max > ret.smax && N2.max < ret.max) ret.smax = N2.max;

        return ret;
    }

    void update_node(int node, int upd) {
        int cnt = tree[node].mcnt;
        int max = tree[node].max;
        tree[node].sum -= 1LL * cnt * (max - upd);
        tree[node].max = upd;
    }

    void apply_chmin(int node, int limit) {
        if (tree[node].max <= limit) return;

        // ? APPLY CHANGE/UPDATE
        tree[node].sum -= 1LL * tree[node].mcnt * (tree[node].max - limit);
        tree[node].max = limit;
        
        // ? UPDATE TAG
        lazy[node] = limit;
        // ? TECHNICALLY SHOULD BE lazy[node] = min(limit, lazy[node]), 
        // ? but the if(max <= limit) condition at start is a guardrail
    }

    void push(int node) {
        if (lazy[node] == INF) return;

        // ? APPLY TAG TO CHIDLREN
        apply_chmin(2 * node, lazy[node]);
        apply_chmin(2 * node + 1, lazy[node]);

        lazy[node] = INF; //  ? PARENT TAG RESET
    }

    void build(int node, int l, int r) {
        if(l == r) {
            tree[node].sum = tree[node].max = arr[l];
            tree[node].mcnt = 1;
            tree[node].smax = -1; // ? Sentinel value since a_i >= 1

            return;
        }

        int m = __mid(l, r);
        build(2 * node, l, m);
        build(2 * node + 1, m + 1, r);

        tree[node] = merge(tree[2*node], tree[2*node + 1]);
    }

    inline bool tc(int node) { return x < tree[node].max && x > tree[node].smax; }
    inline bool bc(int node) { return x >= tree[node].max; }

    void update(int node, int l, int r) {
        if (ql > r || qr < l ||   /*BREAKCONDITION*/bc(node)) return;
        if (ql <= l && r <= qr && /*TAGCONDITION*/  tc(node)) {
            // * UPDATE THE NODE AND PUTTAG ( both in apply_chmin() )
            apply_chmin(node, x);
            return;
        }
        push(node);

        int m = __mid(l,r);
        update(2 * node, l, m);
        update(2 * node + 1, m + 1, r);

        tree[node] = merge(tree[2*node], tree[2*node + 1]);
    }

    long long query_rec(int node, int l, int r) {
        if(ql > r || qr < l) return 0LL;
        if(ql <= l && r <= qr) return tree[node].sum;
        push(node);

        long long ans = 0LL;
        int m = __mid(l, r);
        ans += query_rec(2*node, l, m);
        ans += query_rec(2*node + 1, m+1, r);

        return ans;
    }

public:
    SegmentTree(const vector<int>& a) {
        n = a.size();
        arr = a;
        tree.resize(4 * n);
        lazy.assign(4 * n, INF);
        build(1, 0, n - 1);
    }
    
    void __upd(int l, int r, int x) {
        ql = l, qr = r;
        this->x = x;

        update(1, 0, n - 1);
    }

    long long __query(int l, int r) {
        ql = l, qr = r;

        return query_rec(1, 0, n - 1);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto& e : a) cin >> e;

    int q; cin >> q;
    SegmentTree st(a);
    while(q--) {
        int type, l, r, x; cin >> type >> l >> r;
        if(type == 1) { 
            cin >> x;
            st.__upd(l-1, r-1, x);
        } else cout << st.__query(l-1, r-1) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--) solve();
}