#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    stack<int> st;
    st.push(1);
    st.push(2);
    cout << st.top() << '\n'; // 2
    st.pop();
    cout << st.top() << '\n'; // 1
    cout << st.size() << '\n'; // 1
    cout << (st.empty() ? "Stack is empty" : "Stack is not empty") << '\n'; // Stack is not empty
    return 0;
}