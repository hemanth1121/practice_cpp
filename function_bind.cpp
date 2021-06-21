/*
*https://oopscenities.net/2012/02/24/c11-stdfunction-and-stdbind/
*/
#include <functional>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
void execute(const vector<function<void ()>>& fs)
{
    for (auto& f : fs)
        f();
}
 
void plain_old_func()
{
    cout << "I'm an old plain function" << endl;
}
 
class functor
{
    public:
        void operator()() const
        {
            cout << "I'm a functor" << endl;
        }
};
 
 
void show_text(const string& t)
{
    cout << "TEXT: " << t << endl;
}

int main()
{
    vector<function<void ()>> x;
    x.push_back(plain_old_func);
     
    functor functor_instance;
    x.push_back(functor_instance);
    x.push_back([] ()
    {
        cout << "HI, I'm a lambda expression" << endl;
    });
    
    function <void ()> f = bind(show_text, "Bound function");
    x.push_back(f); 
     
    execute(x);
}
