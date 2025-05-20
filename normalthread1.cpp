#include <iostream>
#include <thread>

using namespace std;

void sayHello() {
    cout << "[Thread] Hello from thread!" << endl;
}

int main() {
    thread t(sayHello);  // Create thread
    t.join();            // Wait for it to finish
    cout << "[Main] Thread finished." << endl;
    return 0;
}
