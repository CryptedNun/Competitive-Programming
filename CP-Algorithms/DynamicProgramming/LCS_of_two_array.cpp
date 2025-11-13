#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int& element : a) cin >> element;
    for(int& element : b) cin >> element;

    // ----------------------------------------------------------------------------------------------------
    // ! Define DP[i][j] = length of LCS considering first i elements of a and first j elements of b
    // ! If a[i] == b[j] meaning arr1_i and arr2_j are common, then DP[i + 1][j + 1] = DP[i][j] + 1
    // ! else DP[i + 1][j + 1] = max(DP[i][j + 1], DP[i + 1][j])
    // * Keep in mind, here i, j are used as 0-based indices of the two arrays, i: 0->n, j: 0->m
    // * Base case: DP[0][j] = DP[i][0] = 0, which is obvious
    // ----------------------------------------------------------------------------------------------------

    int DP[n + 1][m + 1];
    for(int i = 0; i < n; i++) DP[i][0] = 0;
    for(int j = 0; j < m; j++) DP[0][j] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i] == b[j]) DP[i + 1][j + 1] = DP[i][j] + 1;
            else DP[i + 1][j + 1] = max(DP[i][j + 1], DP[i + 1][j]);
        }
    }

    cout << DP[n][m] << endl;

    // ----------------------------------------------------
    // ? LCS Construction with backtracking + two-pointers:
    // ----------------------------------------------------
    
    vector<int> LCS;
    int firstptr = n, secondptr = m;
    while(firstptr >= 1 && secondptr >= 1) {
        if(a[firstptr - 1] == b[secondptr - 1]) {
            LCS.push_back(a[firstptr - 1]);
            firstptr--, secondptr--;
        } else {
            if(DP[firstptr][secondptr - 1] >= DP[firstptr - 1][secondptr]) secondptr--;
            else firstptr--;
        }
    }

    reverse(LCS.begin(), LCS.end());
    for(auto& element : LCS) cout << element << " ";
}