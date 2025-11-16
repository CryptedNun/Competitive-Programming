#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> xIdx(n + 1);
    xIdx[0] = -1;
    for(int i = 0; i < n; i++) {
        int input; cin >> input;
        xIdx[input] = i;
    }

    int rounds = 1;
    for(int i = 1; i <= n; i++) {
        if(xIdx[i] > xIdx[i + 1] && i != n) rounds++;
    }

    cout << rounds << endl;
}