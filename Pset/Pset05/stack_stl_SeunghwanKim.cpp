// 아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: Kim Seunghwan  분반: ECE20010  Student Number: 22000116

#include <iostream>
#include <stack>
using namespace std;

// void printStack(stack<string> s)
// {
//     stack<string> t;
//     while (!s.empty())
//     {
//         cout << s.top() << ' ';
//         t.push(s.top());
//         s.pop();
//     }
//     while (!t.empty())
//     {
//         s.push(t.top());
//         t.pop();
//     }
// }

// side effect
// void printStack(stack<int> s)
// {
//     while (!s.empty())
//     {
//         cout << s.top() << ' ';
//         s.pop();
//     }
// } // brute-force version

void printStack(stack<string> s)
{
    if (s.empty())
        return;

    // your code here
    string tmp;
    tmp = s.top();
    cout << tmp << ' ';
    s.pop();

    printStack(s);

    s.push(tmp);
}

void printStack_fromBottom(stack<string> s)
{
    if (s.empty())
        return;

    // your code here
    string tmp = s.top();
    s.pop();

    printStack_fromBottom(s);

    cout << tmp << " ";

    s.push(tmp);
}

int main()
{ // stack initialization using range-based for
    // int list[] = {1,2,3,4,5,0,6,0,0,7,0,0,0,8};
    string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};

    stack<string> s;
    for (auto item : list)
    {
        if (item != "-")
            s.push(item);
        else
        {
            cout << s.top() << ' ';
            s.pop();
        }
    }
    cout << "\nsize: " << s.size(); // 2
    cout << "\ntop: " << s.top();   // is (8)
    cout << "\nstack T: ";
    printStack(s);
    cout << "\nstack B: ";
    printStack_fromBottom(s);
    cout << "\nHappy Coding";
}