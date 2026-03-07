#include <bits/stdc++.h>

using namespace std;

vector<string> results;
string current;
bool used[8];

void backtrack(string &s) {
    // !BASE CASE
    if (current.length() == s.length()) {
        results.push_back(current);
        return;
    }

    for (int i = 0; i < s.length(); i++) {
        // ! Skip if this character is already used in the current path
        if (used[i]) continue;

        // ! CRITICAL: Skip duplicate characters to avoid duplicate permutations
        // ! If s[i] == s[i-1] and the previous one wasn't used, it means
        // ! we already processed this character "slot" in a previous branch.
        if (i > 0 && s[i] == s[i-1] && !used[i-1]) continue;

        used[i] = true;
        current.push_back(s[i]);
        
        backtrack(s);
        
        // ! Backtrack: undo the choice
        current.pop_back();
        used[i] = false;
    }
}

int main() {
    string s; cin >> s;
    
    // Sort first to handle duplicates and ensure alphabetical order
    sort(s.begin(), s.end());

    backtrack(s);
    
    cout << results.size() << "\n";
    for (const string& res : results) 
        cout << res << "\n";
    
    return 0;
}