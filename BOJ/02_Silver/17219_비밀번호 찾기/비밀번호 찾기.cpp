#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using ld = long double;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N, M;
    cin >> N >> M;

    unordered_map<string, string> um;

    for (int i = 0; i < N; ++i) {
        string str1, str2;
        cin >> str1 >> str2;

        um.insert(make_pair(str1, str2));
    }

    for (int i = 0; i < M; ++i) {
        string str;
        cin >> str;
        cout << um[str] << "\n";
    }

    return 0;
}