// 2473 세 용액
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using LL = unsigned long long;
using lll = __int128_t;
using LLL =
    __uint128_t;  // 128비트 정수는 cout, printf 등으로 출력할 수 없음에 유의

struct dt {
    ll node1;
    ll node2;
    ll weight;
};
using vdt = vector<dt>;

struct coordinate {
    ll x;
    ll y;
    ll z;
};

double find_distance(const coordinate& c1, const coordinate& c2);

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

    int n;
    cin >> n;
    vll v(n, 0);
    for (auto& k : v) {
        cin >> k;
    }

    ll ans = 100'000'000'000;
    vll ans_vector(3, 0);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        vll v_tmp;
        for (int j = 0; j < n; j++) {
            if (i != j) v_tmp.push_back(v[j]);
        }

        ll p1 = 0, p2 = n - 2;
        ll ans3 = v[i];
        ll ans1 = v[p1], ans2 = v[p2];
        ll ans_tmp = abs(ans1 + ans2 + ans3);
        while (p1 < p2) {
            if (abs(v[p1] + v[p2] + ans3) < ans_tmp) {
                ans1 = v_tmp[p1];
                ans2 = v_tmp[p2];
                ans_tmp = abs(ans1 + ans2 + ans3);
            }

            if (v_tmp[p1] + v_tmp[p2] + v[i] < 0) {
                p1++;
            } else {
                p2--;
            }
        }

        if (ans > ans_tmp) {
            ans = ans_tmp;
            ans_vector[0] = ans1, ans_vector[1] = ans2, ans_vector[2] = ans3;
        }

        v_tmp.clear();
    }

    sort(ans_vector.begin(), ans_vector.end());

    for (auto k : ans_vector) {
        cout << k << " ";
    }
}

ll union_find(ll n, vll& root) {
    if (root[n] == n)
        return n;
    else {
        return root[n] = union_find(root[n], root);
    }
}

double find_distance(const coordinate& c1, const coordinate& c2) {
    return min({abs(c1.x - c2.x), abs(c1.y - c2.y), abs(c1.z - c2.z)});
}