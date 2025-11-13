#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >>t;
    while(t--) {
        int n; cin >>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
    
        bool isPossible = false;
        for(int i = 1; i < n; i++) {
            if(a[i] < a[i - 1]) {
                cout << "YES" << endl;
                cout << 2 << endl;
                cout << a[i - 1] << " " << a[i] << endl;

                isPossible = true;
                break;
            }
        }

        if(!isPossible) cout << "NO" << endl;
    }
}