#include <bits/stdc++.h>
using namespace std;

int lastDigitPow(int base, int power) {
    base %= 10;
    int result = 1;
    while(power > 0) {
        if(power & 1) result = result*base % 10;
        base = base*base % 10;
        power >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int a,b; cin>>a>>b;
        cout<<lastDigitPow(a, b)<<endl;
    }
}