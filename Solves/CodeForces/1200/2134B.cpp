#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        long long n, k; cin>>n>>k;
        vector<long long> a(n);
        for(int i=0; i<n; i++) cin>>a[i];

        if(k%2 == 1) {
            for(int i=0; i<n; i++) (a[i] % 2 == 0) ? cout << a[i] << " " : cout << a[i]+k << " ";
        } else {
            for(int i=0; i<n; i++) cout << a[i] + k*(a[i] % (k+1)) << " ";
        }
        cout<<endl;
    }
}