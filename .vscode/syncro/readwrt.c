#include <stdio.h>

int writing = 0;       
int readerCount = 0;   

void startReading() {
    if (writing == 0) {
        readerCount++;
        printf("\nReader %d started reading...\n", readerCount);
    } else {
        printf("\nCannot read, writer is currently writing...\n");
    }
}

void stopReading() {
    if (readerCount > 0) {
        printf("\nReader %d stopped reading...\n", readerCount);
        readerCount--;
    } else {
        printf("\nNo readers are currently reading.\n");
    }
}

void startWriting() {
    if (writing == 0 && readerCount == 0) {
        writing = 1;
        printf("\nWriter started writing...\n");
    } else if (writing == 1) {
        printf("\nCannot write, another writer is already writing...\n");
    } else {
        printf("\nCannot write, readers are currently reading...\n");
    }
}

void stopWriting() {
    if (writing == 1) {
        writing = 0;
        printf("\nWriter stopped writing...\n");
    } else {
        printf("\nNo writer is currently writing.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n\n----- Readers-Writers Simulation -----\n");
        printf("1) Start Reading\n");
        printf("2) Stop Reading\n");
        printf("3) Start Writing\n");
        printf("4) Stop Writing\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                startReading();
                break;
            case 2:
                stopReading();
                break;
            case 3:
                startWriting();
                break;
            case 4:
                stopWriting();
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}
