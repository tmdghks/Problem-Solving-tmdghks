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

    ll a, b, h;
    cin >> a >> b >> h;

    double pi = 3.14159265358979323846;

    if (a == b) {
        cout << -1;
    } else {
        if (a > b) swap(a, b);
        double x = (a * h) / (double)(b - a);
        cout << fixed << setprecision(7) <<  double(pi * (((b * b) + ((h + x) * (h + x)) - (a * a + x * x))));
    }
}