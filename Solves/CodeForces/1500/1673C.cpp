#include <bits/stdc++.h>
using namespace std;

const int MAXN = 40000;
const int MOD = 1000000007;

vector<int> palindromes;
// dp[target_sum][num_palindromes]
// Rows: 0 to 40000, Columns: 0 to 498
long long dp[MAXN + 1][500];

void precompute() {
    // 1. Generate palindromes
    for (int i = 1; i <= MAXN; i++) {
        string s = to_string(i);
        string rs = s;
        reverse(rs.begin(), rs.end());
        if (s == rs) palindromes.push_back(i);
    }

    int M = palindromes.size();

    // 2. Base Case: 
    // For a target sum of 0, there is 1 way (using no palindromes) 
    // across all palindrome counts.
    for (int i = 0; i <= M; i++) dp[0][i] = 1;
    for (int i = 0; i <= MAXN; i++) dp[i][0] = 0;

    // 3. Fill the table
    // j = current target sum
    for (int j = 1; j <= MAXN; j++) {
        // i = number of palindromes considered (1 to M)
        for (int i = 1; i <= M; i++) {
            int p = palindromes[i - 1]; // current palindrome value
            // Option 1: Don't use the i-th palindrome
            // We take the ways from the previous column (same sum)
            dp[j][i] = dp[j][i - 1];
            // Option 2: Use the i-th palindrome (if it fits)
            if (j >= p) 
                dp[j][i] = (dp[j][i] + dp[j - p][i]) % MOD;
            // We add the ways from the current column, but at row (j - p)
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t; 
    if (!(cin >> t)) return 0;
    while(t--) {
        int n; 
        cin >> n;
        // The answer is the entry for sum n using all M palindromes
        cout << dp[n][palindromes.size()] << "\n";
    }
    return 0;
}

// #include <bits/stdc++.h>
// #define MOD 1000000007
// using namespace std;

// vector<int> palindromes;
// vector<long long> dp(40000 + 1, 0);

// void precompute() {
//     for (int i = 1; i <= 40000; i++) {
//         string s = to_string(i);
//         string rs = s;
//         reverse(rs.begin(), rs.end());
//         if (s == rs) palindromes.push_back(i);
//     }

//     dp[0] = 1;
//     for (int p : palindromes) 
//         for (int j = p; j <= 40000; j++) 
//             dp[j] = (dp[j] + dp[j - p]) % MOD;
// }
// ! If you reverse the inner-outer loop order, you get count of permutations, not combinations like now
// ! If you reverse the loop direction of j, problem will become 0/1 knapsack instead of unbound

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     precompute();

//     int t; cin >> t;
//     while(t--) {
//         int n; cin >> n;
//         cout << dp[n] << endl;
//     }
// }
