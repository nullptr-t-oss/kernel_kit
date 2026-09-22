/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _UAPI_FWCTL_BNXT_H_
#define _UAPI_FWCTL_BNXT_H_
#include <linux/types.h>
enum fwctl_bnxt_commands {
  FWCTL_BNXT_INLINE_COMMANDS = 0,
  FWCTL_BNXT_QUERY_COMMANDS,
  FWCTL_BNXT_SEND_COMMANDS,
};
struct fwctl_info_bnxt {
  __u32 uctx_caps;
};
#endif
