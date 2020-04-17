#include<stdio.h>
#include<pthread.h>
#include<stdbool.h>

void *function1();
void *function2();

bool flag1=true;
bool flag2=true;

int main()
{
 pthread_t one,two;

 //for first thread
 while(flag1)
 {
   pthread_create(&one,NULL,function1,NULL);
   pthread_join(one,NULL);
   printf("Process P1 is Executed \n");
   flag1=false;
 }

 //for second thread
 while(flag2)
 {
   pthread_create(&two,NULL,function2,NULL);
   pthread_join(one,NULL);
   printf("Process P2 is Executed \n");
   flag2=false;
 }
}

void *function1()
{
 printf("Process P1 is Executing \n");
 sleep(1);
}

void *function2()
{
 printf("Process P2 is Executing \n");
 sleep(1);
}
