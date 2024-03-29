#include <iostream>
#include <list>

using namespace std;

template<class T>
class Stack;

int main() {

    return 0;
}

template<class T>
class Stack {
    list<T> data;
public:
    void push(T newItem) { data.push_front(newItem); }

    T pop() { return data.pup_front(); }

    T top() const { return *data.begin(); }

    bool isEmpty() const { return data.size() == 0; }

    int size() const { return data.size(); }

    void clear() { data.clear(); }

};