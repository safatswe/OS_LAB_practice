#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hFile = CreateFile(
        "example.txt",         // File name
        GENERIC_WRITE,         // Write access
        0,                     // No sharing
        NULL,                  // Default security
        CREATE_ALWAYS,         // Always create a new file
        FILE_ATTRIBUTE_NORMAL, // Normal file
        NULL);                 // No template

    if (hFile == INVALID_HANDLE_VALUE) {
        printf("Failed to create file. Error: %lu\n", GetLastError());
    } else {
        printf("File created successfully.\n");
        CloseHandle(hFile);
    }
    return 0;
}
