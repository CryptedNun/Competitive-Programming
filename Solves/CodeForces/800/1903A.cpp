#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        bool isNonDecreasing = true;
        for(int i = 1; i < n; i++) 
            if(a[i] < a[i - 1]) {
                isNonDecreasing = false; 
                break;
            }


        if(k == 1 && !isNonDecreasing) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}