// 아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: Kim Seunghwan  분반: ECE20010  Student Number: 22000116

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct Stack
{
    vector<T> item;
};

template <typename T>
using stack = Stack<T> *;

template <typename T>
void free(stack<T> s)
{
    delete s;
}

template <typename T>
T top(stack<T> s)
{
    return s->item.back();
}

template <typename T>
int size(stack<T> s)
{
    return s->item.size();
}

template <typename T>
bool empty(stack<T> s)
{
    return s->item.empty();
}

template <typename T>
void pop(stack<T> s)
{
    // your code here
    if (size(s->item) == 0)
        return;
    s->item.pop_back();
}

template <typename T>
void push(stack<T> s, T item)
{
    // your code here
    s->item.push_back(item);

    cout << "push - size : " << s->item.size() << " - capacity : " << s->item.capacity() << endl;
}

template <typename T>
void printStack(stack<T> s)
{
    while (!empty(s))
    {
        cout << top(s) << ' ';
        pop(s);
    } // stack is empty now
}

int main()
{ // stack initialization using range-based for
    // int list[] = {1,2,3,4,5,0,6,0,0,7,0,0,0,8};
    string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};

    stack<string> s = new Stack<string>(); // 초기화 필수

    for (auto item : list)
    {
        if (item != "-")
            push(s, item);
        else
        {
            cout << "top: " << top(s) << ' ';
            pop(s);
        }
    }

    cout << "\nsize: " << size(s); // 2
    cout << "\ntop: " << top(s);   // is (8)
    cout << "\nstack T: ";
    printStack(s);
    cout << "\nHappy Coding";
}
