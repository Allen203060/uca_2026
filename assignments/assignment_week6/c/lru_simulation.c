#include <stdio.h>
#include <stdbool.h>

void simulate_lru(int page_requests[], int num_requests, int num_frames) {
    int frames[num_frames];
    int last_used[num_frames];
    int page_faults = 0;

    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
        last_used[i] = -1;
    }

    for (int time = 0; time < num_requests; time++) {
        int page = page_requests[time];
        bool hit = false;

        int frame_idx = -1;
        for (int i = 0; i < num_frames; i++) {
            if (frames[i] == page) {
                hit = true;
                frame_idx = i;
                break;
            }
        }
        if (hit) {
            last_used[frame_idx] = time;
        } else {
            page_faults++;

            int target = -1;
            for (int i = 0; i < num_frames; i++) {
                if (frames[i] == -1) {
                    target = i;
                    break;
                }
            }

            if (target == -1) {
                int oldest_time = last_used[0];
                target = 0;

                for (int i = 1; i < num_frames; i++) {
                    if (last_used[i] < oldest_time) {
                        oldest_time = last_used[i];
                        target = i;
                    }
                }
            }
 
            frames[target] = page;
            last_used[target] = time;
        }
        printf("Request %d -> %s -> RAM State: [", page, hit ? "HIT" : "FAULT");
        for (int i = 0; i < num_frames; i++) {
            if (frames[i] == -1) printf("-");
            else printf("%d", frames[i]);
            if (i < num_frames - 1) printf(", ");
        }
        printf("]\n");
    }
 
    printf("\nTotal Page Faults: %d\n", page_faults);
}

int main() {
    int requests[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int num_requests = sizeof(requests) / sizeof(requests[0]);
 
    simulate_lru(requests, num_requests, 3);
    return 0;
}
