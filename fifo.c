#include <stdio.h>

void fifo() {
    int page[] = {9,8,0,8,7,6,7,5,3,7};
    int frame[4] = {-1,-1,-1,-1};
    int i, j, found, index = 0, hit = 0, fault = 0;

    printf("\nFIFO Page Replacement\n");

    for(i = 0; i < 10; i++) {
        found = 0;

        for(j = 0; j < 4; j++)
            if(frame[j] == page[i]) {
                found = 1;
                hit++;
            }

        if(!found) {
            frame[index] = page[i];
            index = (index + 1) % 4;
            fault++;
        }

        printf("%d -> ", page[i]);
        for(j = 0; j < 4; j++)
            printf("%d ", frame[j]);

        printf(found ? "Hit\n" : "Fault\n");
    }

    printf("Hits = %d\nFaults = %d\n", hit, fault);
}

void lru() {
    int page[] = {9,8,0,8,7,6,7,5,3,7};
    int frame[4] = {-1,-1,-1,-1};
    int time[4] = {0};
    int i, j, found, pos, hit = 0, fault = 0;

    printf("\nLRU Page Replacement\n");

    for(i = 0; i < 10; i++) {
        found = 0;

        for(j = 0; j < 4; j++) {
            if(frame[j] == page[i]) {
                found = 1;
                hit++;
                time[j] = i;
            }
        }

        if(!found) {
            pos = 0;
            for(j = 1; j < 4; j++)
                if(time[j] < time[pos])
                    pos = j;

            frame[pos] = page[i];
            time[pos] = i;
            fault++;
        }

        printf("%d -> ", page[i]);
        for(j = 0; j < 4; j++)
            printf("%d ", frame[j]);

        printf(found ? "Hit\n" : "Fault\n");
    }

    printf("Hits = %d\nFaults = %d\n", hit, fault);
}

int main() {
    fifo();
    lru();
    return 0;
}
