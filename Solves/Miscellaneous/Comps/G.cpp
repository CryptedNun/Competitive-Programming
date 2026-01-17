#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    long long mat[n][n];
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];

    long long ans[n][n];
    ans[0][0] = mat[0][0];
    for(int i = 1; i < n; i++) {
        ans[0][i] = mat[0][i] - mat[0][i - 1];
        ans[i][0] = mat[i][0] - mat[i - 1][0];
    }

    for(int i = 1; i < n; i++) 
        for(int j = 1; j < n; j++) 
            ans[i][j] = mat[i][j] + mat[i - 1][j - 1] - mat[i - 1][j] - mat[i][j - 1];

    long long total = 0;
    for(int i = 0; i < n; i++) total += ans[i][i];

    if(total != 0) ans[0][0] -= total;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}