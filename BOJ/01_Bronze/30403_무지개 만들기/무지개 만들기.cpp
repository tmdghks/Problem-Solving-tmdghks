// 30403 무지개 만들기
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    vector<bool> up(7, false);
    vector<bool> down(7, false);
    string s;
    int n;
    
    cin >> n;
    cin >> s;
    for (auto c : s) {
        switch(c) {
            case 'r': up[0] = true; break;
            case 'o': up[1] = true; break;
            case 'y': up[2] = true; break;
            case 'g': up[3] = true; break;
            case 'b': up[4] = true; break;
            case 'i': up[5] = true; break;
            case 'v': up[6] = true; break;
            case 'R': down[0] = true; break;
            case 'O': down[1] = true; break;
            case 'Y': down[2] = true; break;
            case 'G': down[3] = true; break;
            case 'B': down[4] = true; break;
            case 'I': down[5] = true; break;
            case 'V': down[6] = true; break;
        }
    }

    bool f1 = up[0] && up[1] && up[2] && up[3] && up[4] && up[5] && up[6];
    bool f2 = down[0] && down[1] && down[2] && down[3] && down[4] && down[5] && down[6];

    if (f1 && f2) {
        cout << "YeS";
    } else if (f1) {
        cout << "yes";
    } else if (f2) {
        cout << "YES";
    } else {
        cout << "NO!";
    }
}