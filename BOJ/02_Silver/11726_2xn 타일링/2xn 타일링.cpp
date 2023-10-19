#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<long long> DP(1001, 0);

    DP[1] = 1;
    DP[2] = 2;
    for (int i = 3; i <= 1000; i++) {
        DP[i] = DP[i - 1] + DP[i - 2];
        DP[i] %= 10007;
    }    

    int n;
    cin >> n;
    cout << DP[n] << '\n';
}