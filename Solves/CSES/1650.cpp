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

    void update(int i, long long val) {
        for (; i <= n; i += ( i & (~i + 1) ) )  // One based indices
            tree[i] ^= val;
    }

    long long query(int i) {
        long long sum = 0;
        for (; i > 0; i -= ( i & (~i + 1) ) ) 
            sum ^= tree[i];
        return sum;
    }

    long long rangeQuery(int l, int r) {
        return query(r) ^ query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> x(n);
    for(auto& elem : x) cin >> elem;

    FenwickTree BIT(n);
    for(int i = 0; i < n ; i++) 
        BIT.update(i + 1, x[i]);
    
    while(q--) {
        int a, b; cin >> a >> b;
        cout << BIT.rangeQuery(a, b) << '\n';
    }
}