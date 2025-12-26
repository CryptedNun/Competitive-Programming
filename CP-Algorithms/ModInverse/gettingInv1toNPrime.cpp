#include <bits/stdc++.h>
#define M 7                 // For example, here we used 7, there can be any prime.
using namespace std;

vector<long long> inv(400 + 1, 0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Recursive relation:
    // inv[i] = i^-1 MOD M
    // inv[i] = (M - M/i) * inv[M % i] (MOD M)
    // This is valid for 2 <= i < P
    // For i > P, inv[i] = inv[i % P]
    // ! Base case: Starts with inv[1] = 1; for convenience, inv[i] = 0 means no inverse exists of i.
    inv[0] = 0;
    inv[1] = 1;

    for(int i = 2; i <= 400; i++) {
        if(i % M == 0) inv[i] = 0;
        else if(i >= 2 && i < M) inv[i] = ((M - M/i) * inv[M % i]) % M;
        else if(i > M) inv[i] = inv[i % M];
    }

    for(int i = 0; i <= 400; i++) {
        cout << i << ": ";
        if(inv[i] == 0) cout << "No inverse exists" << '\n';
        else cout << inv[i] << '\n';
    }
}