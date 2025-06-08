#include <bits/stdc++.h>
using namespace std;
long long binexpmod(int base, int power, int mod = 1000);
int leading3DigitsOfPower(int base, int power);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int m, n; cin>>m>>n;

        // * Leading Digits: Break down the number in scientific notation. 
        // * (m^n = d * 10^k; where d is 1<=d<10, and k is a non-negative integer)
        int leading3Digits = leading3DigitsOfPower(m, n);

        // * Trailing Digits: Use binary exponentiation modulo
        long long trailing3Digits = binexpmod(m, n);

        // * One Subtle Detail: Fill the trailing 3 digits with leading zeros, if the modulo is less than 100 
        cout << leading3Digits << "...";
        cout << setw(3) << setfill('0') << trailing3Digits << '\n';
    }
}

// ! Set default value of mod to 1000, for getting last 3 digits
long long binexpmod(int base, int power, int mod) {
    base %= mod;
    long long result = 1;
    while(power > 0) {
        if(power&1) result = result*base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return result;
}

// ! Extracts the leading 3 digits, by converting power to mantissa and exponent form.
int leading3DigitsOfPower(int base, int power) {
    double log = power*log10(base);
    double logFraction = log - (int)log;
    double outputMantissa = pow(1.0*10, logFraction);

    return (int)(outputMantissa*100);
}