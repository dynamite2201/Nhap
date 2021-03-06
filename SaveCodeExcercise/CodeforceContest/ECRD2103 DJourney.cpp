//
// Created by alex on 31/01/2021.
// https://codeforces.com/contest/1476/problem/D

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
    vi p, rank, setSize;                           // vi p is the key part
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);                           // optional speedup
        setSize.assign(N, 1);                        // optional feature
        numSets = N;                                 // optional feature
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; }      // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;                 // i and j are in same set
        int x = findSet(i), y = findSet(j);          // find both rep items
        if (rank[x] > rank[y]) {
            p[y] = x;
            setSize[x] += setSize[y];
        } else if (rank[x] < rank[y]) {
            p[x] = y;
            setSize[y] += setSize[x];
        } else {
            p[x] = y;
            rank[y]++;
            setSize[y] += setSize[x];
        }
        --numSets;                                   // a union reduces numSets

    }
};

void runcase() {

    int n;
    cin >> n;
    UnionFind UF(2 * n + 2);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'L') {
            UF.unionSet((n + 1) + i, i + 1);
        } else {
            UF.unionSet(i, (n + 1) + i + 1);
        }
    }
    for (int i = 0; i <= n; ++i) {
        cout << UF.sizeOfSet(i) << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        runcase();
    }
}

