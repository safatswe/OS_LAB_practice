#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;
mutex mtx;

void increment() {
    for (int i = 0; i < 100000; i++) {
        mtx.lock();
        counter++;  // Critical section protected by mutex
        mtx.unlock();
    }
}

int main() {
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout << "Final counter value (with mutex): " << counter << endl;
    return 0;
}
