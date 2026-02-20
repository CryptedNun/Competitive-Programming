// ? The following code is a correct solution,

#include <bits/stdc++.h>
using namespace std;

inline void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

class MergeSortTree {
    struct Node {
        vector<int> values;
        vector<int> l_ptr;
        vector<int> r_ptr;
    };
    int n;
    vector<int> arr;
    vector<Node> tree;

    int l, r;

    void merger(int node) {
        int left_idx = 2 * node;
        int right_idx = 2 * node + 1;

        auto& v = tree[node].values;
        auto& lv = tree[left_idx].values;
        auto& rv = tree[right_idx].values;

        v.resize(lv.size() + rv.size());

        merge(lv.begin(), lv.end(), rv.begin(), rv.end(), v.begin());
    }

    void populate_l_r(int node) {
        int left_idx = 2 * node;
        int right_idx = 2 * node + 1;

        auto& v = tree[node].values;
        auto& lv = tree[left_idx].values;
        auto& rv = tree[right_idx].values;

        tree[node].l_ptr.resize(v.size() + 1);
        tree[node].r_ptr.resize(v.size() + 1);

        // ? tree[node].l_ptr[i] = the idx of the first(smallest) elem >= tree[node].values[i] in leftchild
        // ? tree[node].r_ptr[i] = the idx of the first(smallest) elem >= tree[node].values[i] in rightchild
        int l_idx = 0, r_idx = 0;
        for(int i = 0; i <= v.size(); i++) {
            int val = (i < v.size()) ? v[i] : INT_MAX;

            while(l_idx < lv.size() && lv[l_idx] < val) l_idx++;
            while(r_idx < rv.size() && rv[r_idx] < val) r_idx++;

            tree[node].l_ptr[i] = l_idx;
            tree[node].r_ptr[i] = r_idx;
        }
    }

    void build(int node, int start, int end) {
        if(start == end) {
            tree[node].values.push_back(arr[start]);
            return;
        }

        int mid = mid_calc(start, end);
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        merger(node);

        populate_l_r(node);
    }

    int query_rec(int node, int start, int end, int pos) {
        if(start >= l && end <= r) {
            int total_elements = end - start + 1;
            return total_elements - pos;
        }
        
        int mid = mid_calc(start, end);
        int ans = 0;
        if(l <= mid) ans += query_rec(2 * node, start, mid, tree[node].l_ptr[pos]);
        if(r > mid) ans += query_rec(2 * node + 1, mid + 1, end, tree[node].r_ptr[pos]);

        return ans;
    }

    void clear_values(int node, int start, int end) {
        if (start != end) {
            clear_values(2 * node, start, mid_calc(start, end));
            clear_values(2 * node + 1, mid_calc(start, end) + 1, end);
        }

        if (node != 1) { 
            tree[node].values.clear(); 
            tree[node].values.shrink_to_fit();
        }
    }

    inline int mid_calc(int s, int e) { return s + (e - s) / 2; }

public:
    MergeSortTree(const vector<int>& a) {
        n = a.size();
        arr.resize(n);
        tree.resize(4 * n);
        arr = a;

        build(1, 0, n - 1);

        // ! NOW CLEAR `values` ARRAY OF USELESS INTERNAL AND LEAF NODES, TO OMIT CACHE MISSES.
        if(n > 0) clear_values(1, 0, n - 1);
    }

    int query(int l, int r, int x) {
        this->l = l;
        this->r = r;

        auto it = upper_bound(tree[1].values.begin(), tree[1].values.end(), x);
        int pos = it - tree[1].values.begin();

        return query_rec(1, 0, n - 1, pos);
    }
};

int main() {
    fastIO();

    int n, q; cin >> n >> q;
    vector<int> x(n);
    for(auto& e : x) cin >> e;

    map<int, int> occurence;
    vector<int> new_x(n);
    // new_x[i] = the idx of the element x[i] that occurs immediately after i;

    for(int i = n - 1; i >= 0; i--) {
        if(occurence[x[i]] == 0) new_x[i] = n; 
        else new_x[i] = occurence[x[i]];

        occurence[x[i]] = i;
    }

    MergeSortTree mst(new_x);
    while(q--) {
        int l, r; cin >> l >> r;
        l--, r--;

        cout << mst.query(l, r, r) << '\n';
    }

    return 0;

    // ! The following code uses Coordinate compression for faster querying, although negligible.
    // fastIO();
    // int n, q; cin >> n >> q;

    // vector<int> x(n);
    // vector<int> coords;
    // for(int i = 0; i < n; i++) {
    //     cin >> x[i];
    //     coords.push_back(x[i]);
    // }

    // // Coordinate compression to replace map with a fast vector
    // sort(coords.begin(), coords.end());
    // coords.erase(unique(coords.begin(), coords.end()), coords.end());
    
    // vector<int> last_pos(coords.size(), n);
    // vector<int> next_occ(n);

    // for(int i = n - 1; i >= 0; i--) {
    //     int val = lower_bound(coords.begin(), coords.end(), x[i]) - coords.begin();
    //     next_occ[i] = last_pos[val];
    //     last_pos[val] = i;
    // }

    // MergeSortTree mst(next_occ);
    
    // while(q--) {
    //     int l, r;
    //     cin >> l >> r;
    //     // The logic: distinct elements = count of elements in [L-1, R-1] 
    //     // whose NEXT occurrence is strictly greater than R-1.
    //     cout << mst.query(l - 1, r - 1, r - 1) << "\n";
    // }

    // return 0;
}