// 2166 다각형의 면적
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL = __uint128_t;  // 128비트 정수는 cout, printf 등으로 출력할 수 없음에 유의

// 2-pair
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

    ll N;
    cin >> N;

    vdt v(N, {0, 0});
    for (auto& k : v) {
        cin >> k.a >> k.b;
    }

    double area = 0;
    for (ll i = 1; i < N - 1; i++) {
        area += ((v[i].a - v[0].a) * (v[i+1].b - v[0].b) - (v[i+1].a-v[0].a)*(v[i].b-v[0].b)) / 2.0;
    }
    printf("%.1lf", abs(area));
}
