#include <bits/stdc++.h>
using namespace std;
 
class SegmentTree {
    struct Node {
        long long sum;
        long long pref;
        long long suff;
        long long max_sub;
    };
    int n;
    vector<int> arr;
    vector<Node> tree;
 
    int l, r;
    Node curr;
 
 
    void build_basecase(int node, int start, int end) {
        tree[node].sum = arr[start];
        tree[node].pref = tree[node].suff = tree[node].max_sub = max(arr[start] * 1LL, 0LL);
    }
 
    void build_merge(int node) {
        Node& parent = tree[node];
        Node left_child = tree[leftchild(node)];
        Node right_child = tree[rightchild(node)];
 
        parent.sum = left_child.sum + right_child.sum;
        parent.pref = max(left_child.pref, left_child.sum + right_child.pref);
        parent.suff = max(right_child.suff, right_child.sum + left_child.suff);
        parent.max_sub = max({left_child.max_sub, right_child.max_sub, left_child.suff + right_child.pref});
    }
 
    void build(int node, int start, int end) {
        if(start == end) {
            build_basecase(node, start, end);
            return;
        }
 
        int mid = mid_(start, end);
        build(leftchild(node), start, mid);
        build(rightchild(node), mid + 1, end);
 
        build_merge(node);
    }
 
    void query_basecase(int node) {
        Node tree_node = tree[node];
        Node temp_curr = curr;
 
        curr.sum = temp_curr.sum + tree_node.sum;
        curr.pref = max(temp_curr.pref, temp_curr.sum + tree_node.pref);
        curr.suff = max(tree_node.suff, tree_node.sum + temp_curr.suff);
        curr.max_sub = max({temp_curr.max_sub, tree_node.max_sub, temp_curr.suff + tree_node.pref});
    }
 
    // void query_merge(int node) {
 
    // }
 
    void query_rec(int node, int start, int end) {
        if(start >= l && end <= r) {
            query_basecase(node);
            return;
        }
 
        int mid = mid_(start, end);
        if(l <= mid) query_rec(leftchild(node), start, mid);
        if(r > mid) query_rec(rightchild(node), mid + 1, end);
    }
 
    inline int mid_(int s, int e) { return s + (e-s)/2; }
    inline int leftchild (int node) { return node << 1; }
    inline int rightchild (int node) { return (node << 1) | 1; }
 
public:
    SegmentTree(const vector<int>& a) {
        n = a.size();
        arr.resize(n);
        tree.resize(4 * n);
        arr = a;
 
        build(1, 0, n - 1);
    }
 
    long long query(int l, int r) {
        this->l = l;
        this->r = r;
        curr = {0LL, 0LL, 0LL, 0LL};
 
        query_rec(1, 0, n - 1);
        return curr.max_sub;
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, q; cin >> n >> q;
    vector<int> x(n);
    for(auto& e : x) cin >> e;
 
    SegmentTree st(x);
    while(q--) {
        int l, r; cin >> l >> r;
        cout << st.query(l-1, r-1) << '\n';
    }
    
    return 0;
}