#include <iostream>
using namespace std;

class print
{
    public:
    void display()
    {
        std::cout <<  " sample display" << std::endl;
    }
};
class sample
{
    public:
     sample(const print& prt): m_print(prt)
    {
        cout << "ctro" << endl;
    }
    
    void disp()
    {
       m_print.display(); 
    }
    private:
    print m_print;
};

void foo(sample rhs)
{
    
}
int main() {
	// your code goes here
	
	print obj;
	sample obj1(obj);
	obj1.disp();
	foo(obj);
	return 0;
}
