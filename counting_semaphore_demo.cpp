
// C++ program to demonstrate working of Semaphores
#include <iostream>
#include <thread>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

sem_t m_mutex;
bool m_bDone = false;

void workerThread()
{
    while(!m_bDone){
	//wait
	cout << "waiting for a signal..." << endl;
	sem_wait(&m_mutex);
	cout << "received a signal..." << endl;

	//critical section
	//sleep(2);
    }
    cout << "exiting worker thread..." << endl; 
}

void notifyThread()
{
    cout << "posting a signal..." << endl;
    //sleep(2);
	sem_post(&m_mutex);
}

int main()
{
	sem_init(&m_mutex, 0, 0);
	std::thread t1(workerThread), t2;
	sleep(2);
	//t2 = std::thread(workerThread);
	for(auto i=0; i<2; ++i)
	{
	    notifyThread();
	}

    cout << "after " << endl;

    sleep(5);
    cout << "post a signal so that thread comes out of wait" << endl;
    sem_post(&m_mutex);
    m_bDone = true;
	if(t1.joinable())
	{ 
	    cout << "joining a thread" << endl;
	    t1.join();
	}
	
	cout << "after join" << endl;
	sem_post(&m_mutex);
	sem_destroy(&m_mutex);
	return 0;
}

