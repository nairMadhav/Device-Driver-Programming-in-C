#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#define mem_size 1024
dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;
uint8_t *kernel_buffer;
static int __init etx_driver_init(void);
static void __exit etx_driver_exit(void);
static int etx_open(struct inode *inode, struct file *file);
static int etx_release(struct inode *inode, struct file *file);
static ssize_t etx_read(struct file *filp, char __user *buf, size_t len, loff_t *off);
static ssize_t etx_write(struct file *filp, const char *buf, size_t len, loff_t *off);
static struct file_operations fops =
    {
        .owner = THIS_MODULE,
        .read = etx_read,
        .write = etx_write,
        .open = etx_open,
        .release = etx_release,
};
static int etx_open(struct inode *inode, struct file *file)
{
    if ((kernel_buffer = kmalloc(mem_size, GFP_KERNEL)) == 0)
    {
        printk(KERN_INFO "Cannot allocate memory in kernel\n");
        return -1;
    }
    printk(KERN_INFO "Device File Opened!!\n");
    return 0;
}