// 1208 부분수열의 합 2
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using LL = unsigned long long;
const ll mod = 1'000'000'000;

// pair
struct dt {
    ll a;  // current
    ll b;  // sum
};

// vector<pair>
using vdt = vector<dt>;

vll sum1(8'000'005, 0);
vll sum2(8'000'005, 0);
vector<int> v1, v2;

ll n;
void make_sum1(ll depth, int current_sum) {
    if (depth == n / 2 - 1) {
        sum1[v1[depth] + current_sum + 4000000]++;
        sum1[current_sum + 4000000]++;
        return;
    }

    make_sum1(depth + 1, current_sum);
    make_sum1(depth + 1, current_sum + v1[depth]);
}

void make_sum2(ll depth, int current_sum) {
    if (depth == n - n / 2 - 1) {
        sum2[v2[depth] + current_sum + 4000000]++;
        sum2[current_sum + 4000000]++;
        return;
    }

    make_sum2(depth + 1, current_sum);
    make_sum2(depth + 1, current_sum + v2[depth]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll s, i, ans = 0;
    cin >> n >> s;
    if (n == 1) {
        ll tmp;
        cin >> tmp;
        if (tmp == s)
            ans = 1;
        else
            ans = 0;
    } else {
        v1.resize(n / 2, 0);
        v2.resize(n - n / 2, 0);
        for (i = 0; i < n / 2; i++) {
            cin >> v1[i];
        }
        for (i = 0; i < n - n / 2; i++) {
            cin >> v2[i];
        }

        make_sum1(0, 0);
        make_sum2(0, 0);

        sum1[4'000'000]--; sum2[4'000'000]--;

        ans += sum1[s + 4'000'000] + sum2[s + 4'000'000];
        for (i = 0; i <= 8'000'000 && 8'000'000 + s - i >= 0; i++) {
            ans += sum1[i] * sum2[8'000'000 + s - i];
        }
    }
    cout << ans;
}