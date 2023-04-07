// 아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: Kim Seunghwan  분반: ECE20010  Student Number: 22000116

#include <iostream>
using namespace std;

template <typename T>
struct Stack
{
    T *item;
    int N;
    int capacity;
};

template <typename T>
using stack = Stack<T> *;

template <typename T>
stack<T> newStack(int capacity)
{
    stack<T> s = new Stack<T>;
    s->item = new T[capacity];
    s->N = 0;
    s->capacity = capacity;
    return s;
}

template <typename T>
void free(stack<T> s)
{
    delete[] s->item;
    delete s;
}

template <typename T>
int size(stack<T> s) { return s->N; }

template <typename T>
bool empty(stack<T> s) { return s->N == 0; }

template <typename T>
void pop(stack<T> s) { s->N--; }

template <typename T>
T top(stack<T> s)
{
    return s->item[s->N - 1];
}

template <typename T>
void push(stack<T> s, T item)
{
    s->item[s->N++] = item;
}

template <typename T>
void printStack(stack<T> s)
{
    if (empty(s))
        return;

    // your code here
    T tmp;
    tmp = top(s);
    cout << tmp << ' ';
    pop(s);
    printStack(s);
    push(s, tmp);
}

template <typename T>
void printStack_fromBottom(stack<T> s)
{
    if (empty(s))
        return;

    // your code here
    T tmp = top(s);
    pop(s);
    printStack_fromBottom(s);
    cout << tmp << " ";
    push(s, tmp);
}

int main()
{ // stack initialization using range-based for
    // int list[] = {1,2,3,4,5,0,6,0,0,7,0,0,0,8};
    string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};

    int _size = sizeof(list) / sizeof(list[0]);
    stack<string> s = newStack<string>(_size);

    for (auto item : list)
    {
        if (item != "-")
            push(s, item);
        else
        {
            cout << top(s) << ' ';
            pop(s);
        }
    }
    cout << "\nsize: " << size(s); // 2
    cout << "\ntop: " << top(s);   // is (8)
    cout << "\nstack T: ";
    printStack(s);
    cout << "\nstack B: ";
    printStack_fromBottom(s);
    cout << "\nHappy Coding";
}