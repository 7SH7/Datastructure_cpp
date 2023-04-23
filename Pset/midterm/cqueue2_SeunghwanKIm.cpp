// 아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: Kim Seunghwan  분반: ECE20010  Student Number: 22000116

#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
using namespace std;
// size of circular queue, a magic number
// const int SIZE = 5;

struct CircularQueue
{
    string *items;
    int front;
    int back;
    int capa;
};

using cqueue = CircularQueue *;

// 처음 CircularQueue 선언 -> 이게 최종 완성본이라 생각함.
cqueue newCircularQueue()
{
    cqueue q = new CircularQueue;
    q->front = -1;
    q->back = -1;
    q->capa = 1;
    q->items = new string[q->capa];
    return q;
}

bool full(cqueue q)
{
    if (q->front == 0 && q->back == q->capa - 1)
        return true;
    if (q->front == q->back + 1)
        return true;
    return false;
}

bool empty(cqueue q)
{
    if (q->front == -1)
        return true;
    return false;
}

//// 작업 공간 \\\\ //

int size(cqueue q)
{
    if (q->front == -1)
        return 0;
    int _size = abs(q->back - q->front + q->capa) % q->capa + 1;
    return _size;
}

void resize(cqueue q, int new_capacity)
{
    string *copied = new string[new_capacity];

    int qsize = size(q);

    int i, j;
    for (i = q->front, j = 0; j < qsize; i = (i + 1) % q->capa, j++)
    {
        copied[j] = q->items[i];
    }
    delete[] q->items;
    q->items = copied;
    q->capa = new_capacity;
}

void enqueue(cqueue q, string item)
{
    if (size(q) == q->capa)
        resize(q, q->capa * 2);

    if (full(q))
    {
        cout << "Queue is full" << endl;
        // resize(q, q->capa * 2);
    }
    if (q->front == -1)
        q->front = 0;
    q->back = (q->back + 1) % q->capa;
    q->items[q->back] = item;
    // cout << "enqueued: " << item << endl;
}

string dequeue(cqueue q)
{
    if (empty(q))
    {
        cout << "Queue is empty" << endl;
        return "";
    }
    string item = q->items[q->front];
    if (q->front == q->back)
    {
        q->front = -1;
        q->back = -1;
    } // q has only one item, we reset the q after deleting it.
    else
    {
        q->front = (q->front + 1) % q->capa;
    }
    return item;
}

void display(cqueue q)
{ // display cqueue status
    int i;
    if (empty(q))
        cout << endl
             << "Empty Queue" << endl;
    else
    {
        cout << "Front:Back = [" << q->front << ":" << q->back << "]\n";
        cout << "Items:[ ";
        // cout << endl; // tmp
        for (i = q->front; i != q->back; i = i + 1)
        {
            if (i == q->capa)
            {
                i %= q->capa;
                break;
            }
            cout << q->items[i] << ' ';
        }
        cout << q->items[i];
        cout << " ]\n";
        assert(i <= q->capa);
        // assert(q->back - q->front + 1 || q->front + 1 == q->items.size());
    }
}

int main()
{
    cqueue q = newCircularQueue();
    dequeue(q);
    enqueue(q, "a");
    enqueue(q, "b");
    enqueue(q, "c");
    enqueue(q, "d");
    enqueue(q, "e");
    enqueue(q, "f");
    display(q);
    string item = dequeue(q);
    cout << "dequeued: " << item << endl;
    display(q);
    enqueue(q, "g");
    display(q);
    enqueue(q, "h");
    dequeue(q);
    dequeue(q);
    display(q);
    return 0;
}
