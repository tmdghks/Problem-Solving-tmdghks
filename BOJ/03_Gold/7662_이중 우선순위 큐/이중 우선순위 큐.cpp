// 7662 : 이중 우선순위 큐
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

    ll T;
    cin >> T;
    while (T--) solve();
}

void solve() {
    ll k;
    cin >> k;

    ll double_pq_size = 0;
    priority_queue<ll, vll, greater<ll>> pq1;
    priority_queue<ll> pq2;

    while (k--) {
        string s;
        ll a;
        cin >> s >> a;

        if (s == "I") {
            double_pq_size++;
            pq1.push(a);
            pq2.push(a);
        } else {
            if (a == 1) {
                if (double_pq_size) {
                    pq2.pop();
                    double_pq_size--;
                }
            } else {
                if (double_pq_size) {
                    pq1.pop();
                    double_pq_size--;
                }
            }
        }
    }

    if (double_pq_size) {
        cout << pq2.top() << " " << pq1.top() << '\n';
    } else {
        cout << "EMPTY\n";
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
