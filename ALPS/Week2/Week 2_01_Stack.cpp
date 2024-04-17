#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Stack {
private:
    static const int MAX_SIZE = 100; // 스택의 최대 크기
    T data[MAX_SIZE]; // 배열로 구현된 스택 데이터
    int topIndex; // 스택의 가장 위에 있는 요소의 인덱스

public:
    Stack() {
        topIndex = -1; // 스택이 비어있는 경우를 나타내기 위해 -1로 초기화
    }

    void push(const T& value) {
        if (topIndex == MAX_SIZE - 1) {
            // 스택이 가득 찬 경우
            cout << "Stack is full. Cannot push more elements." << endl;
            return;
        }
        topIndex++;
        data[topIndex] = value;
    }

    void pop() {
        if (topIndex == -1) {
            // 스택이 비어있는 경우
            cout << "Stack is empty. Cannot pop any element." << endl;
            return;
        }
        topIndex--;
    }

    T top() const {
        if (topIndex == -1) {
            // 스택이 비어있는 경우
            cout << "Error: stack is empty.\n";
            // 반환할 값이 없으므로 예외 처리나 기본값 반환 등의 방법을 선택할 수 있습니다.
        }
        return data[topIndex];
    }

    bool empty() const {
        return topIndex == -1;
    }

    int size() const {
        return topIndex + 1;
    }
};

int main() {
    // 스택 클래스 사용 예시
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Top element: " << stack.top() << endl;
    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl;
    cout << "Stack size: " << stack.size() << endl;
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl;
    return 0;
}