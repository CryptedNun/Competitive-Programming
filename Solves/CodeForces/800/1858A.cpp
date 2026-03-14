#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
 
void solve() {
    long long a, b, c; cin >> a >> b >> c;
    if(c % 2 == 0) { cout << (a > b ? "First" : "Second") << endl; }
    else { cout << (b > a ? "Second" : "First") << endl; }
}
 
int main() {
    int t; cin >> t;
    while(t--) solve();
    
    return 0;
}