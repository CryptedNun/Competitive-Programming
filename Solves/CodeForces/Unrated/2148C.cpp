#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin>>a[i]>>b[i];

        long long ans = 0;
        // for i == 0
        // start from 0 0, go to a[0] b[0]
        if(a[0] % 2 == 0) {
            if(b[0] == 0) ans += a[0];
            else ans += a[0] - 1;
        } else {
            if(b[0] == 1) ans += a[0]; 
            else ans += a[0] - 1;
        }
        
        // for mid values
        for(int i=1; i<n; i++) {
            if((a[i] - a[i-1]) % 2 == 0) {
                if(b[i-1] == b[i]) ans += a[i] - a[i-1];
                else ans += a[i] - a[i-1] - 1;
            }
            else {
                if(b[i-1] == b[i]) ans += a[i] - a[i-1] - 1;
                else ans += a[i] - a[i-1];
            }
            
        }

        // for end value
        if(a[n-1] != m) {
            // go from a[n-1] b[n-1] to m whatever
            ans += m-a[n-1];
        }
        
        cout<<ans<<endl;
    }
}