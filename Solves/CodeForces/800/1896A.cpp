// ? This one's good!
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> vec(n);
        for(int i = 0; i < n; i++) cin >> vec[i];

        if(vec[0] == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}