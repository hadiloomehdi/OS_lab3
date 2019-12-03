#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
	int pid,ticket,res;
	if(argc != 3)
		printf(1, "inappropriate arguments\n");
	else
	{
        ticket = atoi(argv[2]);
        pid = atoi(argv[1]);
		res = changeTicket(pid,ticket);
		printf(1, "ticket of procrss %d is %d   %d \n", pid, ticket,res);
	}
	exit();
    
}