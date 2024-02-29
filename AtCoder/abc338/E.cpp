// Atcoder 338: E - Chords
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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    vdt v(2 * n);
    ll a, b;
    for (ll i = 0; i < n; i++) {
        cin >> a >> b;
        --a, --b;
        if (a > b) swap(a, b);

        v[a] = {0, i};
        v[b] = {1, i};
    }
    
    stack<ll> st;
    for (ll i = 0; i < 2 * n; i++) {
        if (v[i].a == 0) {
            st.push(v[i].b);
        } else {
            if (st.top() != v[i].b) {
                cout << "Yes";
                return 0;
            }
            st.pop();
        }
    }

    cout << "No";
}