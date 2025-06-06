// ! Concept: Interval Overlapping, String Manipulation, Arithmetic Series, Basic Number Theory 


#include <bits/stdc++.h>
using namespace std;
 
long long nextSame(long long n);
long long prevSame(long long n);
long long intPow10(int power);
long long countSameFirstLast(long long a, long long b);
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    long long l, r; cin>>l>>r;
 
    int l_c = to_string(l).size();
    int r_c = to_string(r).size();
    long long sum = 0;
    
    if(r_c - l_c - 1 > 0) {                      // Add the numbers within the range (exclusively) directly
        for (int d = l_c + 1; d < r_c; ++d) {
            long long add = 9 * pow(10, d-2);    // Formula for each block of d many digits: 9*10^(d-2)
            sum += add;
        }
    }
 
    if(l_c == r_c) { 
        sum += countSameFirstLast(l, r);
    } else {
        // Evaluate the upper portion: From l to l_c's maximum number
        sum += countSameFirstLast(l, pow(10, l_c) - 1);
        // Evaluate the lower portion: From r_c's minimum number to r
        sum += countSameFirstLast(pow(10, r_c - 1), r);
    }
 
    cout<<sum<<endl;
}
 
long long countSameFirstLast(long long a, long long b) {    // ! This is STRICTLY for equal lengths of a,b
    int size = to_string(a).size();                                   // ! Evaluate the length
    long long count = 0;
    long long pow10_1 = pow(10, size - 1);
    long long pow10_2 = pow(10, size - 2);
 
    if(size == 1) return b-a+1;                             // ! Edge case for single digit numbers.
 
    for(int d=1; d<=9; d++) {
        long long low = d * pow10_1 + d;
        long long high = d * pow10_1 + d + 10 * (pow10_2 - 1);
 
        long long lowerLimit = max(low, nextSame(a));       // ! Clamp the interval
        long long upperLimit = min(high, prevSame(b));
 
        if(lowerLimit>upperLimit) continue;                 // ! Continue if no interval
        count += (upperLimit - lowerLimit)/10 + 1;
    }
    
    return count;
}
 
long long nextSame(long long n) {               // ! Helper Function 1
    while(true) {
        string str = to_string(n);
        if(str.front() == str.back()) return n;
        n++;
    }
}
 
long long prevSame(long long n) {               // ! Helper Function 2
    while(true) {
        string str = to_string(n);
        if(str.front() == str.back()) return n;
        n--;
    }
}
 
long long intPow10(int power) {                 // ! Helper function 3
    long long result = 1;                       // ! I didn't use Binary Exponentiation because for some reason it was casuing an overflow for large inputs, although it could be fixed by using unsigned long long. I just opted for the naive method instead.
    while (power--) result *= 10;
    return result;
}