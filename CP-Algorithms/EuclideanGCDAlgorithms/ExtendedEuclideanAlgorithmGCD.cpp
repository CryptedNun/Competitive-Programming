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

// ! ITERATIVE VERSION [FASTER]
// ! THIS ALSO CALCULATES FOR MINIMUM |x| + |y|, AND IF MULTIPLE SUCH INSTANCES THEN X<=Y
// int gcd(int a, int b, int& x, int& y) {
//     x = 1, y = 0;
//     int x1 = 0, y1 = 1, a1 = a, b1 = b;
//     while (b1) {
//         int q = a1 / b1;
//         tie(x, x1) = make_tuple(x1, x - q * x1);
//         tie(y, y1) = make_tuple(y1, y - q * y1);
//         tie(a1, b1) = make_tuple(b1, a1 - q * b1);
//     }
//     return a1;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n; cin>>m>>n;
    int x, y; 
    cout<<gcd(m, n, x, y)<<endl;
    cout<<x<<" "<<y<<endl;
}