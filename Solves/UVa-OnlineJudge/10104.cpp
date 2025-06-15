#include <bits/stdc++.h>
using namespace std;

// ! Returns the GCD, but the last two passed variables store x and y for a and b respectively
int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n; 
    while(cin>>m>>n) {
        int x, y;
        int d = gcd(m, n, x, y);
        cout<<x<<" "<<y<<" "<<d<<endl;
    }
}