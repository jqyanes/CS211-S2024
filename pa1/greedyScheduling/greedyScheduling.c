#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Selection sort based approach to sorting jobs

int main(int argc, char* argv[]) {

    // First peek at how many jobs and timeslots there are
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        exit(EXIT_FAILURE);
    }

    char buf[256];

    // Read the number of jobs to be scheduled
    if (!fscanf(fp, "%s\n", buf)) {
        perror("reading the number of jobs failed");
        exit(EXIT_FAILURE);
    }
    int jobcount = atoi(buf);

    // Next read the maximum number of timeslots
    if (!fscanf(fp, "%s\n", buf)) {
        perror("reading the number of timeslots failed");
        exit(EXIT_FAILURE);
    }
    int slotmax = atoi(buf);

    // Now read the rest of the file
    char joblist[jobcount];
    unsigned int jobS[jobcount];
    unsigned int jobE[jobcount];
    for ( int line=0; line<jobcount; line++ ) {
	if (!fgets(buf, 256, fp)) {
		perror("reading a line for a job failed");
                exit(EXIT_FAILURE);
        }
	char job;
	unsigned int start;
	unsigned int end;
	if (!sscanf(buf, "%c %d %d", &job, &start, &end)) {
                perror("parsing a line for a job failed");
                exit(EXIT_FAILURE);
	}
	joblist[line] = job;
	jobS[line] = start;
	jobE[line] = end;
     }
     
    fclose(fp);
    
    char temp;
    unsigned int tempS;
    unsigned int tempE;
    int check = 0;
    // Now sort the jobs
    for (int swap = 0; swap < (jobcount - 1); swap++) {
    	for (check = (swap + 1); check < jobcount; check++) {
    		// if a job ends earlier than the one in position, swap
    		if (jobE[check] < jobE[swap]) {
    			temp = joblist[swap];
    			tempS = jobS[swap];
    			tempE = jobE[swap];
    			joblist[swap] = joblist[check];
    			jobS[swap] = jobS[check];
    			jobE[swap] = jobE[check];
    			joblist[check] = temp;
    			jobS[check] = tempS;
    			jobE[check] = tempE;
    		}
    		// if they end at the same time, swap if the job starts sooner or same time
    		else if (jobE[check] == jobE[swap]) {
    			if (jobS[check] <= jobS[swap]) {
    				temp = joblist[swap];
    				tempS = jobS[swap];
    				tempE = jobE[swap];
    				joblist[swap] = joblist[check];
    				jobS[swap] = jobS[check];
    				jobE[swap] = jobE[check];
    				joblist[check] = temp;
    				jobS[check] = tempS;
    				jobE[check] = tempE;
    			}
    		}
    	}
    }
    
    // Finally assign and print the jobs
    check = 0;
    int slot = 0;
    char slotlist[jobcount];
    unsigned int slotE[jobcount];
    while (check < jobcount) {
    	if (jobS[check] == 0) check++;
    	else {
    		if (slot != 0) {
    			if (jobS[check] <= slotE[slot - 1]) check++;
    			else {
    				slotlist[slot] = joblist[check];
    				slotE[slot] = jobE[check];
    				if (slot < slotmax) {
    			    		printf("%s", "\n");
    					printf("%c", slotlist[slot]);
    				}
    				slot++;
    				check++;
    			}
    		}
    		else {
    			slotlist[slot] = joblist[check];
    			slotE[slot] = jobE[check];
    			if (slot < slotmax) printf("%c", slotlist[slot]);
    			slot++;
    			check++;
    		}	
    	}
    }

    exit(EXIT_SUCCESS);
}
