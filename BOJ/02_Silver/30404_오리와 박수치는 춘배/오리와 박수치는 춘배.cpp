// 30404 오리와 박수치는 춘배
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int i, j;
    int n, k;
    cin >> n >> k;

    vector<int> v(n, 0);
    for (i = 0; i < n; i++) {
        cin >> v[i];
    }

    stable_sort(v.begin(), v.end(), greater<int>());

    int cnt = 1;
    int tmp = v[0];
    for (int i = 1; i < n; i++) {
        if (tmp - v[i] > k) {
            tmp = v[i];
            cnt++;
        }
    }

    cout << cnt;
}