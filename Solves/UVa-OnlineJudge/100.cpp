//? Input restrictions aren't that big so just do brute force
#include <bits/stdc++.h>
using namespace std;

int cycleLength(int n) {
    int count = 1;
    while (n != 1) {
        if (n % 2) n = 3 * n + 1;
        else n /= 2;
        count++;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int i, j;
    while (cin >> i >> j) {
        int low = min(i, j), high = max(i, j);
        int maxCycle = 0;
        for (int k = low; k <= high; ++k)
            maxCycle = max(maxCycle, cycleLength(k));
        cout << i << " " << j << " " << maxCycle << "\n";
    }
    return 0;
}