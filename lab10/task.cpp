#include <iostream>

#include <string>

#include <fstream>

using namespace std;

class Book
{
    friend class BookList;

private:
    int id;
    string title;
    float price;
    Book *next;
    Book *pre;

public:
    Book(int id, string title, float price, Book* next=NULL, Book* pre=NULL)
    {
        this->id = id;
        this->title = title;
        this->price = price;
        this->next = next;
        this->pre = pre;
    }
    void bookDetails()
    {
        cout << "Id: " << id << endl << "Title: " << title << endl << "price: " << price
        << endl;
    }
};

class BookList
{
private:
    Book* head;
    Book* cursor;
    Book* last;

public:

    BookList()
    {
        head = NULL;
        cursor = NULL;
        last = NULL;
    }

    ~BookList()
    {
        Book* cur = head;
        while(cur != NULL)
        {
            Book* next = cur->next;
            delete cur;
            cur = next;
        }
        head = NULL;
        cursor = NULL;
        last = NULL;
    }

    void insert(const Book &newItem)
    {
        if(head == NULL)
        {
           head=cursor=last = new Book(newItem);
        }
        else
        {
            Book* temp = new Book(newItem);
            if(cursor == last)
            {
                last->next = temp;
                temp->pre = last;
                last = temp;
            }
            else
            {
                temp->next = cursor;
                cursor->next = temp;
                temp->next->pre = temp;

            }
            cursor = temp;
        }
    }

    void remove()
    {
        Book* temp1 = cursor;
        if(cursor == head)
        {
            head = cursor = cursor->next;
        }
        if(cursor != NULL)
        {
            cursor->pre = NULL;

        }
        else
        {
            cursor->pre->next = cursor->next;
            if(cursor != last)
            {
                cursor->next->pre = cursor->pre;
            }
            else
            {
                last = cursor->pre;
            }
            cursor = cursor->pre;
        }
        delete temp1;
    }

    void search(string title)
    {
        Book* current = head;
        while(current != NULL)
        {
            if(current->title == title)
            {
                current->bookDetails();
            }
            else
            {
                cout << "Not found";
            }
            current = current->next;
            
        }

    }

    void replace(const Book &newItem)
    {
        while(cursor != NULL)
        {
            cursor->id = newItem.id;
            cursor->title = newItem.title;
            cursor->price = newItem.price;
        }
    }

    bool isEmpty()
    {
        return head = NULL;
    }

    void gotoBeginning()
    {
        cursor = head;
    }

    void gotoEnd()
    {
        cursor = last;
    }

    bool gotoNext()
    {
        while(cursor != NULL && cursor->next != NULL)
        {
            cursor = cursor->next;
            return true;
        }
        return false;
    }

    bool gotoPrior()
    {
        while(cursor != NULL && cursor->pre != NULL)
        {
            cursor = cursor->pre;
            return true;
        }
        return false;
    }

    Book getCursor()
    {
        if(cursor != NULL)
        {
            return *cursor;
        }
    }

    void showStructureForward()const
    {
        Book* current = head;
        while(current != NULL)
        {
            current->bookDetails();
            current = current->next;
        }
        if(head == NULL)
        {
            cout << "Empty";
        }
    }

    void showStructureReverse()const
    {
        
        Book* current = last;
        while(current != NULL)
        {
            current->bookDetails();
            current = current->pre;
        }
        if(last == NULL)
        {
            cout << "Empty";
        }
    }

};
int main()
{

    ifstream inf("input.txt");
    if(!inf)
    {
        cout << "Error in opening a file..";
    }

    int id;
    string title;
    float price;

    BookList b1;
    while(inf >> id)
    {
        inf.ignore();
        getline(inf, title);
        inf >> price;
        
        Book b(id,title,price,NULL,NULL);
        b1.insert(b);
        
        inf.ignore();
    }

    b1.showStructureForward();
    b1.showStructureReverse();
    inf.close();
    return 0;
}