#include <stdio.h>

#define MAXP 10
#define MAXR 10

int main() {
    int n, m; // n = processes, m = resources
    int allocation[MAXP][MAXR], max[MAXP][MAXR];
    int need[MAXP][MAXR];
    int available[MAXR];
    int finish[MAXP] = {0};
    int safeSeq[MAXP];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    // Allocation matrix
    printf("\nEnter Allocation Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&allocation[i][j]);

    // Max matrix
    printf("\nEnter Max Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    // Available resources
    printf("\nEnter Available Resources:\n");
    for(int j=0;j<m;j++)
        scanf("%d",&available[j]);

    // Calculate Need matrix
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            need[i][j] = max[i][j] - allocation[i][j];

    int count = 0;

    while(count < n) {
        int found = 0;

        for(int i=0;i<n;i++) {
            if(finish[i]==0) {
                int j;
                for(j=0;j<m;j++) {
                    if(need[i][j] > available[j])
                        break;
                }

                if(j==m) {
                    for(int k=0;k<m;k++)
                        available[k] += allocation[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found==0) {
            printf("\nSystem is NOT in safe state!");
            return 0;
        }
    }

    printf("\nSystem is in SAFE state.");
    printf("\nSafe Sequence: ");
    for(int i=0;i<n;i++)
        printf("P%d ", safeSeq[i]);

    return 0;
}
