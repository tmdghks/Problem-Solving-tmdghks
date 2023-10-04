#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;

    vector<int> DP(11, 0);
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    for (int i = 4; i < 11; i++) {
        DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
    }

    for (int i = 0; i < t; i++) {
        int tmp;
        cin >> tmp;
        cout << DP[tmp] << '\n';
    }
}