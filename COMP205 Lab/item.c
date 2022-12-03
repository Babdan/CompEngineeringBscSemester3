// Dorantes-Nikolaev, Bogdan Itsam
// 11/11/2022, COMP205-02 Systems Programming, Lab5

// Including necessary libraries
#include <stdio.h>
// Constant declarations
#define LARGEDEF 20
#define MEDIUMDEF 10

// Function that records 2 pieces of information and prints whether it's a large or medium item being packed
void classify_items(int volume) {
    // If the volume is greater than 10, it's a large item
    if(volume >= LARGEDEF)
        printf("large item being packed\n");
    // All other values suggest that it's a medium item
    else if(volume >= MEDIUMDEF)
        printf("medium item being packed\n");
}

// Main function
int main() {
    // Variable declarations and initializations
    int volume = 0;
    float threshold = 0;
    int large = 0;
    int medium = 0;
    // Looping until the threshold is reached
    while(threshold < 1000) {
        // Getting the volume of the item
        printf("enter a limit for item volume\n");
        scanf("%d", &volume);
        // Classifying the item
        classify_items(volume);
        // Adding the volume to the threshold
        if(volume >= LARGEDEF)
            large++;
        else if(volume >= MEDIUMDEF)
            medium++;
        // Adding the volume to the threshold
        threshold += 0.25 + 0.2 * volume;
    }
    // Printing the number of large and medium items
    printf("number of large items: %d \n number of medium items: %d", large, medium);
    return 0;
}