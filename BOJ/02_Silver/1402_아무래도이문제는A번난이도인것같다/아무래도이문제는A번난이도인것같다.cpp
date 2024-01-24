// 1402 아무래도이문제는A번난이도인것같다   
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL = __uint128_t;  // 128비트 정수는 cout, printf 등으로 출력할 수 없음에 유의

ll INF = 100'000'000'000;

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

    ll n, tmp;
    cin >> n;
    for (ll i = 0; i < 2 * n; i++) {
        cin >> tmp;
    }

    for (ll i = 0; i < n; i++) {
        cout << "yes\n";
    }
}
