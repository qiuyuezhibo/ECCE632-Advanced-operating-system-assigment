#include <linux/linkage.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/uaccess.h>

struct proc_segs {
	unsigned long mssv;
	unsigned long pcount;
    unsigned long long run_delay;
    unsigned long long last_arrival;
    unsigned long long last_queued;
};

asmlinkage long sys_procsched(int pid, struct proc_segs * info){
	struct task_struct * task;
	printk("Finding...\n");
	for_each_process(task) {
		printk("[%d] ------- [%s]\n", task->pid, task->comm);
		if(task->pid == pid) {
			if(task->mm != NULL) {
				struct proc_segs buff;
				printk("inside process!\n");
				buff.mssv = 1601234;
				buff.pcount = task->sched_info.pcount;
				buff.run_delay = task->sched_info.run_delay;
				buff.last_arrival = task->sched_info.last_arrival;
				buff.last_queued = task->sched_info.last_queued;
				int res = copy_to_user(info, &buff, sizeof(buff));
				if(res == 0) printk("copy data successful!\n");
				else printk("copy data failed\n");
				printk("Find out pid [%d]", pid);
				return 0;
			}
		}
	}
	return -1;
}
