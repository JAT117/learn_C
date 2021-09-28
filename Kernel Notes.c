Linux Kernel

vmlinuz <KERNEL VERSION>
loaded by a boot loader like GRUB
Has command-line parameters
The Kernel is an API
	uses system calls
	Virtual file system entries
		proc
		sys
		debugfs
	Device Files(system calls)
Enforces privilages (capabilities)
Enforces supervisor instructions
Kernel provedes control access to hardware
Modular
located in /boot (do not delete)

	Application 
		|
	STD C Lib
		|
	Kernel
		|
	Hardware
	
lshw
lspci
lsusb 
lsbk
lscpu
lsdev
hdparm
inb & outb

System Calls (varies by architecture, ~340)
	Functions called from user space but implemented in the kernel space
	found in include/uapi/asp-generic/unistd.h
	Documented in man(2)
	Called throught the standard lib
	
//lkm_module.ko	
#include <linux/init.h>
#inlcude <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_VERSION("0.01");

static int __init lkm_example_init(void){
	printk(KERN_INFO "HELLO,WORLD!\n");
	return 0;
}

static void __exit lkm_example_exit(void){
	printk(KERN_INFO "Goodbye Cruel!\n");
	return 0;
}

module_init(lkm_example_init);
module_exit(lkm_example_exit);

//makefile example
obj-m += lkm_example.o
all:
 make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
 make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	
//now add and remove .ko	
$sudo inmod lkm_module.ko
$sudo dsmeg
$lsmod | grep "lkm_example"
$sudl rmod lkm_example

Grub2 BootLoaderSpec (BLS) /etc/default/grub make "true" to revert memory entries
Take a look at /boot file structures on all common distros
symvers 
System.Map