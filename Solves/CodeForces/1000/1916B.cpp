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

// ! One thing to note, the first case doesn't work for all a and b. 
// ! Suppose 15 and 30, gives 60. But 30 and 20 are its biggest divisors. Hence for 15 and 30, no such x exists.