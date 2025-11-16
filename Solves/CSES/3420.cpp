#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ----------------------------------
    int n; cin >> n;
    vector<int> x(n);
    for(int& element : x) cin >> element;
    // ----------------------------------

    map<int, int> freq;
    long long l = 0, r = 0, count = 0;
    while(r < n) {
        freq[x[r]]++;

        while(freq[x[r]] > 1) {
            freq[x[l]]--;
            l++;
        }

        count += (r - l + 1);
        r++;
    }

    cout << count << endl;
}