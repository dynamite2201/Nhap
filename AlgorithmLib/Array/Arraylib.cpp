//
// Created by alex on 17/02/2021.
//
#include <bits/stdc++.h>

using namespace std;

int convert(vector<int> &arr, int x) {
    return (lower_bound(arr.begin(), arr.end(), x) - arr.begin());
}

vector<pair<int, int>> countOccurrences(vector<int> &arr) {
    vector<pair<int, int>> cntcnt;
    for (int i = 0; i < arr.size(); ++i) {
        int temp2 = arr[i];
        int index2 = i;
        int count2 = 0;
        while (temp2 == arr[index2] && index2 < arr.size()) {
            count2++;
            index2++;
        }
        cntcnt.emplace_back(temp2, count2);
        i = index2 - 1;
    }
    return cntcnt;
}

void runcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> temp = arr;
    vector<int> temp2 = arr;
    vector<int> temp3 = arr;
    sort(temp.begin(), temp.end());
    temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
    for (int i = 0; i < n; ++i) {
        arr[i] = convert(temp, arr[i]);
    }

    sort(arr.begin(), arr.end());
    vector<int> arr2 = arr;
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());

    // day ban dau
    cout << "Dãy ban đầu: " << "\n";
    for (int i = 0; i < temp2.size(); ++i) {
        cout << temp2[i] << " ";
    }
    cout << "\n";
    sort(temp3.begin(), temp3.end());
    cout << "Dãy ban đầu sắp xếp: " << "\n";
    for (int i = 0; i < temp3.size(); ++i) {
        cout << temp3[i] << " ";
    }
    cout << "\n";
    cout << "Dãy ban đầu sắp xếp khi rời rạc hóa: " << "\n";
    for (int i = 0; i < arr2.size(); ++i) {
        cout << arr2[i] << " ";
    }
    cout << "\n";

    cout << "Dãy ban đầu sắp xếp khi loại phần tử trùng: " << "\n";
    for (int i = 0; i < temp.size(); ++i) {
        cout << temp[i] << " ";
    }
    cout << "\n";

    cout << "Dãy ban đầu sắp xếp khi rời rạc hóa và loại phần tử trùng (luôn có dạng 0, 1, 2, 3...): " << "\n";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";


    map<int, long long int> myMap;
    for (int i = 0; i < arr.size(); ++i) {
        myMap[i] = temp[i];
    }

    cout << "Mapping giữa dãy ban đầu và rời rạc hóa" << "\n";
    for (int i = 0; i < myMap.size(); ++i) {
        cout << "{" << i << ":" << myMap[i] << "}" << " ";
    }
    cout << "\n";


    vector<pair<int, int>> cntOcc = countOccurrences(arr2);
    sort(cntOcc.begin(), cntOcc.end());

    cout << "Mapping giữa dãy ban đầu và số lượng lặp" << "\n";
    for (int i = 0; i < cntOcc.size(); ++i) {
        cout << "{" << cntOcc[i].first << ":" << cntOcc[i].second << "}" << " ";
    }
    cout << "\n";


    map<int, long long int> mySumMap;
    for (int i = 0; i < arr.size(); ++i) {
        mySumMap[i] = myMap[i] * cntOcc[i].second;
    }

    cout << "Mapping giữa dãy ban đầu và tổng các lặp" << "\n";
    for (int i = 0; i < mySumMap.size(); ++i) {
        cout << "{" << i << ":" << mySumMap[i] << "}" << " ";
    }
    cout << "\n";

}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    runcase();
    return 0;
}