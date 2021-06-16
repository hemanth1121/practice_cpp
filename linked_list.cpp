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
        //cout << __func__ << endl;
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
    
    void insertAtBegin(int val)
    {
        //cout << __func__ << endl;
        if(nullptr == head)
        {
            head = new Node(val);
            cout << head->data << endl;
        }
        else
        {
            Node *temp = new Node(val);
            temp->next = head;
            head = temp;
        }
    }
    
    // insert val after the first occurence of key
    void insertAfter(int val, int key)
    {
        cout << __func__ << endl;
        if(bIsEmpty())
        {
            cout << " list is empty, so not adding key" << endl;
        }
        else
        {
            Node *temp = head;
            while(temp != nullptr)
            {
                if(key == temp->data)
                {
                    Node *nextNode = temp->next;
                    temp->next = new Node(val);
                    //temp = temp->next;
                    temp->next->next = nextNode;
                    break;
                }
                temp = temp->next;
            }
        }
    }
    
    // delete the first occurence of key
    void deleteNode(int key)
    {
        cout << __func__ << endl;
        if(bIsEmpty())
        {
            cout << " list is empty, so not able to delete any key" << endl;
        }
        else if(key == head->data)
        {
            Node *temp = head->next;
           delete head;
           head = temp;
        }
        else
        {
            Node *prevNode = nullptr;
            Node *temp = head;
            while(temp != nullptr)
            {
                if(key == temp->data)
                {
                    prevNode->next = temp->next;
                    delete temp;
                    break;
                }
                
                prevNode = temp;
                temp = temp->next;
            }
        }
    }
    
        // delete the first occurence of key
    void deleteNthNodeFromEnd(int n)
    {
        cout << __func__ << endl;
        if(bIsEmpty())
        {
            cout << " list is empty, so not able to delete any key" << endl;
        }
        else
        {
            Node *temp = head;
            Node *refNode = head;
            for(auto i = 1; i<n; ++i)
            {
                if(nullptr != temp)
                {
                    temp = temp->next;
                }
                else
                {
                    cout << "list has fewer elements than " << n << endl;
                    return;
                }
            }
            
            cout << "entered here..." << endl;
            Node *prevNode = nullptr;
            while(temp->next != nullptr)
            {
                temp = temp->next;
                prevNode = refNode;
                refNode = refNode->next;
            }
              
            cout << "nth node from end is " << refNode->data << endl;  
            if(nullptr == prevNode)
            {
                head = refNode->next;
                delete refNode;
            }
            else
            {
                prevNode->next = refNode->next;
                delete refNode;
            }
        }
    }
    
    void middleElement()
    {
        cout << __func__ << endl;
        if(bIsEmpty())
        {
            cout << " list is empty, so no middle element" << endl;
            return;
        }
        else
        {
            Node *fastPtr = head;
            Node *slowPtr = head;
            while(nullptr != fastPtr && nullptr != fastPtr->next)
            {
                fastPtr = fastPtr->next->next;
                slowPtr = slowPtr->next;
            }
            cout << "middle element is " << slowPtr->data << endl;
        }
    }
    
    void middleElementLowerEnd()
    {
        cout << __func__ << endl;
        if(bIsEmpty())
        {
            cout << " list is empty, so no middle element" << endl;
            return;
        }
        else if(nullptr == head->next)
        {
            cout << "middle element is " << head->data << endl;
        }
        else
        {
            Node *fastPtr = head->next;
            Node *slowPtr = head;
            while(nullptr != fastPtr )
            {
                fastPtr = fastPtr->next;
                if(nullptr == fastPtr)
                {
                    break;
                }
                fastPtr = fastPtr->next;
                slowPtr = slowPtr->next;
            }
            cout << "middle element is " << slowPtr->data << endl;
        }
    }
    
    bool bIsEmpty()
    {
        bool isEmpty;
        nullptr == head? isEmpty = true : isEmpty = false;
        return isEmpty;
    }
    
    void reverse()
    {
        if(bIsEmpty())
        {
           cout << " ********** list is empty, no elements to reverse *************" << endl; 
        }
        else
        {
            Node* prev = nullptr, *curr = head, *next = nullptr;
            while(nullptr != curr)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
        }
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
    
    CLinkedList lists, lists1, lists2;
    lists.print();
    lists.deleteNode(5);
    for(auto i=0; i<5; ++i)
    {
        lists.insertAtEnd(i);
    }
    
    lists.print();
    
    for(auto i=10; i>5; --i)
    {
        lists.insertAtBegin(i);
    }
    
    lists.print();
    
    lists.insertAfter(5, 4);
    lists.print();
    
    lists.deleteNode(5);
    lists.print();
    
    lists1.insertAtEnd(1);
    lists1.print();
    lists1.deleteNode(1);
    lists1.print();
    
    lists.deleteNthNodeFromEnd(2);
    lists.print();
    
    lists.deleteNthNodeFromEnd(20);
    lists.print();
    
    lists.deleteNthNodeFromEnd(9);
    lists.print();
    
    lists1.insertAtEnd(1);
    lists1.insertAtEnd(2);
    lists1.insertAtEnd(3);
    lists1.insertAtEnd(4);
    lists1.print();
    lists1.middleElement();
    lists1.middleElementLowerEnd();
    lists1.print();
    
    
    lists.print();
    lists.middleElement();
    lists.middleElementLowerEnd();
    lists.print();
    
    lists2.insertAtEnd(1);
    lists2.insertAtEnd(2);
    lists2.insertAtEnd(3);
    lists2.insertAtEnd(4);
    lists2.deleteNode(3);
    lists2.print();
    
    lists2.reverse();
    lists2.print();
}
