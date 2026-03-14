#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool inversion(const vector<int>& a) {
    for(int i = 1; i < a.size(); i++) if(a[i] < a[i - 1]) return false;
    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(auto& e : a) cin >> e;
    if(!inversion(a)) { cout << 0 << endl; return; }

    int mini = INT_MAX;
    for(int i = 1; i < n; i++) mini = min(mini, (a[i] - a[i - 1])/2 + 1);
    
    cout << mini << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t; while(t--) solve();

    return 0;
}