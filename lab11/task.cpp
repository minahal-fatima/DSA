#include <iostream>

#include <fstream>

#include <string>

using namespace std;

class Student
{
    friend class StudentBST;

private:

    int id;
    string name;
    float fee;
    Student* left;
    Student* right;
public:

    Student(int id, string name, float fee, Student* left=NULL, Student* right=NULL)
    {
        this->id = id;
        this->name = name;
        this->fee = fee;
    }

};

class StudentBST
{
private:

    Student* root;

public:

    StudentBST()
    {
        root = NULL;
    }

    ~StudentBST()
    {
        destroy(root);
    }

bool insert(int id, string name, float fee)
{
    if(root == NULL)
    {
        root = new Student(id, name, fee);
        return true;
    }

    Student* cur = root;
    Student* pre = NULL;
    while(cur != NULL)
    {
        pre = cur;
        if(id < cur->id)
        {
            cur = cur->left;
        }
        else if(id > cur->id)
        {
            cur = cur->right;
        }
        else
        {
            return false;
        }
    }
    if(id < pre->id)
    {
        pre->left = new Student(id, name, fee);
    }
    else
    {
        pre->right = new Student(id, name, fee);;
    }

    return true;
}

void search(int id)
{
    Student* cur = root;
    while(cur != NULL)
    {
        if(id == cur->id)
        {
            cout << "Id: " << cur->id << " " << "Name: " << cur->name << " "
            << "Fee: " << cur->fee << endl;;
        }
        else if(id < cur->id)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
    cout << "Not foud: " << id << endl;
}

void inOrder()
{
    inOrder(root);
}

void inOrder(Student* stree)
{
    if(stree != NULL)
    {

        inOrder(stree->left);
        cout << "Id: " << stree->id << " " << "Name: " << stree->name << " " << "Fee: "
        << stree->fee << endl;
        inOrder(stree->right);
    }
}

void preOrder()
{
    preOrder(root);
}
void preOrder(Student* stree)
{
    if(stree != NULL)
    {
        cout << "Id: " << stree->id << " " << "Name: " << stree->name << " " << "Fee: "
        << stree->fee << endl;
        inOrder(stree->left);
        inOrder(stree->right);
    }
}

void postOrder()
{
    postOrder(root);
}
void postOrder(Student* stree)
{
    if(stree != NULL)
    {
        inOrder(stree->left);
        inOrder(stree->right);
        cout << "Id: " << stree->id << " " << "Name: " << stree->name << " " << "Fee: "
        << stree->fee << endl;
    }
}   

    void destroy(Student* stree)
    {
        if(stree != NULL)
        {
            destroy(stree->left);
            destroy(stree->right);
            delete stree;
        }
    }

    void deleteStudent(int id)
    {
        Student* cur = root;
        Student* pre = NULL;
        while(cur)
        {
            if(cur->id > id)
            {
                cur = cur->left;
            }
            else if(cur->id < id)
            {
                cur = cur->right;
            }
        }
        if(cur->left == NULL && cur->right == NULL)
        {
            delete cur;
        }
        if(cur->right != NULL || cur->left != NULL)
        {

            if(cur->right == NULL && cur->left != NULL)
            {
                swap(cur,cur->left);
                delete cur;
            }
            else if(cur->right == NULL && cur->left != NULL)
            {
                swap(cur, cur->left);
                delete cur;
            }
        }   
        

    }
};

int main()
{
    StudentBST st;
    ifstream inf("input.txt");
    if(!inf)
    {
        cout << "Error in opening a file..";
    }
    int id;
    string name;
    float fee;


    while(inf >> id >> name >> fee)
    {
        if(st.insert(id,name,fee))
        {
            cout << "Student id: " << id << endl << "name: " << name << endl << "fee: " << fee << endl;;
        }
    }
    st.search(5);
    st.inOrder();
    st.preOrder();
    st.postOrder();

    inf.close();
    return 0;
}