#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *sum(void *arg);
int array[2];

int main()
{
 printf("Enter The First Number: ");
 scanf("%d",&array[0]);
 printf("\n Enter The Second Number: ");
 scanf("%d",&array[1]);
 
 pthread_t t;
 pthread_create(&t,NULL,sum,array);
 pthread_join(t,NULL);
}

void *sum(void *arg)
{
 int *value;
 value=arg;
 int p,q,sum;
 p = value[0];
 q = value[1];
 sum = p+q;
 printf("Required Sum: %d",sum);
}
 
