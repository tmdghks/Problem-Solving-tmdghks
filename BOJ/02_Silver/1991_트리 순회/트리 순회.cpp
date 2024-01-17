// 1991 트리 순회
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

vvll tr(26, vll(2, 100));

void preorder_traversal(int x) {
    if (tr[x][0] == 100 && tr[x][1] == 100) {
        cout << (char) (x + 'A');
        return;
    }
    cout << (char) (x + 'A');
    if (tr[x][0] != 100) {
        preorder_traversal(tr[x][0]);
    }
    if (tr[x][1] != 100) {
        preorder_traversal(tr[x][1]);
    }
}

void inorder_traversal(int x) {
    if (tr[x][0] == 100 && tr[x][1] == 100) {
        cout << (char) (x + 'A');
        return;
    }
    if (tr[x][0] != 100) {
        inorder_traversal(tr[x][0]);
    }
    cout << (char) (x + 'A');
    if (tr[x][1] != 100) {
        inorder_traversal(tr[x][1]);
    }
}

void postorder_traversal(int x) {
    if (tr[x][0] == 100 && tr[x][1] == 100) {
        cout << (char) (x + 'A');
        return;
    }
    if (tr[x][0] != 100) {
        postorder_traversal(tr[x][0]);
    }
    if (tr[x][1] != 100) {
        postorder_traversal(tr[x][1]);
    }
    cout << (char) (x + 'A');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll i, j, n;
    char a, b, c;
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> a >> b >> c;
        tr[a - 'A'][0] = b == '.' ? 100 : b - 'A';
        tr[a - 'A'][1] = c == '.' ? 100 : c - 'A';
    }

    preorder_traversal(0);
    cout << '\n';
    inorder_traversal(0);
    cout << '\n';
    postorder_traversal(0);
    cout << '\n';

    return 0;
}