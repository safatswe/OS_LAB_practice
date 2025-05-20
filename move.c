#include <windows.h>
#include <stdio.h>

int main() {
    if (MoveFile("old.text", "new.text")) {
        printf("File moved/renamed successfully.\n");
    } else {
        printf("Failed to move/rename file. Error: %lu\n", GetLastError());
    }
    return 0;
}
