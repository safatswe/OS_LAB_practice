#include <windows.h>
#include <iostream>
using namespace std;

HANDLE mutex1, mutex2;

DWORD WINAPI Thread1(LPVOID) {
    WaitForSingleObject(mutex1, INFINITE);
    cout << "Thread 1 acquired mutex1" << endl;

    Sleep(1000);  

    cout << "Thread 1 waiting for mutex2" << endl;
    WaitForSingleObject(mutex2, INFINITE);  
    cout << "Thread 1 acquired mutex2" << endl;

    ReleaseMutex(mutex2);
    ReleaseMutex(mutex1);

    return 0;
}

DWORD WINAPI Thread2(LPVOID) {
    WaitForSingleObject(mutex2, INFINITE);
    cout << "Thread 2 acquired mutex2" << endl;

    Sleep(1000);  
    cout << "Thread 2 waiting for mutex1" << endl;
    WaitForSingleObject(mutex1, INFINITE);  
    cout << "Thread 2 acquired mutex1" << endl;

    ReleaseMutex(mutex1);
    ReleaseMutex(mutex2);

    return 0;
}

int main() {
    mutex1 = CreateMutex(NULL, FALSE, NULL);
    mutex2 = CreateMutex(NULL, FALSE, NULL);

    HANDLE t1 = CreateThread(NULL, 0, Thread1, NULL, 0, NULL);
    HANDLE t2 = CreateThread(NULL, 0, Thread2, NULL, 0, NULL);

    WaitForSingleObject(t1, INFINITE);
    WaitForSingleObject(t2, INFINITE);

    CloseHandle(mutex1);
    CloseHandle(mutex2);
    CloseHandle(t1);
    CloseHandle(t2);

    return 0;
}
