/* auto-generated by gen_syscalls.py, don't edit */
#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic push
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif
#include <syscalls/can.h>

extern int z_vrfy_can_send(const struct device * dev, const struct zcan_frame * frame, k_timeout_t timeout, can_tx_callback_t callback, void * user_data);
uintptr_t z_mrsh_can_send(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2,
		uintptr_t arg3, uintptr_t arg4, uintptr_t arg5, void *ssf)
{
	_current->syscall_frame = ssf;
	union { struct { uintptr_t lo, hi; } split; k_timeout_t val; } parm0;
	parm0.split.lo = arg2;
	parm0.split.hi = arg3;
	int ret = z_vrfy_can_send(*(const struct device **)&arg0, *(const struct zcan_frame **)&arg1, parm0.val, *(can_tx_callback_t*)&arg4, *(void **)&arg5)
;
	_current->syscall_frame = NULL;
	return (uintptr_t) ret;
}

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic pop
#endif
