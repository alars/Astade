module_init(trcDriver_init_module);
module_exit(trcDriver_exit_module);
MODULE_LICENSE("GPL");EXPORT_SYMBOL(trcDriver_notify_function_call);
EXPORT_SYMBOL(trcDriver_notifyReturn);
EXPORT_SYMBOL(trcDriver_notify_constructor);
EXPORT_SYMBOL(trcDriver_notify_destructor);

