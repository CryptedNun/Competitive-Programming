// * O(nlogn);

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int count = 0;

    for (int m = 2; 2*m*(m+1) <= n; m++) { // minimum r=1
        for (int r = 1; r < m; r++) {
            if ((m - r) % 2 == 1 && __gcd(m,r) == 1) {
                int P = 2*m*(m+r);
                if (n % P == 0) {   // multiple fits exactly into n
                    int k = n / P;
                    count++; // each primitive or scaled triple counts as 1
                }
            }
        }
    }

    cout << count << "\n";
}