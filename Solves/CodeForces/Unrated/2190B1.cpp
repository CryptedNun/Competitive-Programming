#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> nxt(n, -1);
    int last_open = -1;
    for (int k = n - 1; k >= 0; --k) {
        nxt[k] = last_open;
        if (s[k] == '(') last_open = k;
    }

    vector<int> totalOpensAfter(n + 1, 0);
    totalOpensAfter[n - 1] = 0;
    for (int k = n - 2; k >= 0; --k) totalOpensAfter[k] = totalOpensAfter[k + 1] + (s[k + 1] == '(');
    
    int max_length = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == ')') {
            int j = nxt[i];
            if (j != -1 && totalOpensAfter[j] >= (j - i)) {
                int current_length = n - 2 * (j - i);
                max_length = max(max_length, current_length);
            }
        }
    }

    cout << max_length << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}