#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
#include <linux/sched.h>
 
 
struct task_struct *task;        /*    Structure defined in sched.h for tasks/processes    */
struct task_struct *task_child;        /*    Structure needed to iterate through task children    */
struct list_head *list;            /*    Structure needed to iterate through the list in each task->children struct    */
 
int iterate_init(void)                    /*    Init Module    */
{
    printk(KERN_INFO "%s","LOADING MODULE\n");    /*    good practice to log when loading/removing modules    */
     
    for_each_process( task ){            /*    for_each_process() MACRO for iterating through each task in the os located in linux\sched\signal.h    */
        printk(KERN_INFO "\nCURRENT PID: %d PROCESS: %s",task->pid, task->comm);/*    log parent id/executable name/state    */
        
        struct task_struct* oldestTask = list_entry(&task->child, struct task_struct, sibling);
        printk(KERN_INFO "\nCHILD PID: %s[%d] PID",oldestTask->comm, oldestTask->pid); /*    log child of and child pid/name/state    */
        printk("-----------------------------------------------------");    /*for aesthetics*/
    }    
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
