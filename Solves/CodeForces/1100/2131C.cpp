#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int n, k; cin>>n>>k;
        vector<int> s(n);
        for(int i=0; i<n; i++) cin>>s[i];
        vector<int> t(n);
        for(int i=0; i<n; i++) cin>>t[i];

        for(int i=0; i<n; i++) {
            s[i] = min(s[i]%k, (k - s[i]%k)%k);
            t[i] = min(t[i]%k, (k - t[i]%k)%k);
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        bool isPossible = true;
        for(int i=0; i<n; i++) 
            if(s[i] != t[i]) {
                isPossible = false;
                break;
            }
    
        if(isPossible) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}