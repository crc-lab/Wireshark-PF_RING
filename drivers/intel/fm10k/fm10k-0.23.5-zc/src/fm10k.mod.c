#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
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

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=uio,pf_ring";

MODULE_ALIAS("pci:v00008086d000015A4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015D0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015D5sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015A5sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "5AA76D6935B5A5B72ABC373");
