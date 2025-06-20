// TODO : This method still isn't complete, we aren't accounting for the lines not entirely adjacent to the border in the general approach

#include <bits/stdc++.h>
using namespace std;

long long nC3 (long long n) {
    if(n < 3) return 0;
    return (n*(n-1)*(n-2))/6;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long m, n;
    while(true) {
        cin>>m>>n;
        if(m == 0 || n == 0) break;

        //! Reduce the degen triangles along the vertical and horizontal lines.
        long long totalTriangles = nC3((m+1)*(n+1)) - ((m+1)*nC3(n+1) + (n+1)*nC3(m+1));

        //* Rotate the grid, keep bigger dimension at first to iterate over
        if(m < n) swap(m,n); 

        long long degenTriangles = 0;

        //* Count positive diagonals (First general approach)
        for(long long dx = 2; dx <= m; dx++) {
            for(long long dy = 2; dy <= n; dy++) {
                if(__gcd(dx, dy) != 1) {
                    long long points = __gcd(dx, dy) + 1;
                    degenTriangles += 2LL * nC3(points);
                }
            }
        }

        //* Account for the unslided overcount or undercount
        for(long long dx = 2; dx <= m; dx++) {
            if(__gcd(dx, n) != 1) {
                long long number = m - (__gcd(dx, n) - 1);
                number -= 2; //* Account only for the missed ones, so we reduce the 2 cases we calculated in the general appraoch
                degenTriangles += (number * nC3(__gcd(dx, n) + 1));
            }
        }

        //* Twice to account for negative slope (mirror symmetry)
        degenTriangles *= 2;

        cout << totalTriangles - degenTriangles << endl;
    }
}