#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int p_pow(int n) {
    int prime = 0;
    for(int i = 2; i * i <= n; i++) if(n % i == 0) { prime = i; break; }
    if(prime == 0) prime = n;

    while(n > 1) {
        if(n % prime != 0)
            return -1;
        n /= prime;
    }
    return prime;
}

bool isNonDec(const vector<int>& a) {
    for(int i = 1; i < a.size(); i++) 
        if(a[i] < a[i - 1]) {
            return false;
        }

    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto& e : a) cin >> e;

    // ! 1. isNonDec() ?
    if(isNonDec(a)) {
        cout << "Bob" << endl;
        return;
    }

    vector<int> primes(n);
    for(int i = 0; i < n; i++) {
        int curr = primes[i] = p_pow(a[i]);
        // ! 2. Check if any number can be divided by two primes.
        if(curr == -1) {
            cout << "Alice" << endl;
            return;
        }
    }
    
    if(isNonDec(primes)) cout << "Bob" << endl;
    else cout << "Alice" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}