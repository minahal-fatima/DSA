#include <iostream>

using namespace std;
template <class T>
class Stack
{
    T* data;
    int top;
    const int MAX_SIZE;

public:
    Stack(const int MAX_SIZE = 5) : MAX_SIZE(MAX_SIZE)
    {

        data = new T[MAX_SIZE];

        top = -1;
    }

    ~Stack()
    {
        delete [ ]data;
    }

    void push(const T newItem)
    {
        if(top == MAX_SIZE)
        {
            cout << "Stack overflow";
        }
        else
        {
            data[++top] = newItem;
        }
    }

    void pop()
    {
        if(top == -1)
        {
            cout << "Stack under flow.";
        }
        else
        {
            --top;
        }
    }

    void clear()
    {
        top = -1;
    }

    T getTop() const
    {
        if(top == -1)
        {
            cout << "Stack empty";
        }
        else
        {
            return data[top];
        }
    }

    bool isEmpty() const
    {
        if(top == -1)
        {
            return true;
            cout << "Stack is empty";
        }
    }

    bool isFull() const
    {
        if(!isEmpty())
        {
            return true;
            cout << "Stack is full";
        }
    }

    void showStructure() const
    {
        if(top == -1)
        {
            cout << "Stack is empty..";
        }
        else
        {

        
        for(int i = top; i >= 0; i--)
        {
            cout << data[i] << " " ;
            cout << endl;
        }
    }
    }
};
int main()
{
    Stack<float> a1;
    Stack<float> a2;

    a1.push(5.0);
    a1.push(6.5);

    a1.showStructure();

    a1.push(-3.0);
    a1.push(-8.0);

    a1.showStructure();

    cout << "After removing " << endl;
    a1.pop();
    a1.pop();
    a1.showStructure();

    
    return 0;   
}

