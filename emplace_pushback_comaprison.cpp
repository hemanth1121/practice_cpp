#include <iostream>
#include <vector>

using namespace std;
class sample
{
public:
    sample(int x, int y):
    m_x(x), m_y(y)
    {
        cout << "ctor" << endl;
    }
    
    sample(const sample& rhs)
    {
        cout << "copy ctor " << endl;
        m_x = rhs.m_x;
        m_y = rhs.m_y;
    }
    
    sample(sample&& rhs) noexcept
    {
        cout << "move ctor " << endl;
        m_x = std::move(rhs.m_x);
        m_y = std::move(rhs.m_y);
    }
    
private:
    int m_x, m_y;
};


int main()
{
    //sample obj(10, 20);
    std::vector<sample> pushVector, emplaceVector;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "++++++++++++++push+++++++++++++++++" << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    //pushVector.reserve(10);
    //emplaceVector.reserve(10);
    for(auto i=0; i<2; ++i)
    {
        cout << "pushVector.capacity() : " << pushVector.capacity() << endl;
         pushVector.push_back(sample(i, i+1));
         //cout << "i : " << endl;
    }

    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "++++++++++++++emplace+++++++++++++++++" << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    for(auto i=0; i<2; ++i)
    {
        emplaceVector.emplace_back(i, (i+1));
    }
    return 0;
}
