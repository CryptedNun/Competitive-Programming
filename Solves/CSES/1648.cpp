#include <bits/stdc++.h>
using namespace std;

// 1-based index BIT implementation
class FenwickTree {
    vector<long long> tree;
    int n;
public:
    FenwickTree(int size) : n(size) {
        tree.assign(n + 1, 0LL); // One based indices
    }

    // Update the tree when an array index is updated.
    // pass delta = final - initial, when updating pre-existing arr. (This is why abelian/reversible groups are required)
    void update(int i, long long val) {
        for (; i <= n; i += ( i & (~i + 1) ) )  // One based indices
            tree[i] += val;
    }

    // Get the sum of the range [1, i] through the BIT
    long long query(int i) {
        long long sum = 0;
        for (; i > 0; i -= ( i & (~i + 1) ) ) 
            sum += tree[i];
        return sum;
    }

    long long rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<long long> x(n);
    for(auto& elem : x) cin >> elem;

    FenwickTree BIT(n);
    for(int i = 0; i < n ; i++) BIT.update(i + 1, x[i]);
    
    while(q--) {
        int type;
        long long a, b; 
        cin >> type >> a >> b;

        if(type == 2) {
            cout << BIT.rangeQuery(a, b) << '\n';
        } else if(type == 1) {
            BIT.update(a, b - x[a - 1]);
            x[a - 1] = b;
            // delta = final - initial; final = u, initial = x[k - 1] {k is one-based index}
        }
    }
}