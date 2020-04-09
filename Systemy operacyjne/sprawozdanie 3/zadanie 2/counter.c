#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
unsigned int sleep(unsigned int seconds);
int x,y;
void sigfunc(int sig) {
  char c;
  if(sig != SIGINT)
    return;
  else {
    printf("\n Do you want exit from programm? (y/n)");
    c=getchar();
    if (c == 'y') {
        exit(0);
    } else if (c == 'n') {
        return;
    }
  }
} 

int main(int argc, char * argv[]){
    signal(SIGINT, sigfunc);
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    if (x > y)
    {
        while (1)
        {
            for (int i = y; i < x; i++) {
                printf("%d\n",i);
            }
            sleep(2);
        }
    } else if(x<y) {
        while (1)
        {
            for (int i = x; i < y; i++) {
                printf("%d\n",i);
            }
            sleep(2);
        }
    } else {
        return 0;
    }
}