#include <stdio.h>

#include "MyMath.h"

int main()

{

  int x = 5;

  int y = 4;

  printf("%d + %d = %d\n", x, y, Add(x, y));

  printf("%d * %d = %d\n", x, y, Multiply(x, y)); 

}
