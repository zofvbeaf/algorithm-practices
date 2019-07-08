// http://hihocoder.com/contest/hiho135/problem/1
#include <cstdio>
#include <iostream>
#include <stdlib.h>

using namespace std;

int pos[2];
int a[8][2]; // r3, c3, d2
int n[3][3];

void findpos(int x)
{
  if(x < 3)
  {
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
  }
}

int main()
{
  int a[8][2]; // r3, c3, d2
  int n[3][3];
  int flag = 0;
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
    {
      scanf("%d", &n[i][j]);
      if(n[i][j])
      {
        a[i][0]++, a[i][1] += n[i][j];
        a[j+3][0]++, a[j+3][1] += n[i][j];
        if(i==j) a[6][0]++, a[6][1] += n[i][j];
        if(i+j == 4) a[7][0]++, a[7][1] += n[i][j];
      } 
    }
  for(int i = 0; i < 8; i++)
  {
    if(a[i][0]==2)
    {
      if(i < 3)
      {
        a[i][j] = 
      }
    }
  }


  return 0;
}
