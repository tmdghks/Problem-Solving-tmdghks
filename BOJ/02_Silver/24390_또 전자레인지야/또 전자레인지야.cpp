// 24390 또 전자레인지야?
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

    string s;
    cin >> s;
    ll S, tmp1 = 0, tmp2 = 99999, cnt = 0;

    S = (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10;

    tmp1 = S / 600 + (S % 600) / 60 + (S % 60) / 30 + (S % 30) / 10 + 1;
    if (S >= 30) {
        S -= 30;
        tmp2 = S / 600 + (S % 600) / 60 + (S % 60) / 30 + (S % 30) / 10 + 1;
    }
    cnt = min(tmp1, tmp2);
    cout << cnt;
}
