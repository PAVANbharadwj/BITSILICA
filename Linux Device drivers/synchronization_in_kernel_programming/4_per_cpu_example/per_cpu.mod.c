#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

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
	{ 0x46b0be46, "single_open" },
	{ 0xc60d0620, "__num_online_cpus" },
	{ 0xc00e2b80, "seq_printf" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x63cd0125, "remove_proc_entry" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x44be8471, "pcpu_hot" },
	{ 0x48d88a2c, "__SCT__preempt_schedule" },
	{ 0x7682ba4e, "__copy_overflow" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0xc1d9b323, "seq_read" },
	{ 0x7369f212, "seq_lseek" },
	{ 0x8e66928c, "single_release" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x122c3a7e, "_printk" },
	{ 0x2dbde678, "proc_create" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xe2fd41e5, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "718245D1CA0E2EB827AF7FC");
