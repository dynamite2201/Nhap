//
// Created by alex on 18/01/2021.
//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll maxDay = 1e6 + 200000 + 10;

void run_case() {
    priority_queue<pair<pair<ll, ll>, ll>, vector<pair<pair<ll, ll>, ll>>, less<>> costBias;
    priority_queue<pair<pair<ll, ll>, ll>, vector<pair<pair<ll, ll>, ll>>, greater<>> timeBias;

    ll n;
    cin >> n;
    ll t[n + 1], c[n + 1], saveDay[n + 1];

    for (int i = 1; i < n + 1; ++i) {
        cin >> t[i] >> c[i];
        timeBias.push({make_pair(t[i], c[i]), i});
    }

    ll moneyBorrow = 0; // Số tiền vay
    for (int i = t[1]; i < maxDay; ++i) { // Duyệt từ ngày t[1] đến ngày MAX

        if (!timeBias.empty()) { // Vẫn còn môn phải thi
            while (i == timeBias.top().first.first && !timeBias.empty()) { // Hôm nay có môn thi mới mở
                costBias.push({{timeBias.top().first.second, timeBias.top().first.first},
                               timeBias.top().second}); // Cho luôn vào costBias
                timeBias.pop(); // Xóa môn đó ở timeBias
            }
        }

        // Thi môn trong costBias, môn cấp bách nhất
        // Lấy môn đó ra
        if (!costBias.empty()) {
            pair<pair<ll, ll>, ll> maxExamCostNow = costBias.top();
            costBias.pop();
            if (moneyBorrow < maxExamCostNow.first.first + (i - maxExamCostNow.first.second)) {
                moneyBorrow = maxExamCostNow.first.first + (i - maxExamCostNow.first.second);
            }
            // Lưu ngày thi vào của môn đó là ngày hôm nay
            saveDay[maxExamCostNow.second] = i;
        }

        if (costBias.empty() && timeBias.empty()) break; // Thi xong hết rồi
    }

    // In kết quả
    for (int i = 1; i < n + 1; ++i) {
        cout << saveDay[i] << " ";
    }
}

int main() {
    run_case();
}