// D
#include <bits/stdc++.h>
#include <cmath>

double newtonRaphson(long double a, long double b, long double c, long double d, long double initialGuess) {
    const long double EPSILON = 1e-15;
    long double x = initialGuess;

    while (true) {
        long double f = a * pow(x, 3) + b * pow(x, 2) + c * x + d;  // 계산된 함수 값
        long double fprime = 3 * a * pow(x, 2) + 2 * b * x + c;  // 미분 값

        // x의 업데이트
        long double x1 = x - 0.25 * f / fprime;

        // 상대 오차가 충분히 작으면 종료
        if (abs(x1 - x) < EPSILON) {
            break;
        }

        x = x1;
    }

    return x;
}

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
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, b;
    cin >> n >> b;
    long double A = 0, B = 0, C = 0, D = 0;

    vdt v(n);
    for (auto& k : v) {
        cin >> k.a >> k.b;
        A += -k.a * k.a * k.a;
        B += k.a * k.a * (k.b - b) * 3; 
        C += -k.a * (k.b - b) * (k.b - b) * 3;
        D += (k.b - b) * (k.b - b) * (k.b - b);
    }

    B /= A, C /= A, D /= A, A /= A;

    // bool f = false;
    // for (ll i = -500'000; i <= 500'000; i++) {
    //     if (i * i * i + B * i * i + C * i + D == 0) {
    //         cout << i;
    //         f = true;
    //         break;
    //     }
    // }

    // if (!f)
        cout << fixed << setprecision(10) << newtonRaphson(A, B, C, D, 0.0);

    return 0;
}