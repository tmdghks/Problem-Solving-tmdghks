// BOJ 22993 서든어택 3
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, a;
    cin >> n >> a;
    vector<int> v(n - 1, 0);
    for (int i = 0; i < n - 1; i++) {
        cin >> v[i];
    }

    stable_sort(v.begin(), v.end());

    for (int i = 0; i < n - 1; i++) {
        if (a <= v[i]) {
            cout << "No";
            return 0;
        }
        a += v[i];
    }

    cout << "Yes";
}