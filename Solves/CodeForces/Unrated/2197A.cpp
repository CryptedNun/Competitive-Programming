#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int d(ll n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int t; cin >> t;
    while(t--)
    {
        ll x; cin >> x;
        if (x % 9 != 0) {
            cout << 0 << endl;
            continue;
        }

        int count = 0;
        for (int s = 0; s <= 200; ++s) {
            ll y = x + s;
            if (d(y) == s) count++;
        }

        cout << count << endl;
    }

    return 0;
}