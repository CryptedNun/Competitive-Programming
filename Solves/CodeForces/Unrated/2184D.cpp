#include <bits/stdc++.h>
using namespace std;

long long C[62][62];
void precompute() {
    for (int i = 0; i < 62; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
}

void solve() {
    long long n, k; cin >> n >> k;
    // Find d such that n = 2^d
    int d = 0;
    long long temp = n;
    while (temp > 1) {
        temp >>= 1;
        d++;
    }

    long long alice_wins = 0;

    // Case 1: Highest bit at position i (where 1 <= i <= d)
    for (int i = 1; i <= d; i++) {
        // M(a) = i + j, where j is the number of other set bits
        // We need i + j <= k  =>  j <= k - i
        int max_j = k - i;
        if (max_j < 0) continue;
        
        for (int j = 0; j <= min((int)i - 1, max_j); j++) alice_wins += C[i - 1][j];
    }

    // Case 2: a = n (which is 2^d)
    // M(2^d) = d + 1
    if (d + 1 <= k) alice_wins += 1;
    cout << n - alice_wins << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();
    int t; cin >> t;
    while (t--) solve();
    return 0;
}



// #include <iostream>
// #include <vector>
// using namespace std;

// long long C[62][62];

// void precompute() {
//     for (int i = 0; i < 62; i++) {
//         C[i][0] = 1;
//         for (int j = 1; j <= i; j++) C[i][j] = C[i-1][j-1] + C[i-1][j];
//     }
// }

// void solve() {
//     long long n, k; cin >> n >> k;

//     // Find d such that n = 2^d
//     int d = 0;
//     long long temp = n;
//     while (temp > 1) {
//         temp >>= 1;
//         d++;
//     }

//     long long alice_wins = 0;

//     // Case 1: Highest bit at position i (where 1 <= i <= d)
//     for (int i = 1; i <= d; i++) {
//         // M(a) = i + j, where j is the number of other set bits
//         // We need i + j <= k  =>  j <= k - i
//         int max_j = k - i;
//         if (max_j < 0) continue;
        
//         for (int j = 0; j <= min((int)i - 1, max_j); j++) {
//             alice_wins += C[i - 1][j];
//         }
//     }

//     // Case 2: a = n (which is 2^d)
//     // M(2^d) = d + 1
//     if (d + 1 <= k) alice_wins += 1;

//     cout << n - alice_wins << endl;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     precompute();
//     int t; cin >> t;
//     while (t--) solve();

//     return 0;
// }