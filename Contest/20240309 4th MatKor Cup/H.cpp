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

    ll n, m, t;
    cin >> n >> m >> t;
    vll a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << fixed << setprecision(10) << a[0] - a[0] * pow(t, 1 / (double) m);
    } else if (m == 1){
        cout << 0;
    } else if (n == 2) {
        cout << "MatKor 김동우, 김재우 고급 알고리즘 세미나 화이팅";
    } else if (m == 2) {
        cout << "AlKor 주현철, 최준혁 입문 알고리즘 세미나 화이팅";
    } else {
        cout << "ALPS 위재현 중급 알고리즘 세미나 화이팅";
    }
}