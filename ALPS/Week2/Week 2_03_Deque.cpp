#include <bits/stdc++.h>

using namespace std;


class Deque {
private:
    static const int MAX_SIZE = 1000;
    int arr[MAX_SIZE];
    int frontIndex;
    int backIndex;
public:
    Deque() {
        frontIndex = -1;
        backIndex = -1;
    }

    void push_front(int value) {
        if (frontIndex == -1) {
            frontIndex = 0;
            backIndex = 0;
        } else if (frontIndex == 0) {
            frontIndex = MAX_SIZE - 1;
        } else {
            frontIndex--;
        }
        arr[frontIndex] = value;
    }

    void push_back(int value) {
        if (backIndex == -1) {
            frontIndex = 0;
            backIndex = 0;
        } else if (backIndex == MAX_SIZE - 1) {
            backIndex = 0;
        } else {
            backIndex++;
        }
        arr[backIndex] = value;
    }

    void pop_front() {
        if (frontIndex == -1) {
            return;
        }
        if (frontIndex == backIndex) {
            frontIndex = -1;
            backIndex = -1;
        } else if (frontIndex == MAX_SIZE - 1) {
            frontIndex = 0;
        } else {
            frontIndex++;
        }
    }

    void pop_back() {
        if (backIndex == -1) {
            return;
        }
        if (frontIndex == backIndex) {
            frontIndex = -1;
            backIndex = -1;
        } else if (backIndex == 0) {
            backIndex = MAX_SIZE - 1;
        } else {
            backIndex--;
        }
    }

    int size() {
        if (frontIndex == -1) {
            return 0;
        }
        if (frontIndex <= backIndex) {
            return backIndex - frontIndex + 1;
        } else {
            return MAX_SIZE - frontIndex + backIndex + 1;
        }
    }

    bool empty() {
        return frontIndex == -1;
    }

    int front() {
        if (frontIndex == -1) {
            return -1; // or throw an exception
        }
        return arr[frontIndex];
    }

    int back() {
        if (backIndex == -1) {
            return -1; // or throw an exception
        }
        return arr[backIndex];
    }
};