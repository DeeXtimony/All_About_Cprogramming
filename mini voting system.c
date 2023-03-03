#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 5

int main() {
    int num_candidates;
    int votes[MAX_CANDIDATES];
    int i, j, choice, max_votes = 0, winner = -1;

    printf("Enter the number of candidates (maximum %d): ", MAX_CANDIDATES);
    scanf("%d", &num_candidates);

    if (num_candidates <= 0 || num_candidates > MAX_CANDIDATES) {
        printf("Invalid number of candidates. Please try again.\n");
        return 1;
    }

    // Initialize all candidate votes to zero
    for (i = 0; i < num_candidates; i++) {
        votes[i] = 0;
    }

    printf("Enter the vote for each candidate (1-%d) or 0 to stop:\n", num_candidates);
    while (1) {
        printf("Vote: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > num_candidates) {
            printf("Invalid candidate. Please try again.\n");
            continue;
        }

        votes[choice-1]++;
    }

    // Find the candidate with the most votes
    for (j = 0; j < num_candidates; j++) {
        if (votes[j] > max_votes) {
            max_votes = votes[j];
            winner = j;
        }
    }

    printf("\nResults:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("Candidate %d: %d votes\n", i+1, votes[i]);
    }

    if (winner != -1) {
        printf("\nWinner: Candidate %d with %d votes\n", winner+1, max_votes);
    } else {
        printf("\nNo winner\n");
    }

    return 0;
}
