#include <iostream>
#include <list>

using namespace std;

template<class T>
class Queue {
    list<T> data;
public:
    void enqueue(T newItem) { data.push_back(newItem); }

    void dequeue() { data.pop_front(); }

    bool isEmpty() const { return data.size() == 0; }

    int size() const { return data.size(); }

    void clear() { data.clear(); }


};

int main() {
    Queue<int> q;
    cout << std::boolalpha;
    cout << "Size: " << q.size() << " isEmpty: " << q.isEmpty() << endl;
    q.enqueue(20);
    q.enqueue(50);
    q.enqueue(30);
    cout << "Size: " << q.size() << " isEmpty: " << q.isEmpty() << endl;
    q.dequeue();
    cout << "Size: " << q.size() << " isEmpty: " << q.isEmpty() << endl;
    q.clear();
    cout << "Size: " << q.size() << " isEmpty: " << q.isEmpty() << endl;
    return 0;
}

