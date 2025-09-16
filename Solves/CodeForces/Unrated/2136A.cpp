#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int a, b, c, d; cin>>a>>b>>c>>d;
        c-=a, d-=b;

        if(max(a,b) > 2*min(a, b) + 2 || max(c,d) > 2*min(c,d) + 2) cout<<"NO";
        else cout<<"YES";
        cout<<endl;
    }
}