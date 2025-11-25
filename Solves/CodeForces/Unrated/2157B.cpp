#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n, x, y; cin >> n >> x >> y;
        string str; cin >> str;

        x = abs(x), y = abs(y);
        int a = (int)count(str.begin(), str.end(), '4');
        int b = (int)count(str.begin(), str.end(), '8');
        if(a + 2*b >= x + y && a + b >= max(x, y)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}