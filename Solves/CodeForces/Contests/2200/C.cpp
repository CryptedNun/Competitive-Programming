#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool canWin(string s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop(); // They "cancel out" because the inside is already clear
        } else {
            st.push(c);
        }
    }
    return st.empty();
}

void solve() {
    int n; cin >> n;
    string str; cin >> str;

    cout << (canWin(str) ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}