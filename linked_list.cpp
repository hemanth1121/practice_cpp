#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

class Node
{
 public:
    Node(int val): data(val)
    {
        
    }
    int data;
    Node *next{nullptr};
};

class CLinkedList
{
    public:
    void insertAtEnd(int val)
    {
        cout << __func__ << endl;
        if(nullptr == head)
        {
            head = new Node(val);
            cout << head->data << endl;
        }
        else
        {
            Node *temp = head;
            while(nullptr != temp->next)
                temp = temp->next;
            temp->next = new Node(val);
            cout << temp->next->data << endl;
        }
    }
    
    bool bIsEmpty()
    {
        bool isEmpty;
        nullptr == head? isEmpty = true : isEmpty = false;
        return isEmpty;
    }
    
    void print()
    {
        if(bIsEmpty())
        {
           cout << " ********** list is empty, no elements to display *************" << endl; 
        }
        else
        {
        Node *temp = head;
        cout << " ********** Displaying list elements *************" << endl;
        do 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }while(nullptr != temp);
        cout << endl;
        }
    }
    private:
    Node *head{nullptr};
};

int main()
{
    cout << "*********************** linked list program in c++***************************" << endl;
    
    CLinkedList lists;
    lists.print();
    for(auto i=0; i<5; ++i)
    {
        lists.insertAtEnd(i);
    }
    
    lists.print();
}
