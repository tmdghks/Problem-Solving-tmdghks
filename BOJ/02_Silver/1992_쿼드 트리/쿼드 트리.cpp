// 1992 쿼드 트리
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
bool dt_cmp(dt lhs, dt rhs) {
    return lhs.a < rhs.a;
}

vvll v;

void divide_conquer(ll n, ll x, ll y);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    v.resize(n, vll(n, 0));
    ll i, j;
    for (i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for (j = 0; j < n; j++) {
            v[j][i] = tmp[j] - '0';
        }
    }

    divide_conquer(n, 0, 0);
}

void divide_conquer(ll n, ll x, ll y) {
    if (n == 1) {
        cout << v[x][y];
        return;
    }

    bool f0 = true, f1 = true;
    ll i, j;
    for (i = x; i < x + n; i++) {
        for (j = y; j < y + n; j++) {
            if (v[i][j] == 1) f0 = false;
            else f1 = false;
            if (!(f0 || f1)) break;
        }
    }

    if (f0 && !f1) cout << 0;
    else if (f1 && !f0) cout << 1;
    else {
        cout << "(";
        divide_conquer(n / 2, x, y);
        divide_conquer(n / 2, x + n / 2, y);
        divide_conquer(n / 2, x, y + n / 2);
        divide_conquer(n / 2, x + n / 2, y + n / 2);
        cout << ")";
    }
}