#include <iostream>
#include <vector>
using namespace std;

class CustomQueue
{
    public:
    CustomQueue(int sze):m_iMaxSize(sze)
    {
        m_iQ.reserve(sze);
    }
    
    bool isEmpty()
    {
        bool status = false;
        m_iCount > 0 ? status = false : status = true;
        return status;
    }
    
    int getSize()
    {
        return m_iCount;
    }
    
    void enQ(int val)
    {
        if(m_iCount == m_iMaxSize)
        {
            cout << "q overflow, m_iCount: " << m_iCount << endl;
        }
        else
        {
            if(m_ifront == -1)
                ++m_ifront;
            m_irear = (m_irear + 1)%m_iMaxSize;
            m_iQ[m_irear] = val;
            ++m_iCount;
        }
    }
    
    void deQ()
    {
        if(m_iCount <= 0)
            cout << "q underflow" << endl;
        else
        {
            m_ifront = (m_ifront+1)%m_iMaxSize;
            --m_iCount;
        }
    }
    
    void print()
    {
        if(m_iCount <= 0)
            cout << "q underflow" << endl;
        else
        {
            for(auto i = 0; i < m_iCount; ++i)
                cout << m_iQ[(i+m_ifront)%m_iMaxSize] << " ";
            
            cout << endl;
        }   
    }
    
    private:
    int m_iMaxSize{}, m_ifront{-1}, m_irear{-1}, m_iCount{0};
    vector<int> m_iQ;
};

int main() {
    
    CustomQueue q(10);
    cout << std::boolalpha << "isEmpty: " << q.isEmpty() << endl;
    cout << "q size: " << q.getSize() << std::endl;
    
    for(auto i=0 ; i <12 ; ++i)
	{
	    q.enQ(i);
	}
	
	q.print();
	cout << "q size: " << q.getSize() << std::endl;
	
	for(auto i=0 ; i <5 ; ++i)
	{
	    q.deQ();
	}
	
	q.print();
	cout << "q size: " << q.getSize() << std::endl;
	
	for(auto i=0 ; i < 7 ; ++i)
	{
	    q.enQ(i);
	}
	
	q.print();
	cout << "q size: " << q.getSize() << std::endl;
	
	for(auto i=0 ; i <10 ; ++i)
	{
	    q.deQ();
	}
	
	q.print();
	cout << "q size: " << q.getSize() << std::endl;
	// your code goes here
	return 0;
}
