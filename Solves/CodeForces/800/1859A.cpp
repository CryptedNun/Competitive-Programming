#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto& e : a) cin >> e;

    sort(a.begin(), a.end());

    int idx = 0;
    while(idx + 1 < n && a[idx] == a[idx + 1]) idx++;
    if(idx + 1 == n) {
        cout << -1 << endl;
        return;
    }
    
    cout << (idx + 1) << " " << n - (idx + 1) << endl;
    for(int i = 0; i <= idx; i++) cout << a[i] << " ";
    cout << endl;
    for(int i = idx + 1; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}