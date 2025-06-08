#include <bits/stdc++.h>
using namespace std;
long long binpow(long long base, int power);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    long long adjacentCount = 2 * 3 * binpow(4ll, n-2);
    long long middleCount = (n-3) * binpow(3ll, 2) * binpow(4ll, n-3);
    cout << adjacentCount + middleCount << endl;
}

long long binpow(long long base, int power) {
    long long result = 1;
    while(power > 0) {
        if(power & 1) result *= base;
        base *= base;
        power >>= 1;
    }
    return result;
}