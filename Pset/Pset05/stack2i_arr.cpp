// 아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: Kim Seunghwan  분반: ECE20010  Student Number: 22000116

#include <iostream>
// #include <stack>
using namespace std;

struct Stack
{
    int *item;
    int N;
    int capacity;
};
using stack = Stack *;
stack newStack(int capacity)
{
    stack s = new Stack;
    s->item = new int[capacity];
    s->N = 0;
    s->capacity = capacity;
    return s;
}
void free(stack s)
{
    delete[] s->item;
    delete s;
}
int size(stack s) { return s->N; }
bool empty(stack s) { return s->N == 0; }
void pop(stack s) { s->N--; }
int top(stack s)
{
    return s->item[s->N - 1];
}
void push(stack s, int item)
{
    s->item[s->N++] = item;
}

void printStack(stack s)
{
    if (empty(s))
        return;

    // your code here
    int tmp;
    tmp = top(s);
    cout << tmp << ' ';
    pop(s);
    printStack(s);
    push(s, tmp);
}

void printStack_fromBottom(stack s)
{
    if (empty(s))
        return;

    // your code here
    int tmp = top(s);
    pop(s);
    printStack_fromBottom(s);
    cout << tmp << " ";
    push(s, tmp);
}

int main()
{ // stack initialization using range-based for
    int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
    // string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    stack s = newStack((sizeof(list) / sizeof(list[0])));
    for (auto item : list)
    {
        if (item != 0)
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