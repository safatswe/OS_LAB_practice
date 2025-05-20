#include <iostream>
#include <thread>

using namespace std;

void greet(const string& name, int n) {
    for (int i = 1; i <= n; ++i) {
        cout << "[Thread] Hello, " << name << "! (" << i << ")" << endl;
    }
}

int main() {
    thread t(greet, "safat", 3);
    t.join();
    cout << "[Main] Greeting thread completed." << endl;
    return 0;
}
