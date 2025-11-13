// Fuck hardcoding

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int sum = 0;
        for(int i = 1; i <= 10; i++) {
            for(int j = 1; j <= 10; j++) {
                char input; cin >> input;
                if(input == 'X') {
                    int verticalDist, horizontalDist, dist;
                    verticalDist = (i <= 5) ? 5 - i : i - 6;
                    horizontalDist = (j <= 5) ? 5 - j : j - 6;
                    dist = max(verticalDist, horizontalDist);

                    int score = 5 - dist;
                    sum += score;
                }
            }
        }

        cout << sum << endl;
    }
}