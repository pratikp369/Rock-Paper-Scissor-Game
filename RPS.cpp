#include "cstdlib"
#include "stdio.h"
#include "iostream"
#include "unistd.h"
#include "sys/types.h"
#include "signal.h"
#include "string"
#include "cstring"
#include "ctime"
using namespace std;
//declaration
#define BUFF 80
int fd1[2];
int fd2[2];

string ele[3] = {"paper","sesor","stone"};

void user1(int sig)
{
	char us1[BUFF];

	srand(time(NULL)*100);
	
	int a =rand()%3;
	string s = ele[a];
  
     strcpy(us1, s.c_str());

	write(fd1[1],us1,BUFF);
	cout<<"HELLO USER 1:"<<endl;
	exit(0);
}
void user2(int sig)
{
	char us2[BUFF];

	srand(time(NULL));

	int b =rand()%3;
	string s = ele[b];

    strcpy(us2, s.c_str());

	write(fd2[1],us2,BUFF);
	cout<<"HELLO USER 2:"<<endl;
	exit(0);
}
void check(char us1[],char us2[])
{
	cout<<"US1"<<us1<<endl;
	cout<<"US2"<<us2<<endl;	
	if(!strcmp(us1,us2))
	{
		cout<<"\nTie\n";
	}
	else if(!strcmp(us1,"paper"))
	{
		if(!strcmp(us2,"sesor"))
			{cout<<"\nUser 2 Win\n";}
		else 
			{cout<<"\nUser 1 win\n";}
	}
	else if(!strcmp(us1,"sesor"))
	{
		if(!strcmp(us2,"paper"))
			{cout<<"\nUser 1 Win\n";}
		else
			{cout<<"\nUser 2 win\n";}
	}
	else if(!strcmp(us1,"stone"))
	{
		if(!strcmp(us2,"paper"))
			{cout<<"\nUser 2 Win\n";}
		else
			{cout<<"\nUser 1 win\n";}
	}
}
int main()
{
	int pid1,pid2;
	pipe(fd1);
	pipe(fd2);

	pid1 = fork();
     if(pid1>0)
     {
     	pid2 = fork();
     	if(pid2>0)
     	{
     		sleep(2);
     		cout<<"Main Parent\n";
     		kill(pid2,SIGUSR2);
     		kill(pid1,SIGUSR1);
     		sleep(2);
     		
			char us1[BUFF];
     		read(fd1[0],us1,BUFF);
     		cout<<"\n\n USER ! Is:"<<us1<<endl;

     		char us2[BUFF];
     		read(fd2[0],us2,BUFF);
     		cout<<"\n\n USER @ Is:"<<us2<<endl;   

     		check(us1,us2);
     	}
     	else
     	{     		
     		cout<<"Chiled 2"<<endl;
     		signal(SIGUSR2,user2);
     		sleep(6);
     		exit(0);
     	}
     }
     else
     {
     	cout<<"Child 1"<<endl;
     	signal(SIGUSR1,user1);
     	sleep(5);
     	exit(0);
     }
	return 0;
}
