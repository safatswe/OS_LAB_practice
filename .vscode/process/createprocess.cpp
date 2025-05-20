#include <windows.h>
#include <iostream>

using namespace std;

int main() {
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    char applicationPath[] = "C:\\Windows\\System32\\notepad.exe";

    BOOL success = CreateProcessA(
        NULL,
        applicationPath,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    );

    if (!success) {
        cout << " Failed to start application. Error: " << GetLastError() << endl;
        return 1;
    }

    cout << "✅ Notepad launched. Waiting 5 seconds before terminating it..." << endl;

    Sleep(5000); 

    TerminateProcess(pi.hProcess, 0);
    cout << "Notepad has been forcefully terminated." << endl;

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
