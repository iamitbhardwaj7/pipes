#include"stdio.h"
#include"stdlib.h"
#include"unistd.h"
#include"string.h"
#include"sys/wait.h"
void main()
{
int fd[2],fd2[2],n;
char buff[100];
pid_t p;
pipe(fd);
pipe(fd2);
p=fork();
if(p>0)
  {
  close(fd[0]);
  printf("Enter any string::--");
  gets(buff);
  write(fd[1],buff,strlen(buff));
  close(fd2[1]);
  n=read(fd2[0],buff,100);
  printf("%s",buff);
  }
else
  {
  close(fd[1]);
  n=read(fd[0],buff,100);
  for(int i=0;i<strlen(buff);i++)
    {
    if(buff[i]>='a' && buff[i]<='z')
      {
      buff[i]=buff[i]-32;
      }
    else if(buff[i]>='A' && buff[i]<='Z')
      {
      buff[i]=buff[i]+32;
      }
    }
  close(fd2[0]);
  write(fd2[1],buff,strlen(buff));
  }

}
