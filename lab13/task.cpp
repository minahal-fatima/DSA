#include <iostream>
#include <string>

using namespace std;

class HashTable
{
private:
    string* table; 
    int size;      
    int curSize;  
public:
    HashTable(int size)
    {
        this->size = size;
        this->curSize = 0;

        table = new string[size];

        for (int i = 0; i < size; i++)
        {
            table[i] = "EMPTY";
        }
    }

    bool isEmpty()
    {
        return curSize == 0;
    }

    bool isFull()
    {
        return curSize == size;
    }

    double loadFactor()
    {
        return ((double)curSize / (double)size) * 100;
    }

    int value(string name)
    {
        int temp = 0;
        for (int i = 0; i < name.length(); i++)
        {
            temp = temp + name[i];
        }
        return temp;
    }

    bool insert(string name)
    {
        if (isFull())
        {
            cout << "Hash table is full" << endl;
            return false;
        }
        else
        {
            int h_x = value(name) % size;
            int index = h_x;

            while (table[index] != "EMPTY")
            {
                index = (index + 1) % size;
            }

            table[index] = name;
            curSize++;

            return true;
        }
    }

    bool search(string name)
    {
        if (isEmpty())
        {
            cout << "No values" << endl;
            return false;
        }
        else
        {
            int h_x = value(name) % size;
            int index = h_x;

            while (table[index] != "EMPTY")
            {
                if (table[index] == name)
                {
                    return true;
                }
                index = (index + 1) % size;
            }

            return false;
        }
    }

    bool remove(string name)
    {
        if (isEmpty())
        {
            cout << "No values to remove..." << endl;
            return false;
        }
        else
        {
            int h_x = value(name) % size;
            int index = h_x;

            while (table[index] != "EMPTY")
            {
                if (table[index] == name)
                {
                    table[index] = "EMPTY";
                    curSize--;
                    return true;
                }
                index = (index + 1) % size;
            }

            return false;
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "INDEX.." << i<<": ";
            if (table[i] == "EMPTY")
            {
                cout << "empty..\n";
            }
            else
            {
                cout << table[i] << endl;
            }
        }
    }

    ~HashTable()
    {
        delete[] table;
    }
    void menu()
    {

        int tableSize;
        cout << "Enter the size of the hash table: ";
        cin >> tableSize;

        HashTable hashTable(tableSize);

        int choice;
        string name;

        do
        {
            cout << "\n1. Insert a name\n2. Search for a name\n3. Remove a name\n4. Display the table\n5. Display the load factor\n6. Exit\nEnter your choice: ";
            cin >> choice;

            if (choice == 1)
            {
                cout << "Enter the name to insert: ";
                cin >> name;
                hashTable.insert(name);
            }
            else if (choice == 2)
            {
                cout << "Enter the name to search: ";
                cin >> name;
                if (hashTable.search(name))
                {
                    cout << name << " Founded\n";
                }
                else
                {
                    cout << name << " not founded\n";
                }
            }
            else if (choice == 3)
            {
                cout << "Enter the name to remove: ";
                cin >> name;
                if (hashTable.remove(name))
                {
                    cout << name << " removed\n";
                }
                else
                {
                    cout << name << " not in table\n";
                }
            }
            else if (choice == 4)
            {
                hashTable.display();
            
            }
            else if (choice == 5)
            {
                cout << "Load Factor: " << hashTable.loadFactor() <<"%"<< endl;
            }
            else if (choice == 6)
            {
                cout << "Exiting program.\n";
            }
            else
            {
                cout << "Invalid choice.\n Enter again: \n";
            }

        } while (choice != 6);

    }
};



int main()
{
    HashTable m(5);
    m.menu();

    return 0;
}