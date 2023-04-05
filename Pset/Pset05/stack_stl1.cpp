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
//         cout << s.top() << " ";
//         s.pop();
//     }
// }

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
} // brute-force version

void printStack_fromBottom(stack<int> s)
{
    if (s.empty())
        return;
    stack<int> t;
    if (s.top() != 0)
        return t.push(s.top());
    else
        return s.pop();
    // else
    //     t.pop();

} // recursion version

int main(void)
{
    int list[] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
    // string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "is"};

    // stack<string> s;
    stack<int> s;
    for (auto item : list)
    {
        // if (item != "-")
        if (item != 0)
        {
            s.push(item);
        }
        else
        {
            cout << s.top() << ' ';
            s.pop();
        }
    }

    cout << "\nsize: " << s.size(); // 2
    cout << "\ntop: " << s.top();   // is  (8)
    cout << "\nstack T: ";
    printStack(s);
    // cout << "\nstack B: ";
    // printStack_fromBottom(s);
    cout << "\nHappy Coding";
}