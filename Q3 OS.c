#include<stdio.h>
#include<pthread.h>

void *function1();
void *function2();
void *function3();

pthread_mutex_t first;
pthread_mutex_t second;
pthread_mutex_t third;

int main()
{
 pthread_mutex_init(&first,NULL);
 pthread_mutex_init(&second,NULL);
 pthread_mutex_init(&third,NULL);

 pthread_t one,two,three;

 pthread_create(&one,NULL,function1,NULL);
 pthread_create(&two,NULL,function2,NULL);
 pthread_create(&three,NULL,function3,NULL);
 
 pthread_join(one,NULL);
 pthread_join(two,NULL);
 pthread_join(three,NULL);

 printf("Thread Joined \n"); //proof of not having deadlock (if printed)
}

void *function1()
{
 pthread_mutex_lock(&first);
 printf("Thread ONE acquired the First Mutex \n");
 sleep(2);
 pthread_mutex_lock(&second);
 printf("Thread One acquired Second Mutex \n");
 pthread_mutex_unlock(&second); 
 printf("Thread ONE realease Second Mutex \n");
 pthread_mutex_unlock(&first);
 printf("Thread ONE realease First Mutex \n");
}

void *function2()
{
 pthread_mutex_lock(&second);
 printf("Thread Two acquired the second Mutex \n");
 sleep(2);
 pthread_mutex_lock(&third);
 printf("Thread Two acquired Third Mutex \n");
 pthread_mutex_unlock(&third); 
 printf("Thread Two realease Second Mutex \n");
 pthread_mutex_unlock(&second);
 printf("Thread Two realease First Mutex \n");
}

void *function3()
{
 pthread_mutex_lock(&third);
 printf("Thread Three acquired the Third Mutex \n");
 sleep(2);
 pthread_mutex_lock(&first);
 printf("Thread Three acquired First Mutex \n");
 pthread_mutex_unlock(&first); 
 printf("Thread Three realease First Mutex \n");
 pthread_mutex_unlock(&third);
 printf("Thread Three realease Third Mutex \n");
}

