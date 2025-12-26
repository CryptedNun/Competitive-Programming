// ? https://youtu.be/gIJczEQoSmM?si=NYXYuGXxpAOom9kF
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// dp[prev_digit][remaining_digits][is_leading_zero]
ll dp[11][20][2]; 

// This function recursively counts 'proper' numbers from 0 to n.
ll dpf(const string& str, int prev, int idx, bool tight, bool lz) {
    if (idx == str.size()) return 1;

    // Use 'remaining digits' for universal memoization
    int rem = str.size() - idx;
    if (!tight && dp[prev][rem][lz] != -1) return dp[prev][rem][lz];

    int ub = tight ? str[idx] - '0' : 9;
    ll res = 0;

    for (int dig = 0; dig <= ub; dig++) {
        if (!lz && dig == prev) continue;
        res += dpf(str, dig, idx + 1, tight && (dig == ub), lz && (dig == 0));
    }

    if (!tight) dp[prev][rem][lz] = res;
    return res;
}

ll solve(ll a, ll b) {
    string l = to_string(a - 1);
    string r = to_string(b);
 
    ll ans_l = (a == 0) ? 0 : dpf(l, 10, 0, 1, 1);
    ll ans_r = dpf(r, 10, 0, 1, 1);
    
    return ans_r - ans_l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    ll a, b; cin >> a >> b;
    
    cout << solve(a, b) << endl;
    return 0;
}

//! This below also works and is logically easy-going
// // prev, idx, tight, lz
// #include <bits/stdc++.h>
// using namespace std;
 
// typedef long long ll;
 
// ll dp[11][19][2][2];
 
// ll dpf(string& str, int prev, int idx, bool tight, bool lz) {
//     if(idx == str.size()) return 1;
 
//     if(dp[prev][idx][tight][lz] != -1) return dp[prev][idx][tight][lz];
 
//     int ub = (tight) ? str[idx] - '0' : 9;
 
//     ll res = 0;
//     for(int dig = 0; dig <= ub; dig++) {
//         if(dig == prev && !lz) continue;
 
//         res += dpf(str, dig, idx + 1, ((tight && dig == ub) ? 1 : 0), ((lz && dig == 0) ? 1 : 0));
//     }
    
//     return dp[prev][idx][tight][lz] = res;
// }
 
// ll solve(ll a, ll b) {
//     string l = to_string(a - 1);
//     string r = to_string(b);
 
//     // reset for each a and b for fresh DP table.
//     memset(dp, -1, sizeof(dp));
//     ll ans_l = dpf(l, 0, 0, 1, 1);
//     memset(dp, -1, sizeof(dp));
//     ll ans_r = dpf(r, 0, 0, 1, 1);
 
//     return ans_r - ans_l;
// }
 
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
 
    
//     ll a, b; cin >> a >> b;
//     cout << solve(a, b) << endl;
//     return 0;
// }