//
// Created by alex on 30/01/2021.
//
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int &e : c) cin >> e;
        for (int &e : a) cin >> e;
        for (int &e : b) cin >> e;
        vector<long long> dp(n);
        dp[0] = -1e18;
        for (int i = 1; i < n; i++) {
            long long foo = abs(a[i] - b[i]);
            if (foo == 0) dp[i] = 2;
            else dp[i] = max(2 + foo, 2 + c[i - 1] - 1 - foo + dp[i - 1]);
        }
        long long ans = -1e18;
        for (int i = 1; i < n; i++) {
            // cout << dp[i] << ' ' << c[i] << endl;
            ans = max(ans, dp[i] + c[i] - 1);
        }
        cout << ans << '\n';
    }

    return 0;
}


