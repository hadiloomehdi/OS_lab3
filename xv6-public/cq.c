#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    if(fork()>0)
    {

	int pid,Q;
	if(argc != 3)
		printf(1, "inappropriate arguments\n");
	else
	{
        Q = atoi(argv[2]);
        pid = atoi(argv[1]);
        changeQ(pid,Q);
		printf(1, "Q of procrss %d is %d    \n", pid, Q);
	}
	exit();
    }
    else
    {
        while(1)
        ;
    }
    
}