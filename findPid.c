#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
#include <linux/sched.h>
 



int iterate_init(void)                    /*    Init Module    */
{
    int pid = 820;
    struct task_struct* task = pid_task( find_vpid(pid), PIDTYPE_PID);     
    printk("[%d] ---------[%s]--------[%d]----------[%s]\n", task->pid, task->comm,
    task->parent->pid, task->parent->comm);
    return 0;
 
}                /*    End of Init Module    */
     
void cleanup_exit(void)        /*    Exit Module    */
{
    printk(KERN_INFO "%s","REMOVING MODULE\n");
 
}                /*    End of Exit Module    */
 
module_init(iterate_init);    /*    Load Module MACRO    */
module_exit(cleanup_exit);    /*    Remove Module MACRO    */
 
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("ITERATE THROUGH ALL PROCESSES/CHILD PROCESSES IN THE OS");
MODULE_AUTHOR("Laerehte");
