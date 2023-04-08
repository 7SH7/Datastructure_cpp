// 아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: Kim Seunghwan  분반: ECE20010  Student Number: 22000116

#include <iostream>
#include <vector>
using namespace std;

struct Stack
{
    vector<string> item;
};
using stack = Stack *;

void free(stack s)
{
    delete s;
}

int size(stack s)
{
    // cout << size() << endl;
    return s->item.size();
}

bool empty(stack s)
{
    return s->item.empty();
}

// 감소하는 것은 표현 안 해도 괜춘함.
void pop(stack s)
{
    // your code here
    if (size(s->item) == 0)
        return;
    s->item.pop_back();
}

string top(stack s)
{
    // your code here
    if (size(s) == 0)
        return NULL;
    return s->item.back();
}

void push(stack s, string item)
{
    // your code here
    s->item.push_back(item);

    // cout << endl
    //      << "push - size : " << s->item.size() << " - capacity : " << s->item.capacity() << endl;
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
    string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};

    stack s = new Stack(); // 초기화 필수

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
    cout << "\nstack B: ";
    printStack_fromBottom(s);
    cout << "\nHappy Coding";
}
