#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
int kill(pid_t pid, int sig);
int s = 0;
int fo; 
int newFork(int * pidm, int t){
    fo = fork();
    pid_t childPid = fo;
        if (fo < 0){
            printf("Fork Error"); //error
            return -1;
        } else if (fo == 0) { //child
            while(1);
        } else 
            {
                //printf("PID of child process: %d\n",fo);
                pidm[t] = fo;         
            } //parent
        return 0;
}

int main (int argc, char * argv[]) {
    int count = 0;
    s = atoi(argv[1]);
    if (argc != 2){   /* check for valid number of command-line arguments */ 
        printf("To use this program you need write number of process");
        return 1;
    }
    int pids[s];
    for (int z = 0; z<s; z++){
        pids[s] = newFork(pids, z);
    }
    printf("\n");
    int timeToStop = 0;
    while(timeToStop != -1){
        if(count == s-1){
                timeToStop = -1;
                return 0;
        } else {
            count = 0;
            for (int z = 0; z < s; z++){
                if (pids[z] != -1)
                {
                    printf("PID of child process: %d\n",pids[z]);
                }else if (pids[z] == -1)
                {
                    count++;
                }
            }
            printf("Write pid to kill process\n");
            int pidToKill;
            scanf("%d", &pidToKill);
            for (int i = 0; i < s; i++)
            {
                if(pidToKill == pids[i]) {
                    kill(pidToKill, 9);
                    pids[i] = -1;
                }
            }
        }
    }
    return 0;
}