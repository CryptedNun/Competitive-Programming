#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
    
        // Pass to check if there is a length-3 contiguous subarray with all '.'s
        bool doesSubarrayExist = false;
        for(int i = 0; i <= n - 3; i++) {
            if(s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.') {
                doesSubarrayExist = true;
                break;
            }
        }

        if(doesSubarrayExist) cout << 2 << endl;
        else {
            cout << count(s.begin(), s.end(), '.') << endl;
        }
    }
}