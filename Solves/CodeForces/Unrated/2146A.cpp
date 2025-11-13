#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> freq(n + 1, 0); // freq[t] = # of elements in a, with value exactly t
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        vector<int> countFreq(n + 1, 0); // countFreq[t] = # of unique elements with frequency exactly t.
        for(auto& element : freq) countFreq[element]++;

        vector<int> incFreq(n + 1, 0); // incFreq[t] = # of unique elements with freq >= t, incFreq[t] = incFreq[t + 1] + countFreq[t]
        incFreq[n] = countFreq[n];
        for(int i = n - 1; i >= 1; i--) incFreq[i] = incFreq[i + 1] + countFreq[i];

        int answer = 0;
        for(int i = 1; i <= n; i++) answer = max(answer, incFreq[freq[i]] * freq[i]);

        cout << answer << endl;
    }
}