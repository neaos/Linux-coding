/*fork.c*/
#include <sys/types.h>
//#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	pid_t result;

	/*����fork()����*/
	result = fork();

	/*ͨ��result��ֵ���ж�fork()�����ķ�����������Ƚ��г�����*/
	if (result == -1)
	{
		printf("Fork Error \n");
	}
	else if (result == 0)
	{
		/*����ֵΪ0�����ӽ���*/
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