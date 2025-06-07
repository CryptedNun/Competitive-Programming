#include <bits/stdc++.h>
using namespace std;
long long binexp(int base, int power);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n; cin>>m>>n;
    cout<<binexp(2, 7);
}

// * Binary Exponentiation: Time Complexity = O(log(n)), where n is the power.
long long binexp(int base, int power) {
    long long result = 1;
    while(power > 0) {
        if(power&1) result = result * base;
        base = base*base;
        power >>=1;
    }
    return result;
}

// ! 7(10) = 111(2);
// ! 2^7 = 2^(111(2)) = 2^(100 + 10 + 1 (2));
// !     = 2^4 * 2^2 * 2^1;
// ! Base is squared after each term, from right to left; Hence we do base = base*base.
// ! [Bitwise operation, if bit is 1, its added to result, otherwise ignored]