#include <bits/stdc++.h>
using namespace std;

// ! Returns the GCD, but the last two passed variables store x and y for a and b respectively
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n; cin>>m>>n;
    int x, y; 
    cout<<gcd(m, n, x, y)<<endl;
    cout<<x<<" "<<y<<endl;
}