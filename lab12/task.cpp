#include <iostream>

#include <cmath>

using namespace std;

class Student
{
    friend class StudentMaxHeap;
private:
    double cgpa;
    int rollNo;

public:
    Student(double cgpa = 0, int rollNo = 0)
    {
        this->cgpa = cgpa;
        this->rollNo = rollNo;
    }
};

class StudentMaxHeap
{
private:
    Student* arr;
    int curSize;
    int maxSize;

public:
    StudentMaxHeap(int size)
    {
        this->curSize = 0;
        this->maxSize = size;
        arr = new Student[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
        ~StudentMaxHeap()
    {
        delete[] arr;
    }
    bool isEmpty()
    {
        return curSize == 0;
    }
    bool isFull()
    {
        return curSize == maxSize;
    }
    bool insert(int rollNo, double cgpa)
    {
        if (curSize == maxSize)
        {
            cout << "full...";
        }
        else
        {
            arr[curSize] = Student(cgpa, rollNo);
            int np = curSize;
            int parent = (np - 1) / 2;
            curSize++;

            while (np != 0 && arr[np].cgpa >= arr[parent].cgpa)
            {
                swap(arr[np], arr[parent]);
                np = parent;
            }
        }
        return true;
    }
    bool remove(int& rollNo, double& cgpa)
    {
        if (curSize == 0)
        {
            cout << "EMpty..";
        }
        rollNo = arr[0].rollNo;
        cgpa = arr[0].cgpa;
        arr[0] = arr[--curSize];
        maxHeaping(0);

        return true;
    }
    void maxHeaping(int i)
    {
        int l_i = 2 * i + 1;
        int r_i = 2 * i + 2;
        int max = i;

        if (l_i < curSize && arr[max].cgpa < arr[l_i].cgpa)
        {
            max = l_i;

        }
        if (r_i < curSize && arr[max].cgpa < arr[l_i].cgpa)
        {
            max = r_i;
        }
        if (max != i)
        {
            swap(arr[max], arr[i]);
            maxHeaping(max);
        }
    }
    void displayStudentList()
    {
        if (isEmpty())
        {
            cout << "Heap is empty..." << endl;
        }

        StudentMaxHeap temp(maxSize);

        while (!isEmpty())
        {
            int rollNo;
            double cgpa;
            remove(rollNo, cgpa);
            cout << "Roll No: " << rollNo << endl;
            cout << "CGPA: " << cgpa << endl;
            temp.insert(rollNo, cgpa);
        }

        while (!temp.isEmpty())
        {
            int rollNo;
            double cgpa;
            temp.remove(rollNo, cgpa);
            insert(rollNo, cgpa);
        }
    }
    void levelOrder()
    {
        if (isEmpty())
        {
            cout << "Heap is empty..." << endl;
        }

        for (int level = 0, count = 0, i = 0; i < curSize; i++)
        {
            cout << arr[i].cgpa << " ";
            count++;

            if (count == pow(2, level))
            {
                cout << endl;
                count = 0;
                level++;
            }
        }

        cout << endl;
    }
};
void menu(StudentMaxHeap& heap)
{
    int choice;
    do
    {
        cout << "1. Insert a new student" << endl;
        cout << "2. Remove (and display) the student with the Max CGPA" << endl;
        cout << "3. Display the list of students (Descending order of CGPA)" << endl;
        cout << "4. Display the list of students (Level-order traversal)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int rollNo;
            double cgpa;
            cout << "Enter Roll Number: ";
            cin >> rollNo;
            cout << "Enter CGPA: ";
            cin >> cgpa;
            if (heap.insert(rollNo, cgpa))
            {
                cout << "Student inserted successfully." << endl;
            }
            else
            {
                cout << "Failed to insert. Heap is full." << endl;
            }
            break;
        }
        case 2:
        {
            int rollNo;
            double cgpa;
            if (heap.remove(rollNo, cgpa))
            {
                cout << "Student with Max CGPA removed - Roll No: " << rollNo << ", CGPA: " << cgpa << endl;
            }
            else
            {
                cout << "Heap is empty! No student to remove." << endl;
            }
            break;
        }
        case 3:
        {
            cout << "List of students in descending order of CGPA:" << endl;
            heap.displayStudentList();
            break;
        }
        case 4:
        {
            cout << "Level-order traversal of students:" << endl;
            heap.levelOrder();
            break;
        }
        case 5:
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }
    } while (choice != 5);
} 
int main()
{
    int maxSize;
    cout << "Enter the maximum number of students in the heap: ";
    cin >> maxSize;

    StudentMaxHeap heap(maxSize);
    menu(heap);
    return 0;
}