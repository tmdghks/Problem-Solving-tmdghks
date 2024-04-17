#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL = __uint128_t;  // 128비트 정수는 cout, printf 등으로 출력할 수 없음에 유의

ll INF = 999'999'999;

// 3-pair
struct dt {
    ll a;
    ll b;
};

// vector<pair>
using vdt = vector<dt>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll N, T;
    cin >> T;

    for (ll i = 0; i < T; i++) {
        cin >> N;
        if (N == 1) {
            cout << "kidw0124\n";
        } else {
            if (ll(log2(N)) % 2 == 1) {
                cout << "kidw0124\n";
            } else {
                cout << "eoaud0108\n";
            }
        }
    }
}