#include <linux/linkage.h>
#include <linux/kernel.h>
#include <asm/uaccess.h>
#include <linux/mm.h>
#include <linux/slab.h>

int q;
int len;
char reversed[256];

asmlinkage long sys_printcall(char *str)
{

    if (str == NULL) {
        printk(KERN_ALERT "NULL Argument!\n");
        return -1;
    }

    printk(KERN_ALERT "Original String: %s\n", str);

    len = (int) strlen_user(str);

    if (len <= 0) {
        printk(KERN_ALERT "No input string!\n");
        return -1;
    }

    printk(KERN_ALERT "TEST: %s ", reversed);

    for(q = 0; q < len; q++) {
        reversed[q] = str[len - q - 1];
        printk(KERN_ALERT "Reversed String: %s\n", (char *) (reversed + q));
    }

    return 1;
}

