// 아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: Kim Seunghwan  분반: ECE20010  Student Number: 22000116

#include <iostream>
// #include <string>
using namespace std;

struct Stack
{
    string *item;
    int N;
    int capacity;
};
using stack = Stack *;

stack newStack(int capacity = 1)
{
    stack s = new Stack;
    s->item = new string[capacity];
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

string top(stack s)
{
    return s->item[s->N - 1];
}

// pop 은  1/4 줄으면, 1/2배 줄기
// push는 입력되면 2배만큼 크기 증가

void pop(stack s)
{
    s->N--;
    // your code here
    int tmp_N = s->N;
    int tmp_capacity = s->capacity;

    if (s->N <= s->capacity / 4)
    {
        delete[] s;
        s = newStack(tmp_capacity / 2);
        s->N = tmp_N;
    }

    cout << endl
         << "push - size : " << s->N << " - capacity : " << s->capacity;
}

void push(stack s, string item)
{
    // your code jere
    s->item[s->N++] = item;

    int tmp_N = s->N;
    int tmp_capacity = s->capacity;
    if (s->N == s->capacity)
    {
        delete[] s;
        s = newStack(tmp_capacity * 2);
        s->N = tmp_N;
    }

    // cout << endl
    //      << "push - size : " << s->N << " - capacity : " << s->capacity;
}

void printStack(stack s)
{
    if (empty(s))
        return;

    // your code here
    string tmp;
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
    string tmp = top(s);
    pop(s);
    printStack_fromBottom(s);
    cout << tmp << " ";
    push(s, tmp);
}

int main()
{ // stack initialization using range-based for
    // int list[] = {1,2,3,4,5,0,6,0,0,7,0,0,0,8};
    // string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    string list[] = {"to", "be", "or", "not", "to"};

    stack s = newStack(sizeof(list) / sizeof(list[0])); // 이게 초기화.
    cout << endl
         << "push - size : " << s->N << " - capacity : " << s->capacity;
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
    cout << endl
         << "push - size : " << s->N << " - capacity : " << s->capacity;
    pop(s);
    pop(s);
    pop(s);
    pop(s);

    cout << endl
         << "push - size : " << s->N << " - capacity : " << s->capacity;
    // cout << "\nsize: " << size(s); // 2
    // cout << "\ntop: " << top(s);   // is (8)
    // cout << "\nstack T: ";
    // printStack(s);
    // cout << "\nstack B: ";
    // printStack_fromBottom(s);
    cout << "\nHappy Coding";
}