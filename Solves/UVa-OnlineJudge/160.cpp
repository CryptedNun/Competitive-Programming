#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimesUpTo(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true) {
        int n; cin >> n;
        if(n == 0) break;

        vector<int> primes = getPrimesUpTo(n);
        vector<int> freq(primes.size(), 0);

        //! Legendre's formula
        for(int i = 0; i < primes.size(); i++) {
            int p = primes[i], temp = n;
            while(temp) {
                freq[i] += temp / p;
                temp /= p;
            }
        }

        //* Output formatting
        cout << setw(3) << n << "! =";
        for(int i = 0; i < freq.size(); ++i) {
            if(i > 0 && i % 15 == 0) cout << "\n      "; // indent continuation lines
            cout << setw(3) << freq[i];
        }
        cout << '\n';
    }
}