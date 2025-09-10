#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];

        long long ans = 0;
        for(int i=0; i<n; i++) ans += ((i+1) % 2 == 1) ? a[i] : -a[i];

        long long r_lMax = (n%2 == 0) ? n-2 : n-1;
        // cout<<ans<<endl;

        int minOdd_l = 0; // for even r's
        int minEven_l = 1; // for odd r's
        int del = 0;
        for(int r=1; r<n; r++) {
            if((r+1) % 2 == 0) {
                // r is even
                // l is odd
                del = max(del, 2*(a[r] - a[minOdd_l]) + (r - minOdd_l));
                if(r - 2*a[r] < minEven_l - 2*a[minEven_l]) minEven_l = r;
            } else {
                // r is odd
                // l is even
                del = max(del, 2*(a[minEven_l] - a[r]) + (r - minEven_l));
                if(r + 2*a[r] < minOdd_l + 2*a[minOdd_l]) minOdd_l = r;
            }

            // cout<<r<<" "<<del<<endl;
            // cout<<minOdd_l<<endl;
            // cout<<minEven_l<<endl;
            // cout<<endl;
            // // cout<<r<<" "<<del<<" "<<endl;
        }

        cout<<max(ans + r_lMax, ans + del)<<endl;
    }
}