#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL =
    __uint128_t;  // 128비트 정수는 cout, printf 등으로 출력할 수 없음에 유의

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<string> str(5);

    for (auto& k : str) cin >> k;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (str[j].length() > i) {
                cout << str[j][i];
            }
        }
    }
}