/*execlp.c*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    if(fork()==0)
    {
        /*调用execlp()函数，这里相当于调用了ps -ef命令*/
        if((ret == execlp("ps","ps","-ef",NULL))<0)
        {
            printf("Execlp Error \n");
        }
    }
}
