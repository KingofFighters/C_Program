#include <stdio.h>
#include <stdlib.h>

// Structure to represent an activity
struct Activity {
    int start;
    int finish;
};

// Function to compare two activities based on their finish time
int compare(const void *a, const void *b) {
    struct Activity *activityA = (struct Activity *)a;
    struct Activity *activityB = (struct Activity *)b;
    return activityA->finish - activityB->finish;
}

// Function to select the maximum number of activities that can be done
void activitySelection(struct Activity activities[], int n) {
    // Sort activities based on their finish time
    qsort(activities, n, sizeof(struct Activity), compare);

    // The first activity is always selected
    printf("Selected activities:\n");
    printf("Start: %d, Finish: %d\n", activities[0].start, activities[0].finish);

    // The last finish time of the selected activity
    int lastSelected = 0;

    // Loop through the remaining activities and select the ones that do not overlap
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= activities[lastSelected].finish) {
            printf("Start: %d, Finish: %d\n", activities[i].start, activities[i].finish);
            lastSelected = i; // Update last selected activity
        }
    }
}

int main() {
    int n;

    // Read number of activities
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    // Create an array to store activities
    struct Activity activities[n];

    // Read start and finish time of each activity
    printf("Enter start and finish time for each activity:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: Start time: ", i + 1);
        scanf("%d", &activities[i].start);
        printf("Activity %d: Finish time: ", i + 1);
        scanf("%d", &activities[i].finish);
    }

    // Call the activity selection function
    activitySelection(activities, n);

    return 0;
}
