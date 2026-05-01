/*Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    float time;
} Car;

int compare(const void *a, const void *b) {
    return ((Car *)b)->position - ((Car *)a)->position;
}

int main() {
    int target, n;
    scanf("%d %d", &target, &n);

    int position[n], speed[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &position[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    Car cars[n];

    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].time = (float)(target - position[i]) / speed[i];
    }

    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    float maxTime = 0;

    for (int i = 0; i < n; i++) {
        if (cars[i].time > maxTime) {
            fleets++;
            maxTime = cars[i].time;
        }
    }

    printf("%d\n", fleets);

    return 0;
}