#include <iostream>
#include <chrono>
#include <thread>
#include <future>

using namespace std;
using namespace std::chrono_literals;

void fun(std::promise<int>* prmse)
{
    cout << "waiting...." << endl;
    std::this_thread::sleep_for(1s);
    prmse->set_value(100);
    std::this_thread::sleep_for(1s);
    cout << "value is set now...." << endl;
}

int main() {
	// your code goes here
	
	std::promise<int> promiseObj;
	std::future<int> futureObj = promiseObj.get_future();
	
	std::thread th(fun, &promiseObj);
	cout << "main thread...." << endl;
	
	cout << futureObj.get() << endl;

    cout << "joinable check: " << th.joinable() << endl;	
	if(th.joinable())
	    th.join();
	    
	
	return 0;
}
