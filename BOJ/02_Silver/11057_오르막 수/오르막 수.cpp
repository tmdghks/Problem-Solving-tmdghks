#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<vector<long long>> v(1001, vector<long long>(10, 0));
    int n;
    cin >> n;

    for (int i = 0; i < 10; i++) {
        v[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= j; k++) {
                v[i][j] += v[i - 1][k];
            }
            v[i][j] %= 10007;
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += v[n][i];
    }

    cout << sum % 10007 << '\n';
}