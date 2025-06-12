#include <bits/stdc++.h>
using namespace std;

// gdc(a, b) = gcd(b, a%b);
int gcd(int a, int b) {
    while(b != 0) {
        int temp = a;
        a = b;
        b = temp%b;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n; cin>>m>>n;
    cout<<gcd(m, n);
}

// ! lcm(a,b) * gcd(a,b) = a*b;