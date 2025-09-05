#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)        // if b is odd
            res *= a;
        a *= a;           // square the base
        b >>= 1;          // divide b by 2
    }
    return res;
}

long long sum(long long n) {
    if(n<10) {
            int sum = 0;
            for(int i=1; i<=n; i++) sum += i;
            return sum;
        }

        long long noOfDigits = to_string(n).size();

        // LSD Case Calculation
        long long LSDsum = 0;
        long long higherLSD = n/10;
        long long LSD = n%10;
        for(int i=1; i<=9; i++) {
            if(i <= LSD) 
                LSDsum += i*(higherLSD+1);
            else 
                LSDsum += i*higherLSD;
        }

        // MSD Case Calculation
        long long MSDsum = 0;
        long long lowerMSD = n % binpow(10, noOfDigits-1);
        long long MSD = n / binpow(10, noOfDigits-1);
        for(int i=1; i<=MSD; i++) {
            if(i<MSD) 
                MSDsum += i*binpow(10, noOfDigits-1);
            else 
                MSDsum += i*(lowerMSD+1);
        }

        // mid Digits calculation
        long long midSum = 0;
        long long tenPosPower = 10;
        long long positionDigit = (n % (tenPosPower*10)) / tenPosPower;
        long long rightCarry = n % tenPosPower;
        long long leftCarry = n / (tenPosPower*10);
        while(tenPosPower < binpow(10, noOfDigits-1)) {
            for(int i=1; i<=9; i++) {
                if(i < positionDigit) midSum += i*((leftCarry+1)*tenPosPower);
                else if(i == positionDigit) midSum += i*(rightCarry+1 + leftCarry*tenPosPower);
                else midSum += i*(leftCarry*tenPosPower);
            }

            tenPosPower *= 10;
            positionDigit = (n % (tenPosPower*10)) / tenPosPower;
            rightCarry = n % tenPosPower;
            leftCarry = n / (tenPosPower*10);
        }

        long long totalSum = MSDsum + LSDsum + midSum;
        return totalSum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        // ! Compute the number before from given k.
        long long k; cin>>k;
        long long digitCount = 1;
        long long lowerBound, upperBound;
        lowerBound = 1;
        upperBound = 9;
        while(!(k>=lowerBound && k<=upperBound)) {
            digitCount++;
            lowerBound = upperBound+1;
            upperBound = upperBound + 9*digitCount*binpow(10, digitCount-1);
        }
        
        long long smallestNumber = binpow(10, digitCount-1);
        long long targetNumber = smallestNumber + (k-lowerBound)/digitCount;
        long long digitIdx = (k-lowerBound)%digitCount;

        long long summation = sum(targetNumber-1);
        string stringifiedTargetNumber = to_string(targetNumber);
        for(int i=0; i <= digitIdx; i++) {
            summation += stringifiedTargetNumber[i] - '0';
        }

        cout<<summation<<endl;
    }
}