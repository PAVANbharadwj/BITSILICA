#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xf28efea0, "module_layout" },
	{ 0x53934f07, "platform_driver_unregister" },
	{ 0xb3e308df, "__platform_driver_register" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0x86332725, "__stack_chk_fail" },
	{ 0x97fb274c, "of_property_read_string" },
	{ 0x33dbd1e2, "of_property_read_variable_u32_array" },
	{ 0xc5850110, "printk" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cpcdev-A1x");
MODULE_ALIAS("of:N*T*Cpcdev-A1xC*");
MODULE_ALIAS("of:N*T*Cpcdev-B1x");
MODULE_ALIAS("of:N*T*Cpcdev-B1xC*");
MODULE_ALIAS("of:N*T*Cpcdev-C1x");
MODULE_ALIAS("of:N*T*Cpcdev-C1xC*");
MODULE_ALIAS("of:N*T*Cpcdev-D1x");
MODULE_ALIAS("of:N*T*Cpcdev-D1xC*");
