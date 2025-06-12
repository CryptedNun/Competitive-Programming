#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for (int i = 1; i <= t; ++i) {
        long long seconds, root, shorted, row, column;
        cin >> seconds;

        root = ceil(sqrt(seconds));
        shorted = root * root - seconds;

        if (shorted < root) {
            row = root;
            column = shorted + 1;
        } else {
            column = root;
            row = seconds - (root - 1) * (root - 1);
        }

        if (root % 2 == 0) swap(row, column);
        cout << "Case " << i << ": " << column << " " << row << "\n";
    }
}