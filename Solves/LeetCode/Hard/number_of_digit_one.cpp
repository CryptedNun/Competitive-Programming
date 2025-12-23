// idx, tight, cnt_1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[10][2][10];

ll solve(string& n, int idx, bool tight, ll cnt_1) {
    if(idx == n.size()) return cnt_1;

    if(dp[idx][tight][cnt_1] != -1) return dp[idx][tight][cnt_1];

    int ub = (tight) ? n[idx] - '0' : 9;
    ll res = 0;
    for(int dig = 0; dig <= ub; dig++) {
        res += solve(n, idx + 1, (tight && dig == ub), cnt_1 + (dig == 1));
    }

    return dp[idx][tight][cnt_1] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    string s = to_string(n);
    cout << solve(s, 0, 1, 0) << endl;
}