#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex m1, m2;

void threadA() {
    m1.lock();
    cout << "[Thread A] Locked m1" << endl;

    this_thread::sleep_for(chrono::milliseconds(100));
    m2.lock();
    cout << "[Thread A] Locked m2" << endl;
    m2.unlock();
    m1.unlock();
}

void threadB() {
     m2.lock();
    cout << "[Thread B] Locked m2" << endl;

    this_thread::sleep_for(chrono::milliseconds(100));
    m1.lock();
    cout << "[Thread B] Locked m1" << endl;
    m1.unlock();
    m2.unlock();
}

int main() {
    thread t1(threadA);
    thread t2(threadB);

    t1.join();
    t2.join();

    cout << "[Main] Finished (if no deadlock occurred)." << endl;
    return 0;
}
