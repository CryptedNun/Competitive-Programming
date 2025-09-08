#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int k, x; cin>>k>>x;
        for(int i=1; i<=k; i++) {
            x *= 2;
        }

        cout<<x<<endl;
    }
}