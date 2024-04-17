#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 100; // maximum size of the queue

class Queue {
private:
    int arr[MAX_SIZE];
    int frontIndex;
    int rearIndex;

public:
    Queue() {
        frontIndex = -1;
        rearIndex = -1;
    }

    void push(int value) {
        if (rearIndex == MAX_SIZE - 1) {
            cout << "Queue is full. Cannot push more elements." << endl;
            return;
        }

        if (frontIndex == -1) {
            frontIndex = 0;
        }

        rearIndex++;
        arr[rearIndex] = value;
    }

    void pop() {
        if (frontIndex == -1 || frontIndex > rearIndex) {
            cout << "Queue is empty. Cannot pop any element." << endl;
            return;
        }

        frontIndex++;
    }

    int size() {
        if (frontIndex == -1 || frontIndex > rearIndex) {
            return 0;
        }

        return rearIndex - frontIndex + 1;
    }

    bool empty() {
        return (frontIndex == -1 || frontIndex > rearIndex);
    }

    int front() {
        if (frontIndex == -1 || frontIndex > rearIndex) {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }

        return arr[frontIndex];
    }

    int back() {
        if (frontIndex == -1 || frontIndex > rearIndex) {
            cout << "Queue is empty. No back element." << endl;
            return -1;
        }

        return arr[rearIndex];
    }
};

int main() {
    
}