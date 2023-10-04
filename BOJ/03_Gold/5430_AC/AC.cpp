#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    deque<int> dq;
    bool reverse = false, flag = false;
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string s, l;
        int n;
        cin >> s >> n >> l;
        string tmp;
        for (int i = 0; i < l.length(); i++) {
            if (isdigit(l[i])) {
                tmp += l[i];
            } else {
                if(!tmp.empty()) {
                    dq.push_back(stoi(tmp));
                    tmp = "";
                }
            }
        }

        reverse = false;
        flag = true;
        for (auto tmp : s) {
            if (tmp == 'R') {
                if (reverse) reverse = false;
                else reverse = true;
            }
            else {
                if (dq.empty()) {
                    cout << "error\n";
                    flag = false;
                    break;
                }
                if (reverse) {
                    dq.pop_back();
                } else {
                    dq.pop_front();
                }
            }
        }

        if (flag) {
            cout << "[";
            if (reverse) {
                while (!dq.empty()) {
                    cout << dq.back();
                    if (dq.size() > 1) cout << ",";
                    dq.pop_back();
                }
            } else {
                while (!dq.empty()) {
                    cout << dq.front();
                    if (dq.size() > 1) cout << ",";
                    dq.pop_front();
                }
            }
            cout << "]\n";
        }
    }
}