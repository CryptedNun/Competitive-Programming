#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        long long a,b; cin>>a>>b;
        if(b % a == 0) {
            cout<<b*b/a<<endl;
        } else {
            cout<<a*b/__gcd(a,b)<<endl;
        }
    }
}