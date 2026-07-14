#include <stdio.h>

int main() {
    int frames, pages, i, j;
    int page[20], memory[10];

    int hits = 0, faults = 0;
    int pointer = 0;
    int found;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter page reference string:\n");
    for(i = 0; i < pages; i++) {
        scanf("%d", &page[i]);
    }

    for(i = 0; i < frames; i++)
        memory[i] = -1;

    printf("\nFIFO Page Replacement\n");

    for(i = 0; i < pages; i++) {

        found = 0;

        for(j = 0; j < frames; j++) {
            if(memory[j] == page[i]) {
                found = 1;
                hits++;
                break;
            }
        }

        if(found == 0) {
            memory[pointer] = page[i];
            pointer = (pointer + 1) % frames;
            faults++;
        }

        printf("Page %d -> ", page[i]);

        for(j = 0; j < frames; j++) {
            if(memory[j] == -1)
                printf("- ");
            else
                printf("%d ", memory[j]);
        }

        if(found)
            printf("Hit\n");
        else
            printf("Fault\n");
    }

    printf("\nTotal Hits   : %d\n", hits);
    printf("Total Faults : %d\n", faults);

    return 0;
}
