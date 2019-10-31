#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include <iostream>

using namespace std;
namespace sc = boost::statechart;

struct start;

struct sActive;
struct sStopped;

struct evStartStop: sc::event<evStartStop> {};
struct evReset: sc::event<evReset> {};

struct Machine: sc::state_machine<Machine, sActive>
{
        Machine(){
            cout << "Machine -> entry" << endl;
        }
        ~Machine(){
            cout << "Machine -> exit" << endl;
        }
};

struct sActive: sc::simple_state<sActive, Machine, sStopped>
{
        sActive()
        {
            cout << "sActive -> entry "<< endl;
        }
        ~sActive()
        {
            cout << "sActive -> exit "<< endl;
        }
        typedef sc::transition< evReset, sActive > reactions;
};
struct sRunning;
struct sStopped: sc::simple_state<sStopped, sActive>
{
    
        sStopped()
        {
            cout << "sStopped -> entry "<< endl;
        }
        ~sStopped()
        {
            cout << "sStopped -> exit "<< endl;
        }
        typedef sc::transition<evReset, sRunning > reactions;
};

struct sRunning: sc::simple_state<sRunning, sActive>
{
        sRunning()
        {
            cout << "sRunning -> entry "<< endl;
        }
        ~sRunning()
        {
            cout << "sRunning -> exit "<< endl;
        }
        typedef sc::transition<evReset, sStopped > reactions;
    
};
int main()
{
    Machine myMachine;
    myMachine.initiate();
    myMachine.process_event(evStartStop());
    myMachine.process_event(evStartStop());
    myMachine.process_event(evReset());
}
