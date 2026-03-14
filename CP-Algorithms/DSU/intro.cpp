
#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;

// ? DSU-------------------------------------------------------------------------------------
int parent[MAXN];
int SIZE[MAXN];

void make_set(int v) {
    parent[v] = v;
    SIZE[v] = 1;
}

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]); // ! Path compression 
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (SIZE[a] < SIZE[b]) swap(a, b); // ! Guarantees that a is bigger or atleast equal
        parent[b] = a;
        SIZE[a] += SIZE[b];
    }
}

void initialize_dsu(int n) {
    for (int i = 0; i < n; i++) 
        make_set(i);
}
// ? ----------------------------------------------------------------------------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
}