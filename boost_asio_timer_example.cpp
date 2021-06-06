#include <iostream>
#include <chrono>
#include <thread>
#include <boost/function.hpp>
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <condition_variable>

using namespace std;
std::condition_variable m_cvRequestJobTimeout;
std::mutex m_RequestJobTimeoutMutex;

boost::asio::io_service io_service;
boost::posix_time::seconds interval(1);  // 1 second
boost::asio::deadline_timer timer(io_service, interval);
bool m_flag = false;

void tick(const boost::system::error_code& /*e*/) {

    std::cout << "tick" << std::endl;

    // Reschedule the timer for 1 second in the future:
    timer.expires_at(timer.expires_at() + interval);
    // Posts the timer event
    if(!m_flag)
        timer.async_wait(tick);
       
     return;
}

void fun()
{
    timer.async_wait(tick);
    // Enter IO loop. The timer will fire for the first time 1 second from now:
    io_service.run();
    timer.cancel();
}
void func1()
{
    std::unique_lock<std::mutex> lock(m_RequestJobTimeoutMutex);
    while(m_flag){
    m_cvRequestJobTimeout.wait_for(lock, std::chrono::milliseconds(1));
    boost::this_thread::sleep_for(boost::chrono::milliseconds(10000000));
    }
}
int main(void) {

    boost::thread th(boost::bind(&func1));
    // Schedule the timer for the first time:
cout << "thread is running... " << endl;
    sleep(10);
    m_flag = true;
    th.interrupt();
    th.join();
    
    return 0;
}
