#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(vector<int>& arr, string& s, int idx, bool tight, bool lz) {    
    if(idx == s.size()) return 1;

    int ub = tight ? s[idx] - '0' : 9;
    ll res = 0;
    for(int digit = 0; digit <= ub; digit++) {
        if(binary_search(arr.begin(), arr.end(), digit) || (digit == 0 && lz)) {
            res += solve(arr, s, idx + 1, (tight && (digit == ub)), (lz && (digit == 0)));
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int size; cin >> size;
    vector<int> vec(size);
    for(auto& element : vec) cin >> element;

    ll n; cin >> n;
    string s = to_string(n);
    int first_digit = s[0] - '0';

    cout << solve(vec, s, 0, 1, 1) - 1 << endl;
}