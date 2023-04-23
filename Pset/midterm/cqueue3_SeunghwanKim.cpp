// 아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: Kim Seunghwan  분반: ECE20010  Student Number: 22000116

// #include <iostream>
// #include <sstream>
// #include <string>
// #include <cassert>
// using namespace std;
// // size of circular queue, a magic number
// // const int SIZE = 5;

// struct CircularQueue
// {
//     string *items;
//     int front, back;
//     int capa;      // total capacity of the queue
//     string dash;   // dash - a place holder string
//     bool doubling; // if true, increase capacity by 2x, otherwise by 10
//     int incr;      // if doubling is false, increase capacity by incr
//     int shown;     // the max number of items to show
// };

// using cqueue = CircularQueue *;
#include "cqueue.h"

// void free(cqueue q){}; // deallocate queue items and queue itself
// void clear(cqueue q){};      // q->items are cleared, no change in capa
void show_setup(cqueue q){}; // display the current status of the queue
void show_items(cqueue q){};

// 처음 CircularQueue 선언 -> 이게 최종 완성본이라 생각함.
cqueue newCircularQueue(int, int)
{
    cqueue q = new CircularQueue;
    q->front = -1;
    q->back = -1;
    q->capa;
    q->shown;
    q->items = new string[q->capa];
    q->dash = "-";
    q->doubling = true;
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

int size(cqueue q)
{
    if (q->front == -1)
        return 0;
    int _size = (q->back - q->front + q->capa) % q->capa + 1;
    return _size;
}

void resize(cqueue q, int new_capacity)
{
    string *copied = new string[new_capacity];

    if (size(q) == 0)
    {
        // cout << "Queue is empty" << endl;
        return;
    }

    int i, j;
    for (i = q->front, j = 0; j < size(q); i = (i + 1) % q->capa, j++)
        copied[j] = q->items[i];
    copied[j] = q->items[q->back];

    int qsize = size(q);
    delete[] q->items;
    q->items = new string[new_capacity];
    q->capa = new_capacity;
    q->front = 0;
    q->back = qsize - 1;
    // q->items = copiesd;
    for (int i = 0; i < qsize; i++)
    {
        q->items[i] = copied[i];
    }
    delete[] copied;
}

void enqueue(cqueue q, string item)
{
    if (full(q))
    {
        resize(q, q->capa * 2);
    }
    if (q->front == -1)
        q->front = 0;
    q->back = (q->back + 1) % q->capa;
    q->items[q->back] = item;
    cout << "enqueued: " << item << endl;
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

    // resize 과정 추가하기!
    if (q->items->size() == q->capa / 4)
    {
        cout << "변경 전, q->capa : " << q->capa << endl; /////////////  변경 전
        resize(q, q->capa / 2);
    }

    return item;
}

void clear(cqueue q)
{
    delete[] q->items;
    q->items = new string[q->capa];
    for (int i = 0; i < q->capa; i++)
    {
        q->items[i] = "-";
    }
    q->front = -1;
    q->back = -1;
}

void free(cqueue q)
{
    delete[] q->items;
    delete q;
} // deallocate queue items and queue itself

// reset queue with a new capacity & clear queue
void reset(cqueue q, int new_capacity)
{
    delete[] q->items;
    q->capa = new_capacity;
    q->items = new string[new_capacity];
    q->front = -1;
    q->back = -1;
    for (int i = 0; i < q->capa; i++)
    {
        q->items[i] = "-";
    }
}

void show_queue(cqueue q)
{ // display cqueue status
    int i;
    if (empty(q))
        cout << endl
             << "Empty Queue" << endl;
    else
    {
        cout << "Front:Back = [" << q->front << ":" << q->back << "]\n";
        cout << "\tQueue:[ ";
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

// int main()
// {
//     cqueue q = newCircularQueue();
//     dequeue(q);
//     enqueue(q, "a");
//     enqueue(q, "b");
//     enqueue(q, "c");
//     enqueue(q, "d");
//     enqueue(q, "e");
//     enqueue(q, "f");
//     show_queue(q);
//     string item = dequeue(q);
//     cout << "dequeued: " << item << endl;
//     show_queue(q);
//     enqueue(q, "g");
//     show_queue(q);
//     enqueue(q, "h");
//     dequeue(q);
//     dequeue(q);
//     show_queue(q);
//     return 0;
// }
