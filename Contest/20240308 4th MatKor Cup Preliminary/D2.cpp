// D
#include <bits/stdc++.h>

#include <cmath>

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

double newtonRaphson(long double a, long double b, long double c, long double d, long double initialGuess) {
    const long double EPSILON = 1e-11;
    long double x = initialGuess;

    while (true) {
        long double f = a * pow(x, 3) + b * pow(x, 2) + c * x + d;  // 계산된 함수 값
        long double fprime = 3 * a * pow(x, 2) + 2 * b * x + c;     // 미분 값

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

long double Root1, Root2, Root3;

// Function to find the roots of a cubic equation using the cubic formula
vector<long double> findCubicRoots(__int128_t a, __int128_t b, __int128_t c, __int128_t d) {
    vector<long double> roots;

    // Calculate discriminant
    long double discriminant = 18 * a * b * c * d - 4 * pow(b, 3) * d + pow(b, 2) * pow(c, 2) - 4 * a * pow(c, 3) - 27 * pow(a, 2) * pow(d, 2);

    if (discriminant > 0) {
        // Three distinct real roots
        long double C = pow((discriminant + sqrt(discriminant)) / 2, 1.0 / 3.0);
        long double D = pow((discriminant - sqrt(discriminant)) / 2, 1.0 / 3.0);

        long double root1 = (-1 * b + C + D) / (3 * a);
        long double root2 = (-1 * b - (C + D) / 2) / (3 * a) + (sqrt(3) * (C - D)) / (6 * a);
        long double root3 = (-1 * b - (C + D) / 2) / (3 * a) - (sqrt(3) * (C - D)) / (6 * a);

        roots.push_back(root1);
        roots.push_back(root2);
        roots.push_back(root3);
    } else if (discriminant == 0) {
        // One real root and two complex roots
        long double root1 = (-1 * b + pow(discriminant, 1.0 / 3.0)) / (3 * a);
        long double root2 = (-1 * b - pow(discriminant, 1.0 / 3.0)) / (3 * a);

        roots.push_back(root1);
        roots.push_back(root2);
    } else {
        // Three real roots, two of which are equal
        long double C = pow((discriminant + sqrt(-1 * discriminant)) / 2, 1.0 / 3.0);
        long double D = pow((discriminant - sqrt(-1 * discriminant)) / 2, 1.0 / 3.0);

        long double root1 = (-1 * b + C + D) / (3 * a);
        long double root2 = (-1 * b - (C + D) / 2) / (3 * a) + (sqrt(3) * (C - D)) / (6 * a);
        long double root3 = (-1 * b - (C + D) / 2) / (3 * a) - (sqrt(3) * (C - D)) / (6 * a);

        roots.push_back(root1);
        roots.push_back(root2);
        roots.push_back(root3);
    }

    Root1 = roots[0];
    Root2 = roots[1];
    Root3 = roots[2];

    return roots;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, b;
    cin >> n >> b;
    __int128_t A = 0, B = 0, C = 0, D = 0;

    ll maxtmp = 0;
    vdt v(n);
    for (auto& k : v) {
        cin >> k.a >> k.b;
        A += -k.a * k.a * k.a;
        B += k.a * k.a * (k.b - b) * 3;
        C += -k.a * (k.b - b) * (k.b - b) * 3;
        D += (k.b - b) * (k.b - b) * (k.b - b);
        if (maxtmp < abs(k.b / (double)k.a)) {
            maxtmp = abs(k.b / (double)k.a);
        }
    }

    findCubicRoots(A, B, C, D);
    if (isnan(Root1)) {
        if (isnan(Root2)) {
            if (isnan(Root3)) {
                cout << fixed << setprecision(10) << newtonRaphson(A, B, C, D, 0.0);
            } else {
                cout << fixed << setprecision(10) << Root3 << endl;
            }
        } else {
            cout << fixed << setprecision(10) << Root2 << endl;
        }
    } else {
        cout << fixed << setprecision(10) << Root1 << endl;
    }

    return 0;
}