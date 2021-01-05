#include <bits/stdc++.h>

using namespace std;
struct node {
    int h, w;
    int id;
} p[200010];
int _;
int n;
int ans[200010];

bool cmp(const struct node &a, const struct node &b) {
    if (a.h == b.h)
        return a.w < b.w;
    return a.h < b.h;
}

int main() {
    cin >> _;
    while (_--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i].h >> p[i].w;
            p[i].id = i;
            if (p[i].h > p[i].w) {
                swap(p[i].h, p[i].w);
            }
        }
        sort(p + 1, p + n + 1, cmp);
        int mw = 1e9 + 11;//当前比p[i].h小的y的最小值
        int maw = 1e9 + 11;//为下一次更新做准备
        int mwpos = -1;
        int mawpos = -1;
        for (int i = 1; i <= n; i++) {
            if (p[i].w > mw) {
                ans[p[i].id] = p[mwpos].id;
            } else {
                ans[p[i].id] = -1;
            }
            if (p[i].w < maw) {
                maw = p[i].w;
                mawpos = i;
            }
            if (i < n && p[i + 1].h > p[i].h) {
                if (maw < mw) {
                    mw = maw;
                    mwpos = mawpos;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}