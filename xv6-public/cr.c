#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{

	int pid,R ;
	if(argc != 3)
		printf(1, "inappropriate arguments\n");
	else
	{
        R = atoi(argv[2]);
        pid = atoi(argv[1]);
        changeR(pid,R);
		printf(1, "R of procrss %d is %d    \n", pid, R);
	}
	exit();

    
}