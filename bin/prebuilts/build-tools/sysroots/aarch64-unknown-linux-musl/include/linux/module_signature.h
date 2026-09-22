/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _UAPI_LINUX_MODULE_SIGNATURE_H
#define _UAPI_LINUX_MODULE_SIGNATURE_H
#include <linux/types.h>
#define MODULE_SIGNATURE_MARKER "~Module signature appended~\n"
enum module_signature_type {
  MODULE_SIGNATURE_TYPE_PKCS7 = 2,
};
struct module_signature {
  __u8 algo;
  __u8 hash;
  __u8 id_type;
  __u8 signer_len;
  __u8 key_id_len;
  __u8 __pad[3];
  __be32 sig_len;
};
#endif
