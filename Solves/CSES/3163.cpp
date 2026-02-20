#include <bits/stdc++.h>
using namespace std;

// ! RECURSIVE
class MergeSortTree {
    int n; 
    vector<int> arr;
    vector<vector<int>> tree;

    // ? EXTRA VARS
    int l, r;
    int minimum, maximum;

    // The node to merge to, the two nodes left__right to merge from
    void merger(int node) {
        int left_idx = 2 * node;
        int right_idx = 2 * node + 1;

        tree[node].resize(tree[left_idx].size() + tree[right_idx].size());

        merge(tree[left_idx].begin(), tree[left_idx].end(),
                   tree[right_idx].begin(), tree[right_idx].end(),
                   tree[node].begin());
    }

    void build(int node, int start, int end) {
        if(start == end) {
            tree[node].push_back(arr[start]);
            return;
        }

        int mid = start + (end - start)/2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        merger(node);
    }

    int query_range(int node, int start, int end) {
        if(start >= l && end <= r) {
            auto it1 = lower_bound(tree[node].begin(), tree[node].end(), minimum);    // ! Gets smallest elem >= minimum
            auto it2 = upper_bound(tree[node].begin(), tree[node].end(), maximum);    // ! Gets smallest elem > maximum, GOING BACK once gives largest elem <= maximum
            
            return (int)(it2 - it1);
        }

        int mid = start + (end - start)/2;
        int ans = 0;
        if(l <= mid) ans += query_range(2 * node, start, mid);
        if(r > mid) ans += query_range(2 * node + 1, mid + 1, end);

        return ans;
    }

public:
    MergeSortTree(const vector<int>& a) {
        n = a.size();
        arr.resize(n);
        arr = a;
        tree.resize(4 * n);

        build(1, 0, n - 1);
    }

    int query(int l, int r, int c, int d) {
        this->l = l, this->r = r, minimum = c, maximum = d;

        return query_range(1, 0, n - 1);
    }
};

class IterativeMergeSortTree {
    int n;
    vector<vector<int>> tree;

public:
    IterativeMergeSortTree(const vector<int>& a) {
        n = a.size();
        tree.resize(2 * n);

        for (int i = 0; i < n; i++) {
            tree[n + i] = {a[i]};
        }

        for (int i = n - 1; i > 0; i--) {
            tree[i].resize(tree[i << 1].size() + tree[i << 1 | 1].size());

            merge(tree[i << 1].begin(), tree[i << 1].end(),
                  tree[i << 1 | 1].begin(), tree[i << 1 | 1].end(),
                  tree[i].begin());
        }
    }

    int query(int l, int r, int mn, int mx) {
        int count = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) count += get_count(tree[l++], mn, mx);
            if (r & 1) count += get_count(tree[--r], mn, mx);
        }

        return count;
    }

private:
    inline int get_count(const vector<int>& vec, int mn, int mx) {
        return upper_bound(vec.begin(), vec.end(), mx) - 
               lower_bound(vec.begin(), vec.end(), mn);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> x(n);
    for(auto& e : x) cin >> e;

    IterativeMergeSortTree mst(x);
    while(q--) {
        int a, b, c, d; cin >> a >> b >> c >> d; a--, b--;

        cout << mst.query(a, b, c, d) << '\n';
    }
}