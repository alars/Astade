#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/timer.h>
#include <linux/sched.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("This driver exports some functions to generate Trace2UML traces. It has a procfile interface to read the traces."); 
