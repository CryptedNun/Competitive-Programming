#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;
    
    // Temporary variables to avoid passing them in recursion (Mem efficiency)
    int val;

    void build(const vector<int>& arr, int node, int start, int end) {
        if(start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = start + (end - start) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);

        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    // Removed l and r from parameters
    int query_rec(int node, int start, int end) {
        // ! If the nodemax is still smaller, return 0, meaning no answer. Guardrail condition.
        if(tree[node] < val) return 0;

        // ! Leaf node approached, update tree_node and return the leaf's index in original arr
        if(start == end) {
            tree[node] -= val;
            return start + 1;    // ! class uses 0-based idx, so +1 for 1-based.
        }

        int mid = start + (end - start) / 2;
        int res = 0;

        // ! Left side first, to get earliest first-fit occurence. Else right.
        if (tree[2 * node] >= val) res = query_rec(2 * node, start, mid);
        else if (tree[2 * node + 1] >= val) res = query_rec(2 * node + 1, mid + 1, end);
    
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        return res;
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    int query(int val) {
        this->val = val;
        return query_rec(1, 0, n-1);
    }
};

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(auto& e : a) cin >> e;

    SegmentTree maxiTree(a);
    vector<int> responses;
    while(m--) {
        int input; cin >> input;
        responses.push_back(maxiTree.query(input));
    }

    for(auto& e : responses) cout << e << " ";
    return 0;
}