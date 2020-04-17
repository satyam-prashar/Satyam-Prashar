#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
 int fid,n;
 char buff[5],c[20];
 printf("Enter name of file: ");
 scanf("%s",c);
 fid = open(c,O_RDONLY);
 lseek(fid,-6,SEEK_END);
 n=read(fid,buff,6);
 write(1,buff,6);
}
