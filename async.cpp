#include <iostream>
#include <chrono>
#include <thread>
#include <future>

using namespace std;
using namespace std::chrono_literals;

int fun()
{
    cout << "waiting...." << this_thread::get_id()<< endl;
    std::this_thread::sleep_for(1s);
    return 100;
}

int main() {
	std::future<int> futureObj = std::async(std::launch::async, fun);

	cout << "main thread...." << this_thread::get_id() << endl;
	
	cout << futureObj.get() << endl;
	
	return 0;
}
