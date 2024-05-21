// 2263 : 트리의 순회
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

    ll T = 1;
    while (T--) solve();
}

void printPreOrder(vll& inOrder, vll& postOrder, int sIn, int eIn, int sPost,
                   int ePost) {
    // cout << "sIn: " << sIn << " eIn: " << eIn << '\n';
    // cout << "sPost: " << sPost << " ePost: " << ePost << '\n';
    if (sIn > eIn || sPost > ePost) return;

    ll root = postOrder[ePost];
    cout << root << " ";

    ll rootIndex = sIn;
    for (rootIndex = sIn; rootIndex <= eIn; rootIndex++) {
        if (inOrder[rootIndex] == root) {
            break;
        }
    }

    int left = rootIndex - sIn;

    printPreOrder(inOrder, postOrder, sIn, rootIndex - 1, sPost, sPost + left - 1);
    printPreOrder(inOrder, postOrder, rootIndex + 1, eIn, sPost + left, ePost - 1);
}

void solve() {
    ll n; cin >> n;
    vll inOrder(n);
    vll postOrder(n);

    for (auto& k : inOrder) cin >> k;
    for (auto& k : postOrder) cin >> k;

    printPreOrder(inOrder, postOrder, 0, n-1, 0, n-1);
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