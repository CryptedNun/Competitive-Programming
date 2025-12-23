#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 32 is max size of int data
ll dp[32][2][2];

ll solve(string& str, int idx, bool tight, bool prev) {
    if(idx == str.size()) return 1;

    if(dp[idx][tight][prev] != -1) return dp[idx][tight][prev];

    int ub = tight ? str[idx] - '0' : 1;
    ll res = 0;
    for(int bit = 0; bit <= ub; bit++) {
        if(bit == 1 && prev) continue;      // Skip case where currbit and prevbit are both 1
        res += solve(str, idx + 1, (tight && (bit == ub)), (bit == 1));
    }

    return dp[idx][tight][prev] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    memset(dp, -1, sizeof(dp));
    string s = bitset<32>(n).to_string();
    s = s.substr(s.find('1'));
    cout << solve(s, 0, 1, 0) << endl;
}