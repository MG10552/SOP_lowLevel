#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

int main() 
{
  int i, j, wysokosc,los;
los= time(NULL);
    srand(los);

  printf("---=====[クリスマスツリーのレベルをチェックしてください。]=====---\n", wysokosc);
  scanf("%d", &wysokosc);
  if (wysokosc<1 || wysokosc>79) { 
  printf("-==[申し訳ありませんが、範囲外の値。]==-\n");
  return 0;
}

  for( i = 0; i < wysokosc; i++ ) 
  {
    printf( "%*c", wysokosc - i, ' ' );
    for ( j = 0; j <= i; j++ )
      printf( " /" ); 
      putchar( '\n' ); 
    printf( "%*c|\n", wysokosc + 1, ' ' );

  }

  
  printf( "%*c|\n", wysokosc + 1, ' ' );
  return 0; 
}
