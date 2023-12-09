// 1620 나는야 포켓몬 마스터 이다솜
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll i, j;
    ll n, m;
    cin >> n >> m;

    string tmp;
    unordered_map<string, int> g;

    for (i = 1; i <= n; i++) {
        cin >> tmp;
        g.insert({tmp, i});
    }

    unordered_map<int, string> g_reversed;
    for (const auto& k : g) {
        g_reversed[k.second] = k.first;
    }

    for (i = 0; i < m; i++) {
        cin >> tmp;
        if (isdigit(tmp[0]) != 0) {
            cout << g_reversed[stoi(tmp)] << '\n';
        } else {
            cout << g[tmp] << '\n';
        }
    }
}