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

cqueue newCircularQueue(int capa, int shown)
{
    cqueue q = new CircularQueue;
    q->front = -1;
    q->back = -1;
    q->capa = 4;
    q->shown = 32;
    q->items = new string[q->capa];
    q->dash = "-";
    q->doubling = true;
    q->incr = 0; // if doubling is false, increase capacity by incr
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
        // resize(q, q->capa * 2);
        // 밑의 5줄은 chatgpt 내용임. 삭제 가능.
        int new_capacity = q->capa * 2;
        if (q->back < q->front)
        {
            new_capacity = q->back + q->capa + 1; // wrap around case
        }
        resize(q, new_capacity);
    }
    if (q->front == -1)
        q->front = 0;
    q->back = (q->back + 1) % q->capa;
    q->items[q->back] = item;
    // cout << "enqueued: " << item << endl;
}

string dequeue(cqueue q)
{
    if (size(q) == 0)
    {
        // cout << "Queue is empty" << endl;
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
        // q->back = (q->back - q->capa + q->capa) % q->capa + 1;
    }

    // resize 과정 추가하기!

    if (size(q) == q->capa / 4)
    {
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
    int i, j;
    if (empty(q))
        cout << "\tQueue: [   ]";
    else
    {
        // cout << "Front:Back = [" << q->front << ":" << q->back << "]\n";
        cout << "\tQueue:[ ";
        ////  이 사이 공간만 바꾸면 ㅇㅋㅇㅋ
        for (i = q->front, j = 0; i != (1 + q->back) % q->capa, j < size(q); i = i + 1, j++)
        {
            cout << ' ' << q->items[i] << ' ';
        }
        ////
        cout << " ]\n";
        assert(i <= q->capa);
    }
    cout << endl;
}

void show_items(cqueue q)
{
    cout << "\tItems: [ ";
    int i, j, k;

    // if q->size가 q->ins 보다 더 커. 이러한 경우, q->size/2만 뜨고 실행은 계속 되고, 마지막 - q->size/2 만큼 뜨도록 코드 짜면 되지 않으려나??
    if (q->shown >= size(q))
    {
        for (int i = 0; i < q->capa; i++)
        {
            if (i == q->front)
            {
                for (j = q->front, k = 0; j != (1 + q->back) % q->capa, k < size(q); j = j + 1, k++)
                {
                    cout << ' ' << q->items[j] << ' ';
                    i++;
                }
                i--;
            }
            else
            {
                cout << " - ";
            }
        }

        cout << " ]" << endl;
    }
    else if (q->shown < size(q))
    {

        for (int i = 0; i < q->capa; i++)
        {
            int check_lower = 0;
            if (i == q->front)
            {
                for (j = q->front, k = 0; j != (1 + q->back) % q->capa, k < size(q); j = j + 1, k++)
                {
                    check_lower++;
                    if (check_lower <= q->shown / 2)
                        cout << ' ' << q->items[j] << ' ';
                    i++;
                }
                i--;
                check_lower = 0;
                cout << "  ...  ";
            }
            else
            {
                check_lower++;
                if (check_lower < q->shown / 2)
                    cout << " - ";
            }
        }

        cout << " ]" << endl;
    }
}

void show_setup(cqueue q)
{
    cout << "\tSetup: Front:Back = [" << q->front << ":" << q->back << "], ";
    cout << " size =" << size(q) << ", "
         << "capacity=" << q->capa << ", ";

    cout << "resize by ";
    if (q->doubling == true)
    {
        cout << "2x";
    }
    else if (q->doubling == false)
    {
        cout << q->incr;
    }

    cout << ", show n=" << q->shown << endl;

} // display the current status of the queue
