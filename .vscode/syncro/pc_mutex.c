#include <stdio.h>

int mutex = 0;      
int bufferSize;     
int items = 0;     

void lock() {
    while (mutex == 1) {
    }
    mutex = 1;
}

void unlock() {
    mutex = 0;
}

void producer() {
    lock();
    if (items == bufferSize) {
        printf("Buffer is full! Cannot produce.\n");
    } else {
        items++;
        printf("Produced item-%d\n", items);
    }
    unlock();
}

void consumer() {
    lock();
    if (items == 0) {
        printf("Buffer is empty! Cannot consume.\n");
    } else {
        printf("Consumed item-%d\n", items);
        items--;
    }
    unlock();
}

int main() {
    int choice;

    printf("Enter buffer size: ");
    scanf("%d", &bufferSize);

    do {
        printf("\n1) Produce an item\n2) Consume an item\n3) Check if full\n4) Check if empty\n5) Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                if (items == bufferSize)
                    printf("Buffer is full.\n");
                else
                    printf("Buffer is not full.\n");
                break;
            case 4:
                if (items == 0)
                    printf("Buffer is empty.\n");
                else
                    printf("Buffer is not empty.\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
