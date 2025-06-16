#include <bits/stdc++.h>
using namespace std;

// ! Returns the prime factors of n
vector<long long> trial_division1(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long input; cin>>input;

    vector<long long> vec = trial_division1(input);
    for(long long& num:vec) cout<<num<<" ";
}