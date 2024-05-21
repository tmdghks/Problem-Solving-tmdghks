// 2239: 스도쿠
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL =
    __uint128_t;  // 128비트 정수는 cout, printf 등으로 입출력할 수 없음에 유의

struct dt {
    ll node1;
    ll node2;
    ll weight;
};
using vdt = vector<dt>;

struct coordinate_3d {
    ll x;
    ll y;
    ll z;
};

struct coordinate_2d {
    ll x;
    ll y;
};

double find_distance(const coordinate_3d& c1, const coordinate_3d& c2);

struct cmp {
    bool operator()(const dt& a, const dt& b) { return a.weight < b.weight; }
};

bool cmp_weights(const dt& a, const dt& b) { return a.weight < b.weight; }

ll union_find(ll n, vll& root);

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll T = 1;
    while (T--) solve();
}

bool isValid(vvll& sudoku, ll x, ll y, ll num) {
    for (int i = 0; i < 9; i++) {
        if (num == sudoku[x][i] || num == sudoku[i][y] ||
            sudoku[x - x % 3 + i / 3][y - y % 3 + i % 3] == num) {
            return false;
        }
    }
    return true;
}

bool f = true;

void backTracking(vvll& sudoku, vector<coordinate_2d>& vectorWhereZero, ll n,
                  ll maxLength) {
    if (!f) return;
    if (n == maxLength && f) {
        f = false;
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j];
            }
            cout << '\n';
        }

        return;
    }
    auto [x, y] = vectorWhereZero[n];

    for (int i = 1; i <= 9; i++) {
        if (!isValid(sudoku, x, y, i)) {
            continue;
        }

        sudoku[x][y] = i;
        backTracking(sudoku, vectorWhereZero, n + 1, maxLength);
        sudoku[x][y] = 0;
    }
    return;
}

void solve() {
    ll n;
    vvll sudoku(9, vll(9));
    vector<coordinate_2d> vectorWhereZero;
    for (int i = 0; i < 9; i++) {
        cin >> n;
        for (int j = 8; j >= 0; --j) {
            sudoku[i][j] = n % 10;
            n /= 10;
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0)
                vectorWhereZero.push_back({i, j});
        }
    }

    backTracking(sudoku, vectorWhereZero, 0, vectorWhereZero.size());
}

ll union_find(ll n, vll& root) {
    if (root[n] == n)
        return n;
    else {
        return root[n] = union_find(root[n], root);
    }
}

double find_distance(const coordinate_3d& c1, const coordinate_3d& c2) {
    return min({abs(c1.x - c2.x), abs(c1.y - c2.y), abs(c1.z - c2.z)});
}