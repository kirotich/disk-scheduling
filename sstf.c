/*
  SSTF Disk Scheduling Algorithm
*/

#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int queue[100], t[100], head, seek=0, i, j, n,temp;
  float avg;

  printf("%s\n", "Enter the size of the queue");
  scanf("%d", &n);

  for(i=0; i<n; i++){
      scanf("%d",&queue[i]);
  }

  printf("%s\n","Enter initial head position");
  scanf("%d", &head);

  for(i=1; i<n; i++){
    t[i] = abs(head-queue[i]);
  }
  for(i=0; i<n; i++){

    for(j=i+1; j<n;j++){

        if(t[i]>t[j]){
          temp = t[i];
          t[i]=t[j];
          t[j]=temp;
          temp=queue[i];
          queue[i]=queue[j];
          queue[j]=temp;

        }
    }

  }

  for(i=1; i<n-1; i++){
    seek = seek+abs(head-queue[i]);
    head = queue[i];
  }

  printf("\nTotal Seek Time os %d\t", seek);
  avg = seek/(float)n;
  printf("\nAverage Seek Time is %f\t", avg);
  //getch();
  return 0;
}
