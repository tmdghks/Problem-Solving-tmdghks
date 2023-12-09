// 10814 나이순 정렬
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

struct dt {
    ll a;
    string b;
    ll c;
};

bool compare(dt a, dt b) {
    if (a.a == b.a) {
        return a.c < b.c;
    } else {
        return a.a < b.a;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll i, j, n;

    vector<dt> g;
    cin >> n;

    ll a;
    string b;
    for (i = 0; i < n; i++) {
        cin >> a >> b;
        g.push_back({a, b, i});
    }

    sort(g.begin(), g.end(), compare);

    for (auto s : g) {
        cout << s.a << ' ' << s.b << '\n';
    }
}