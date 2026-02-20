#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll memo[65][2][65];

string toBin(ll in) {
    if (in == 0) return "0";
    string ret; 
    while(in > 0) {
        ret.push_back('0' + (in & 1));
        in >>= 1;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

ll solve_dp(const string& s, int idx, bool tight, int curr_count) {
    if (idx == s.size()) return curr_count;
    
    if (memo[idx][tight][curr_count] != -1) return memo[idx][tight][curr_count];

    ll ans = 0;
    int limit = tight ? (s[idx] - '0') : 1;

    for (int bit = 0; bit <= limit; bit++) {
        bool next_tight = tight && (bit == limit);
        ans += solve_dp(s, idx + 1, next_tight, curr_count + (bit == 1));
    }

    return memo[idx][tight][curr_count] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    string str = toBin(n);

    memset(memo, -1, sizeof(memo));

    cout << solve_dp(str, 0, true, 0) << endl;

    return 0;
}