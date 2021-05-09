#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
#include <linux/sched.h>
 
 
struct task_struct *task;        /*    Structure defined in sched.h for tasks/processes    */
struct task_struct *task_child;        /*    Structure needed to iterate through task children    */
struct list_head *list;            /*    Structure needed to iterate through the list in each task->children struct    */
 
module_param(PID, long, S_IRUSR);
MODULE_PARM_DESC(PID, "PID of process");

int init_module(void)                    /*    Init Module    */
{
    printk(KERN_INFO "Input argument pid %ld\n", PID);
       
    return 0;
 
}                /*    End of Init Module    */
     
void cleanup_exit(void)        /*    Exit Module    */
{
    printk(KERN_INFO "%s","REMOVING MODULE\n");
 
}                /*    End of Exit Module    */
 
module_init(init_module);    /*    Load Module MACRO    */
module_exit(cleanup_module);    /*    Remove Module MACRO    */
 
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("ITERATE THROUGH ALL PROCESSES/CHILD PROCESSES IN THE OS");
MODULE_AUTHOR("Laerehte");
