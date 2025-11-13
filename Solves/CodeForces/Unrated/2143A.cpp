#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> p(n);
        vector<int> idx(n+1);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
            idx[p[i]] = i;
        }

        int frontptr = idx[n] + 1; // may be == n
        int backptr = idx[n] - 1;  // may be == -1
        int curr = n;
        bool isPossible = true;

        while(curr > 1) {
            if(backptr >= 0 && p[backptr] == curr - 1) {
                backptr--;
                curr--;
                continue;
            }
            if(frontptr < n && p[frontptr] == curr - 1) {
                frontptr++;
                curr--;
                continue;
            }
            cout << "NO" << endl;
            isPossible = false;
            break;
        }

        if(isPossible) cout << "YES" << endl;
    }
}