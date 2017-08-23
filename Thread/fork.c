/*fork.c*/
#include <sys/types.h>
//#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	pid_t result;

	/*调用fork()函数*/
	result = fork();

	/*通过result的值来判断fork()函数的返回情况，首先进行出错处理*/
	if (result == -1)
	{
		printf("Fork Error \n");
	}
	else if (result == 0)
	{
		/*返回值为0代表子进程*/
		printf("The Returned Value is %d \n \
			In child Process !! \n My Pid is %d \n",result,getpid());
	}
	else
	{
		printf("The Returned Value is %d \n \
			In father Process !! \n My Pid is %d \n", result, getpid());
	}
	return result;
}