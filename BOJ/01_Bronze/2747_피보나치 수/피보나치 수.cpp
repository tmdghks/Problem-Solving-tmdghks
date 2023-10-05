#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> DP(46,0);
    DP[1] = 1;
    for (int i = 2; i <= 45; i++) {
        DP[i] = DP[i - 1] + DP[i - 2];
    }   

    int tmp;
    cin >> tmp;
    cout << DP[tmp] << '\n';
}   