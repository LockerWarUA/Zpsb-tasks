#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* reverse:  переворачиваем строку s на месте */
 void reverse(char s[])
 {
     int i, j;
     char c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }

void itoa(int n, char s[])
 {
     int i, sign;

     if ((sign = n) < 0)  /* записываем знак */
         n = -n;          /* делаем n положительным числом */
     i = 0;
     do {       /* генерируем цифры в обратном порядке */
         s[i++] = n % 10 + '0';   /* берем следующую цифру */
     } while ((n /= 10) > 0);     /* удаляем */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }

int main(int argc, char *argv[]){
    int rez=0;
    char input[15];
    char output[15];
    FILE * iFile, *oFile;
    int count = 0;
    char ch;
//  opterr=0;
  while ( (rez = getopt(argc,argv,"i:o:o:i:")) != -1){
    switch (rez){
	    case 'i': /*printf("found argument \"i = %s\".\n",optarg);*/ strcpy(input, optarg); break;
    	    case 'o': /*printf("found argument \"o = %s\".\n",optarg);*/ strcpy(output, optarg); break;
    	    case '?': printf("Error found !\n");break;
        	};
  };
  iFile = fopen(input, "r");
  if ( !iFile ) perror("Error opening file");
  else 
  {
	  while(1){
		  ch = fgetc(iFile);
	  	  if (feof(iFile)) break;
	  	  if (ch == 'x') count++;
	  }
  }
  printf("%d\n",count);
  oFile = fopen(output, "w+");
  char string[10];
  itoa(count, string);
  fputs(string, oFile);
  //printf("%s\n",input);
  //printf("%s",output);
  return 0;
  fclose(iFile);
  fclose(oFile);
};
