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

    ll a, m, n;
    cin >> a >> m >> n;
    if (n > m) {
        swap(n, m);
    }
    cout << fixed << setprecision(10) <<  min<double>({(max<double>(m / (double) a, n)), (m + n) / (double) a, (n + n) / (double) a});
}