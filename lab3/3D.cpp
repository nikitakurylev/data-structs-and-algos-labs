#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


    int heap[1000000][2];
    int length = 0;
    void Add(int line, int value)
    {
        heap[length][0] = line;
        heap[length][1] = value;
        length++;
    }
    void RemoveAt(int index)
    {
        length--;
        for (int i = index; i < length; i++) {
            heap[i][0] = heap[i + 1][0];
            heap[i][1]=heap[i+1][1];
        }
    }
    void swap(int a, int b)
    {
        int t1 = heap[a][0], t2 = heap[a][1];
        heap[a][0] = heap[b][0];
        heap[a][1] = heap[b][1];
        heap[b][0] = t1;
        heap[b][1] = t2;
    }
    void up(int index)
    {
        if (index > 0 && heap[index][1] < heap[(index - 1) / 2][1])
        {
            swap(index, (index - 1) / 2);
            up((index - 1) / 2);
        }
    }
    void down(int index)
    {
        int i0 = index, left = index * 2 + 1, right = index * 2 + 2;
        if (left < length && heap[i0][1] > heap[left][1])
            i0 = left;
        if (right < length && heap[i0][1] > heap[right][1])
            i0 = right;
        if (i0 != index)
        {
            swap(i0, index);
            down(i0);
        }
    }

int main()
{
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int line = 1;
    string inp;
    while (cin >> inp)
    {
        int x, y;
        if (inp == "push") {
            cin >> x;
            Add(line, x);
            up(length - 1);
        }
        else if (inp == "extract-min") {
            if (length == 0)
                cout << "*\n";
            else
            {
                cout << heap[0][1] << endl;
                swap(0, length - 1);
                RemoveAt(length - 1);
                down(0);
            }
        }
        else if (inp == "decrease-key") {
            cin >> x >> y;
            for (int i = 0; i < length; i++)
                if (heap[i][0] == x)
                {
                    heap[i][1] = y;
                    up(i);
                    break;
                }
        }
        line++;
    }  
}



