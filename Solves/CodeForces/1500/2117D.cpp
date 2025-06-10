#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> v(n);
        for(long long i=0; i<n; i++) cin>>v[i];

        long long num = 2 * v[0] - v[1];
        long long den = n+1;
        if(num%den != 0) {
            cout<<"NO"<<endl;
            continue;
        } 
        
        long long y = num / den;
        long long x = v[0] - y * n;
        if(x < 0 || y < 0) {
            cout<<"NO"<<endl;
            continue;
        }

        bool ok = true;
        for(long long i=2; i<n; i++) {
            long long index = i+1;
            long long value = x*index + y*(n-index+1);
            if(value != v[i]) {
                ok = false;
                break;
            }
        }

        cout<<(ok ? "YES" : "NO")<<endl;
    }
}