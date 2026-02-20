#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    int n;
    vector<int> arr;
    struct Pair {
        int max_h, count;
    };
    vector<Pair> tree;

    // ? EXTRA VARS
    int l, r;
    int running_maximum_height_of_query;

    void build(int node, int start, int end) {
        if(start == end) {
            tree[node] = {arr[start], 1};
            return;
        }
        int mid = start + (end - start)/2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        tree[node] = {
            max(tree[2 * node].max_h, tree[2 * node + 1].max_h),
            tree[2 * node].count + GET_COUNT(tree[2 * node].max_h, 2 * node + 1, mid + 1, end)
        };
    }

    // Answers: Number of buildings visible in range, IF maximum height to the left is height
    int GET_COUNT(int height, int node, int start, int end) {
        if(tree[node].max_h <= height) return 0;

        if(start == end) return 1;
        
        int mid = start + (end - start)/2;
        if(tree[2 * node].max_h <= height) return GET_COUNT(height, 2 * node + 1, mid + 1, end);
        else return GET_COUNT(height, 2 * node, start, mid) + (tree[node].count - tree[2 * node].count);
    }

    int query_range(int node, int start, int end) {
        if(start >= l && end <= r) {
            int ans = GET_COUNT(running_maximum_height_of_query, node, start, end);
            running_maximum_height_of_query = max(running_maximum_height_of_query, tree[node].max_h);

            return ans;
        }

        int mid = start + (end - start)/2;
        int ans = 0;
        if(l <= mid) ans += query_range(2 * node, start, mid);
        if(r > mid) ans += query_range(2 * node + 1, mid + 1, end);

        return ans;
    }

public:
    SegmentTree(const vector<int>& a) {
        n = a.size();
        arr.resize(n);
        arr = a;
        tree.resize(4 * n);

        build(1, 0, n - 1);
    }

    int query(int l, int r) {
        this->l = l, this->r = r, running_maximum_height_of_query = 0;

        return query_range(1, 0, n - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> h(n);
    for(auto& e : h) cin >> e;

    SegmentTree st(h);
    while(q--) {
        int a, b; cin >> a >> b; a--, b--;
        cout << st.query(a, b) << endl;
    }
}