#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(Door door[DOORS_COUNT]);
void sort(Door door[DOORS_COUNT]);

int main() {
    Door door[DOORS_COUNT];

    initialize_doors(door);
    sort(door);
    for (int i = 0; i < DOORS_COUNT; ++i) {
        printf("%d, %d", door[i].id, door[i].status);
        if (i != DOORS_COUNT - 1) printf("\n");
    }

    return 0;
}

void sort(Door door[DOORS_COUNT]) {
    for (int i = 0; i < DOORS_COUNT - 1; i++) {
        if (door[i].status == 1) {
            door[i].status = 0;
        }
        for (int j = 0; j < DOORS_COUNT - 1 - i; j++) {
            if (door[j].id > door[j + 1].id) {
                Door twink = door[j];
                door[j] = door[j + 1];
                door[j + 1] = twink;
            }
        }
    }
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(Door door[DOORS_COUNT]) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        door[i].id = (i + seed) % DOORS_COUNT;
        door[i].status = rand() % 2;
    }
}
