#include <procsched.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
     pid_t mypid = getpid();
     printf("PID: %d\n", mypid);
     struct proc_segs info;

     if (procsched(mypid, &info) == 0) {
        printf("Student ID: %lu \n", info.mssv);
        printf("pcount: %lu \n", info.pcount);
        printf("run_delay: %llu \n", info.run_delay);
        printf("last_arrival: %llu\n", info.last_arrival);
        printf("last_queued: %llu\n", info.last_queued);
     }else{
        printf("Cannot get information from the process %d\n", mypid);
     }
// If necessary, uncomment the following line to make this program run
// long enough so that we could check out its maps file
// sleep(100);
}

