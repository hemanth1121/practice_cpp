#include <iostream>
#include <vector>
using namespace std;

class CustomStack
{
    public:
    CustomStack(int sze): m_iMaxSize(sze)
    {
         m_stck.reserve(sze);
    }
    
    bool isEmpty()
    {
        bool status;
        m_iTop == -1 ? status= true : status = false;
    }
    
    int getSize()
    {
        return (m_iTop+1);
    }
    
    void push(int elem)
    {
        if(m_iTop == m_iMaxSize-1)
        {
            cout << "stack overflow" <<endl;
        }
        else
        {
            ++m_iTop;
            m_stck[m_iTop] = elem;
        }
    }
    
    void pop()
    {
        if(m_iTop == -1)
            cout << "stack underflow" << endl;
        else
        {
            --m_iTop;
        }
    }
    
    void print()
    {
        for(auto i = 0; i<=m_iTop; ++i)
        {
            cout << i << " " ;
        }
        cout << endl;
    }
  
  private:
  int m_iMaxSize{}, m_iTop{-1};
  vector<int> m_stck;
};
int main() {
	// your code goes here
	
	CustomStack stck(10);
	
	cout << stck.isEmpty() << endl;
	
	for(auto i=0 ; i <12 ; ++i)
	{
	    stck.push(i);
	}
	
	stck.print();
	
	for(auto i=0 ; i <5 ; ++i)
	{
	    stck.pop();
	}
	
	stck.print();
	
	for(auto i=0 ; i <10 ; ++i)
	{
	    stck.pop();
	}
	
	stck.print();
	return 0;
}
