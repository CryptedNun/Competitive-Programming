// state: idx, prefmax, suff.
// Track: {steps, underflow}
// ! THIS IS NOT COMPLETE, 
// ! the logic is so far correct, but it cannot be memoized due to large "suff" 
// ! dp state "suff" needs to be opted for "underflow" instead for memoization, this will require logical restructure
// ! Basically this is a faster solution to the easier version

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power10[20];

pair<ll, int> solve(string& s, int idx, int prefMax, ll suff) {
    // Base case
    if(idx == s.size() - 1) {
        // return {steps, underflow}
        int currDigit = suff;
        return {1, currDigit - max(prefMax, currDigit)};
    }

    int currDigit = suff / power10[s.size() - idx - 1];   // Will go from currD to 0
    ll suffix = suff % power10[s.size() - idx - 1];
    ll steps = 0;
    ll underflow;
    while(currDigit >= 0) {
        int prefixMax = max(prefMax, currDigit);          // init it with max(currDigit, prefMax).
        auto res = solve(s, idx + 1, prefixMax, suffix);

        steps += res.first;
        // If returned underflow is negative, currDigit--, but if idx == 0 && currDigit == 0 then stop; Prepare next suffix with that.
        underflow = res.second;
        if(underflow < 0) {
            suffix = power10[s.size() - idx - 1] + underflow;
            currDigit--;
        } else if(underflow == 0 && prefixMax != 0) {
            suffix = 0;
        } else if(underflow == 0 && prefixMax == 0) { break; }
    }

    return {steps, underflow};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    power10[0] = 1;
    for(ll i = 1; i < 20; i++) power10[i] = 10 * power10[i - 1];

    ll n; cin >> n;
    string s = to_string(n);
    cout << solve(s, 0, 0, n).first << endl;
}