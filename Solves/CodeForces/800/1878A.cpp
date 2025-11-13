#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++) cin >> a[i], freq[a[i]]++;

        if(freq[k] == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}