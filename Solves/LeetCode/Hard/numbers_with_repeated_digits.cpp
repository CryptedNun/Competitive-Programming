#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// states: idx, tight, repetition, mask, lz
ll dp[10][2][2][1 << 9][2];

ll solve(string& s, int idx, bool tight, bool repetition, int mask, bool lz) {
    if(idx == s.size()) return repetition ? 1 : 0;

    if(dp[idx][tight][repetition][mask][lz] != -1) return dp[idx][tight][repetition][mask][lz];

    int ub = (tight) ? s[idx] - '0' : 9;
    ll res = 0;
    for(int digi = 0; digi <= ub; digi++) {
        bool curr_tight = tight && (digi == ub);
        bool curr_lz = lz && (digi == 0);
        bool curr_repetition = repetition;
        int curr_mask = mask;

        // This condition checks if the digit is being formed, if yes, check and update mask , otherwise do nothing
        if (!curr_lz) {
            // If the digit is already in the mask, we found a repetition
            if (mask & (1 << digi)) {
                curr_repetition = true;
            }
            curr_mask |= (1 << digi);
        }

        res += solve(s, idx + 1, curr_tight, curr_repetition, curr_mask, curr_lz);
    }

    return dp[idx][tight][repetition][mask][lz] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    memset(dp, -1, sizeof(dp));
    
    string str = to_string(n);
    cout << solve(str, 0, 1, 0, 0, 1) << endl;
}