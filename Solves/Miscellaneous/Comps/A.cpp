#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n); for(int& elem : a) cin >> elem;

    int max = 0;
    for(int& elem : a) if(elem > max) max = elem;

    int cnt = 0;
    for(int& elem : a) if(elem < max) cnt++;

    cout << cnt << '\n';
}