#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll fast_power(ll base, ll power, ll mod) {
    if (power == 0)
        return 1;
    else if (power == 1)
        return base;
    else {
        if (power % 2 == 1) {
            return fast_power(base * base % mod, power / 2, mod) * base % mod;
        } else {
            return fast_power(base * base % mod, power / 2, mod);
        }
    }
}

int mod27(int x) {
    if (x == 0) return 1;
    if (x == 1) return 1;
    if (x == 2) return 2;
    int tmp = x % 27;
    int tmp2 = 1;
    for (int i = 1; i <= tmp; i++) {
        if (i % 3 == 0) continue;
        tmp2 *= i;
        tmp2 %= 27;
    }
    return ((fast_power(26, x / 27, 27) * mod27(x / 3)) % 27 * tmp2) % 27;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int i, j;
    vector<vector<int>> comb11(12, vector<int>(12, 0));
    comb11[0][0] = 1;
    for (i = 1; i <= 11; i++) {
        comb11[i][0] = 1;
        comb11[i][i] = 1;
        for (j = 1; j < i; j++) {
            comb11[i][j] = (comb11[i - 1][j - 1] + comb11[i - 1][j]) % 11;
        }
    }

    vector<vector<int>> comb13(14, vector<int>(14, 0));
    comb13[0][0] = 1;
    for (i = 1; i <= 13; i++) {
        comb13[i][0] = 1;
        comb13[i][i] = 1;
        for (j = 1; j < i; j++) {
            comb13[i][j] = (comb13[i - 1][j - 1] + comb13[i - 1][j]) % 13;
        }
    }

    vector<vector<int>> comb37(38, vector<int>(38, 0));
    comb37[0][0] = 1;
    for (i = 1; i <= 37; i++) {
        comb37[i][0] = 1;
        comb37[i][i] = 1;
        for (j = 1; j < i; j++) {
            comb37[i][j] = (comb37[i - 1][j - 1] + comb37[i - 1][j]) % 13;
        }
    }

    vector<int> inv27(27, 0);
    for (j = 1; j < 27; j++) {
        inv27[j] = fast_power(j, 17, 27);
        cout << inv27[j] << " ";
    }
    cout << '\n';

    int t;
    cin >> t;
    int n1, k1, n2, k2, n3, k3;
    for (i = 0; i < t; i++) {
        cin >> n1 >> k1;
        n2 = n1, n3 = n1, k3 = k1, k2 = k1;

        int ans1 = 1, ans2 = 1, ans3 = 1, ans4 = 1;
        ans4 = mod27(n1) * inv27[mod27(k1)] * inv27[mod27(n1 - k1)] % 27;
        while (n1 > 0) {
            ans1 *= comb11[n1 % 11][k1 % 11];
            ans1 %= 11;
            n1 /= 11;
            k1 /= 11;
        }
        while (n2 > 0) {
            ans2 *= comb13[n2 % 13][k2 % 13];
            ans2 %= 13;
            n2 /= 13;
            k2 /= 13;
        }
        while (n3 > 0) {
            ans3 *= comb37[n3 % 37][k3 % 37];
            ans3 %= 37;
            n3 /= 37;
            k3 /= 37;
        }

        int inv1 = 8, inv2 = 10, inv3 = 20, inv4 = 26;
        ll sum = 0;

        cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << " \n";

        for (int i = 0; i <= 142857; i++) {
            if (i % 11 == ans1 && i % 13 == ans2 && i % 37 == ans3 && i % 27 == ans4) sum = i;
        }

        cout << sum << '\n';
    }
}