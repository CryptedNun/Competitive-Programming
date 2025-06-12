// ! This isn't necessary to learn if you are a beginner. Don't sweat it. This function is already built-in in C++17 onwards.
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n; cin>>m>>n;
    cout<<gcd(m, n);
}