#include <windows.h>
#include <iostream>
using namespace std;

DWORD WINAPI MyThread(LPVOID param) {
    int n = *(int*)param;  
    cout << "Thread received: " << n << endl;
    return 0;
}

int main() {
    int value = 42;  

    HANDLE thread = CreateThread(NULL, 0, MyThread, &value, 0, NULL);

    if (thread) {
        WaitForSingleObject(thread, INFINITE);
        CloseHandle(thread);  
    } else {
        cout << "Thread creation failed." << endl;
    }

    return 0;
}
