#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    for (int i = 0; i < 2; i++)
    {
        int pid = fork();
        if(pid == 0)
        {
                printf(1,"i am number %d\n",i);
            while (1)
            {
            }
            
        }
    }
    
    
}