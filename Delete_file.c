#include <windows.h>
#include <stdio.h>

int main() {
    if (DeleteFile("example.txt")) {
        printf("File deleted successfully.\n");
    } else {
        printf("Failed to delete file. Error: %lu\n", GetLastError());
    }
    return 0;
}
