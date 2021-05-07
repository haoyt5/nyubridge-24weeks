#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Queue {
    std::vector<T> data;
    int frontIndex;
    int length;
public:
    Queue() {
        frontIndex = 0;
        length = 0;
        data.clear();
        data = {0};
    }

    void enqueue(T newItem) {
        if (length > 0) {
            data.push_back(newItem);
            length++;
        }
        if (length == 0) {
            data = {newItem};
            length++;
        }

    }

    void dequeue() {
        if (length > 0) {
            frontIndex++;
            length--;
            if (length == 0) {
                frontIndex = 0;
                data.clear();
                data = {0};
            }
        }

    }

    T front() const {
        return data[frontIndex];
    }

    bool isEmpty() const {
        return length == 0;
    }

    int size() const { return length; }

    void clear() {
        data = {0};
        frontIndex = 0;
        length = 0;
    }


};

int main() {
    Queue<int> q;
    for (int i = 1; i < 6; i++) {
        q.enqueue(i);
    }
    cout << std::boolalpha;
    cout << "front:" << q.front() << " ,size:" << q.size() << " ,isEmpty:" << q.isEmpty() << endl;
    q.dequeue();
    q.dequeue();
    cout << "front:" << q.front() << " ,size:" << q.size() << " ,isEmpty:" << q.isEmpty() << endl;
    q.enqueue(6);
    cout << "front:" << q.front() << " ,size:" << q.size() << " ,isEmpty:" << q.isEmpty() << endl;
    q.dequeue();
    cout << "front:" << q.front() << " ,size:" << q.size() << " ,isEmpty:" << q.isEmpty() << endl;
    q.clear();
    cout << "front:" << q.front() << " ,size:" << q.size() << " ,isEmpty:" << q.isEmpty() << endl;
    q.dequeue();
    cout << "front:" << q.front() << " ,size:" << q.size() << " ,isEmpty:" << q.isEmpty() << endl;
    q.enqueue(2);
    cout << "front:" << q.front() << " ,size:" << q.size() << " ,isEmpty:" << q.isEmpty() << endl;
    return 0;
}