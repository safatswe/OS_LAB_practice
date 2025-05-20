#include <windows.h>
#include <stdio.h>

int main() {
    if (CopyFile("source.text", "copy.text", FALSE)) {
        printf("File copied successfully.\n");
    } else {
        printf("Failed to copy file. Error: %lu\n", GetLastError());
    }
    return 0;
}
