#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        long long x; cin>>x;

        int k = to_string(x).length();
        if(x == binpow(10, k) - 1) {
            cout<<9*binpow(10, k)<<endl;
        } else if(x >= 9*binpow(10, k-1)) {
            cout<<binpow(10, k+1) - 1 - x<<endl;
        } else {
            cout<<binpow(10, k) - 1 - x<<endl;
        }
    }
}