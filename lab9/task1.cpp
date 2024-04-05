#include <iostream>

#include <fstream>

#include <string>

using namespace std;

class Student
{
    friend class StudentList;

private:

    int id;
    string name;
    float cgpa;
    Student* next;

public:

    Student(int id, string name, float cgpa, Student* next=NULL)
    {
        this->id = id;
        this->name = name;
        this->cgpa = cgpa;
        this->next = next;
    }

    void studentDetails() const
    {
        cout << "ID: " << id << endl << "NAME: " << name << endl << "CGPA: " << cgpa << endl;
    }
};

class StudentList
{

private:

    Student* head;
    Student* cursor;

public:

    StudentList()
    {
        head = NULL;
        cursor =  NULL;
    }
    ~StudentList()
    {
        Student* temp = head;
        while(temp != NULL)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void insert(const Student& newStd)
    {
        if(head == NULL)
        {
            head = new Student(newStd);
            cursor = head;
        }
        else
        {
            Student* node = new Student(newStd);
            node->next = cursor->next;
            cursor->next = node;
            cursor = node;
        }
    }

    void remove(int id)
    {
        Student* current = head;

        Student* previous = NULL;

        while(current != NULL && current->id != id)
        {
            previous = current;
            current = current->next;
        }

        if(current != NULL)
        {
            if(previous != NULL)
            {
                previous->next = current->next;

            }
            else
            {
                head = current->next;
            }

            if(cursor == current)
            {
                cursor = current->next;
            }

            delete current;
        }
    }

    void search(float cgpa) const
    {
        Student* current = head;
        while(current != NULL)
        {
            if(current->cgpa == cgpa)
            {
                current->studentDetails();
            }
            else
            {
                cout << "not found";
            }
            current = current->next;
        }
    }

    void replace(const Student& newStd)
    {
        Student* current = head;
        while(current != NULL)
        {
            if(current->id == newStd.id)
            {
                *current = newStd;
                *cursor = newStd;
            }
            else
            {
                insert(newStd);
            }
            current = current->next;
        }
    }

    bool isEmpty()const
    {
        return head == NULL;
    }

    void gotoBeginning()
    {
        cursor = head;
    }

    void gotoEnd()
    {
        while(cursor != NULL && cursor->next != NULL)
        {
            cursor = cursor->next;
        }
    }

    bool gotoNext()
    {
        if(cursor != NULL && cursor->next != NULL)
        {
            cursor = cursor->next;
            return true;
        }
        return false;
    }

    bool gotoPrior()
    {
        if(cursor != NULL && cursor != head)
        {
            Student* temp = head;
            while(temp->next != cursor)
            {
                temp = temp->next;
            }
            cursor = temp;
            return true;

        }
        return false;
    }

    Student getCursor()
    {
        if(cursor != NULL)
        {
            return *cursor;
        }
    }

    void showStructure()const
    {
        if(isEmpty())
        {
            cout << "Empty";
        }
        else
        {
            Student* temp = head;
            while(temp != NULL)
            {
                temp->studentDetails();
                temp = temp->next;
            }
        }
    }
};
int main()
{
    ifstream inf("input.txt");

    if(!inf)
    {
        cout << "file opening failed";
    }

    
    StudentList stdList;
    int id;
    string name;
    float cgpa;

    while(inf >> id)
    {
        inf.ignore();
        getline(inf, name);
        inf >> cgpa;
        Student s(id,name,cgpa);
        stdList.insert(s);

        inf.ignore();
        
    }
    
    stdList.showStructure();
    inf.close();
    return 0;
}