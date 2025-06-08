#define MOD 1000000007

class Solution {
public:
    long long binpowmod(long long base, long long power) {
        base %= MOD;
        long long result = 1;
        while(power > 0) {
            if(power & 1) result = result * base % MOD;
            base = base * base % MOD;
            power >>= 1;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long oddPositions = n / 2;
        long long evenPositions = n - oddPositions;
        return (binpowmod(4, oddPositions) * binpowmod(5, evenPositions)) % MOD;
    }
};