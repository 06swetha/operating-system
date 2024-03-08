#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate total head movement
int calculateHeadMovement(int queue[], int head, int size) {
    int totalMovement = 0;
    int i; // Declare i here
    
    // Traverse the queue and calculate head movement
    for (i = 0; i < size; i++) {
        totalMovement += abs(queue[i] - head);
        head = queue[i];
    }
    
    return totalMovement;
}

int main() {
    int n; // Number of disk requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    
    // Dynamic memory allocation for requestQueue
    int *requestQueue = (int*)malloc(n * sizeof(int));
    if (requestQueue == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter the disk request queue:\n");
    int i; // Declare i here
    for (i = 0; i < n; i++) { // Use the previously declared i
        scanf("%d", &requestQueue[i]);
    }
    
    int initialHead; // Initial position of the head
    printf("Enter the initial position of the head: ");
    scanf("%d", &initialHead);
    
    int totalHeadMovement = calculateHeadMovement(requestQueue, initialHead, n);
    
    printf("Total head movement: %d\n", totalHeadMovement);

    free(requestQueue);
    
    return 0;
}

