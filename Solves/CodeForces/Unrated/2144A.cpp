#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(auto& element : a) cin >> element;

        if(accumulate(a.begin(), a.end(), 0) % 3) cout << 0 << " " << 0 << endl;
        else cout << 1 << " " << 2 << endl;
    }
}