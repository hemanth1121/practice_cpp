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
        (m_irear-m_ifront)>=0 ? status = true : status = false;
        return status;
    }
    
    int getSize()
    {
        int iSize = m_irear - m_ifront;
        if(iSize > 0)
            return iSize;
        else
            return 0;
        
    }
    
    void enQ(int val)
    {
        if(m_irear == m_iMaxSize-1)
        {
            cout << "q overflow, m_irear: " << m_irear << " m_iMaxSize: " << m_iMaxSize << endl;
        }
        else
        {
            if(m_ifront == -1)
                ++m_ifront;
            ++m_irear;
            m_iQ[m_irear] = val;
        }
    }
    
    void deQ()
    {
        if(m_ifront>m_irear || m_ifront == -1)
            cout << "q underflow" << endl;
        else
        {
            ++m_ifront;
        }
    }
    
    void print()
    {
        if(m_ifront>m_irear || m_ifront == -1)
            cout << "q underflow" << endl;
        else
        {
            for(auto i = m_ifront; i <= m_irear; ++i)
                cout << m_iQ[i] << " ";
            
            cout << endl;
        }   
    }
    
    private:
    int m_iMaxSize{}, m_ifront{-1}, m_irear{-1};
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
	
	for(auto i=0 ; i <10 ; ++i)
	{
	    q.deQ();
	}
	
	q.print();
	cout << "q size: " << q.getSize() << std::endl;
	// your code goes here
	return 0;
}
