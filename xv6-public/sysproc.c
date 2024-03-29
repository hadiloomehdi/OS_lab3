#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int sys_changeTicket(void)
{
  int pid,ticket;
  argptr(0, (void *)&pid, sizeof(pid));
  argptr(1, (void *)&ticket, sizeof(ticket));
  // cprintf("t = %d    pid = %d\n",ticket,pid);
  int res = changeTicket(ticket,pid);
  return res;
}

int sys_info(void)
{
  printInfo();
  return 0;
}

int sys_changeQ(void)
{
  int pid,Q;
  argptr(0, (void *)&pid, sizeof(pid));
  argptr(1, (void *)&Q, sizeof(Q));
  changeQ(pid,Q);
  return 0;
}

int sys_changeR(void)
{
  int pid;
  char* R;
  argptr(0, (void *)&pid, sizeof(pid));
  argstr(1, &R);
  changeR(pid,R);
  return 0;
}