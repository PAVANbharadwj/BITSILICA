#include<linux/kernel.h>
#include<linux/module.h>
#include<asm/atomic.h>


atomic_t val = ATOMIC_INIT(0);

MODULE_LICENSE("GPL");

static int test_init(void){

	pr_info("%s : value after initiliazation:%d",__func__,atomic_read(&val));
	atomic_set(&val,4);
	pr_info("%s : value after initiliazation to 4:%d",__func__,atomic_read(&val));
	pr_info("%s : atomic_sub_and_test ():%d",__func__,atomic_sub_and_test(4,&val));
	pr_info("%s : atomic_add_negative ():%d",__func__,atomic_add_negative(-1,&val));
	pr_info("%s : atomic_inc_and_test ():%d",__func__,atomic_inc_and_test(&val));
	pr_info("%s : atomic_inc_and_test ():%d",__func__,atomic_inc_and_test(&val));
	pr_info("%s : atomic_dec_and_test ():%d",__func__,atomic_dec_and_test(&val));
	pr_info("%s : atomic_dec_and_test ():%d",__func__,atomic_dec_and_test(&val));

	return -1;

}

static void test_exit(void){
	pr_info("%s : In exit\n",__func__);
}

module_init(test_init);
module_exit(test_exit);






