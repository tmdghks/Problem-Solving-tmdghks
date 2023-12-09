#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int depth = INT_MAX;
bool f = false;

void back_tracking(int a, int b, int d) {
    if (a == b) {
        if (depth > d) depth = d;
        f = true;
        return;
    }
    if (a > b) {
        return;
    }
    if (b % 10 == 1) {
        back_tracking(a, b / 10, d + 1);
    }
    if (b % 2 == 0) {
        back_tracking(a, b / 2, d + 1);
    }
    return;
}

int main() {
    int a, b;
    cin >> a >> b;

    back_tracking(a, b, 1);
    if (f)
        cout << depth;
    else
        cout << -1;
}