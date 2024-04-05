#include <iostream>

using namespace std;

template <class T>

class Queue
{
    T* data;
    int front;
    int rear;
    const int MAX_SIZE;

public:

    Queue(const int MAX_SIZE  = 5) : MAX_SIZE(MAX_SIZE)
    {
        data = new T[MAX_SIZE];
        front = -1;
        rear = -1;
    }

    ~Queue()
    {
        delete [] data;
    }

    void enQueue(const T newItem)
    {
        if((rear + 1) % MAX_SIZE == front)
        {
            cout << "Queue is full";
        }
        else
        {
            if(front == -1)
            {
                front = 0;
            }
            rear = (rear + 1) % MAX_SIZE;

            data[rear] = newItem;
        }
    }

    void deQueue()
    {
        if(front == -1)
        {
            cout << "Queue is empty";
        }
        else
        {
            if(front == rear)
            {
                front = rear = -1;
            }
            else
            {

                front = (front + 1) % MAX_SIZE;
            }
        }
    }

    void clear()
    {
        front = -1;
        rear = -1;
    }

    T getFront() const
    {
        return data[front];
    }

    T getRear() const
    {
        return data[rear];
    }

    bool isEmpty() const
    {
        if(front == -1 && rear == -1)
        {
            return true;
        }
    }

    bool isFull() const
    {
        if((rear + 1)%MAX_SIZE == front)
        {
            return true;
        }
    }

    void showStructure() const
    {
        if(front == -1 && rear == -1)
        {
            cout << "queue is empty";
        }
        else
        {

            for(int i = front; i <= rear; i++)
            {
                cout << data[i] << endl;
            }
        }
    }
};
int main()
{
    Queue<float>a1;

    a1.enQueue(5.0);
    a1.enQueue(6.5);
    a1.showStructure();

    a1.enQueue(-3.0);
    a1.enQueue(-8.0);
    a1.showStructure();

    cout << "after removing " << endl;

    a1.deQueue();
    a1.deQueue();
    a1.showStructure();

    return 0;
}