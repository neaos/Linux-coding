/*waitpid.c*/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pc,pr;

    pc = fork();
    if(pc<0)
        printf("Error fork \n");
    else if(pc == 0)
    {
        //子进程暂停5s
        sleep(5);
        exit(0);
    }else
    {
        do
        {
            //调用waitpid,且父进程不阻塞
            pr = waitpid(pc,NULL,WNOHANG);
            //若子进程还未退出，则子进程暂停1s
            if(pr==0)
            {
                printf("The child process has not exited\n");
                sleep(1);
            }
        }while(pr==0);
        
        //若发现子进程退出，打印出相应的情况
        if(pr == pc)
        {
            printf("Get Child exit code: %d\n",pr);
        }else
        {
            printf("Some Error Occured.\n");
        }
    }

}