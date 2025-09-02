// * Time Complexity to get all primTriples and multTriples: O(nlogn);
// * O(n) may be possible if we use sieving techniques to get co-prime pairs {List all m,r that gcd(m,r) == 1}, but I'm not sure and I don't think that's necessary, since nlogn is still pretty fast.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    vector<tuple<int,int,int>> primTriples;
    vector<tuple<int,int,int>> multTriples;

    for(int m=2; m*m <= n/2; m++) {
        for(int r=1; r < m; r++) {
            if((m-r)%2 == 1 && __gcd(m,r) == 1) {
                // Then primitive triple found
                int a = m*m - r*r;
                int b = 2*m*r;
                int c = m*m + r*r;
                int P = a + b + c;   // == 2*m*(m+r)

                if (P <= n) {
                    // primitive triple (a,b,c) is valid
                    if(a > b) swap(a,b);
                    primTriples.push_back({a, b, c});
                }
            }
        }
    }

    for(auto [a,b,c] : primTriples) {
        for(int k=2; k*(a + b + c) <= n; k++) {
            multTriples.push_back({k*a, k*b, k*c});
        }
    }

    cout<<"Primitive Triples: \n";
    for (auto [a, b, c] : primTriples) cout << "(" << a << ", " << b << ", " << c << ")\n";

    cout<<"Multiplied/Non-Primitive Triples: \n";
    for (auto [a, b, c] : multTriples) cout << "(" << a << ", " << b << ", " << c << ")\n";
}