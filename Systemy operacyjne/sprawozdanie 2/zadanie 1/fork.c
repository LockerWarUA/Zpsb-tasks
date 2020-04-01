#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
int kill(pid_t pid, int sig);
#define N 2048
int line = 1;
int savedLine = 0;
int count = 0;
int lines = 0;
char ch1 = ' ';
int spaceCheck(FILE * file,int needLine, int pid){
    if (needLine < lines){
    char arr[N];
    int count = 0;
    file = fopen("lorem","r");
    
    for (int i = 1; i<=needLine; i++){
        fgets (arr,N,file);
        }
        for (int i = 1; i<N; i++){
            if(arr[i] == ' '){
            count++;
            } else if (arr[i] == '\0'){
            break;
            }
        }
        printf("\nPID: %d line %d have %d spaces\n",pid,needLine,count);
    }
    return 0;
}
int lineCheck(FILE * f){
    int linesCount = 0;
    while (!feof(f))
    {
        if (fgetc(f) == '\n')
            linesCount++;
    }
    linesCount++;
    return linesCount;
}
int newFork(FILE *f){
    while(1){
    pid_t pid;
    int fo = fork();
    pid = getpid();
    pid_t childPid;
        if (fo < 0){
            printf("Fork Error"); //error
            return -1;
        } else if (fo == 0) { //child
            childPid = getpid();
            spaceCheck(f,line,pid);
            return 0;
        } else { //parent
            if (line < lines){
                line++;
                kill(childPid,SIGKILL);
            } else {
                break;
            }
        }
    }    
    return 0;
}
int main () {
    FILE * f;
    int line = 0;
    f = fopen("lorem","r");
    if (f == NULL) perror("Error opening file");
    lines = lineCheck(f);
    newFork(f);
}