// !Given Q ranges of the form [L_i,R_i], 
// !find for each point x ∈ [1,N]
// !the number of ranges that contain that point.

// ! 1 ≤ N
// ! Q ≤ 1e7

// ! 1 ≤ L_i ≤ R_i ≤ 1e7

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    struct Range { int l, r; };
    vector<Range> ranges(q);
    while(q--) {
        int l, r; cin >> l >> r;
        ranges.push_back({l, r});
    }

    vector<int> diff(n + 2, 0);
    for(Range r : ranges) diff[r.l]++, diff[r.r+1]--;
    for(int i = 1; i < diff.size(); i++) diff[i] += diff[i - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}