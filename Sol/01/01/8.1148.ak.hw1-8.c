#include <stdint.h>
#include <stdio.h>

#define MAXWEIGHT 1000000

int worker(int weight);
int nextweight();


int main ()
{
  int w; 
  scanf("%d", &w);

  printf("%d\n", worker(w));
  return 0;
}



int worker(int weight)
{
  int q=0;
  int g;
  int side1=weight;
  int side2=0;
  while(weight /* && side1<=MAXWEIGHT && side2 <= MAXWEIGHT */ )
  {
    g = nextweight();
    
    switch (weight % 3 )
    {
      case 1:
        weight--;
        side2 += g;
//        printf("%d to side2 (%d)\n", g, side2);
        q++;
        break;
      case 2:
        weight++;
        side1 += g ;
//        printf("%d to side1 (%d)\n", g, side1);
        q++;
        break;
    }
    if(side1 > MAXWEIGHT || side2 > MAXWEIGHT )
    {
      break;
    }
    weight/=3;
  }
  
  return weight? -1: q;
}


int nextweight()
{
  static int current = 0;

  current = (!current)?1:current*3;

  return current;
}


