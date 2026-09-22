/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef LINUX_IO_URING_BPF_FILTER_H
#define LINUX_IO_URING_BPF_FILTER_H
#include <linux/types.h>
struct io_uring_bpf_ctx {
  __u64 user_data;
  __u8 opcode;
  __u8 sqe_flags;
  __u8 pdu_size;
  __u8 pad[5];
  union {
    struct {
      __u32 family;
      __u32 type;
      __u32 protocol;
    } socket;
    struct {
      __u64 flags;
      __u64 mode;
      __u64 resolve;
    } open;
  };
};
enum {
  IO_URING_BPF_FILTER_DENY_REST = 1,
  IO_URING_BPF_FILTER_SZ_STRICT = 2,
};
struct io_uring_bpf_filter {
  __u32 opcode;
  __u32 flags;
  __u32 filter_len;
  __u8 pdu_size;
  __u8 resv[3];
  __u64 filter_ptr;
  __u64 resv2[5];
};
enum {
  IO_URING_BPF_CMD_FILTER = 1,
};
struct io_uring_bpf {
  __u16 cmd_type;
  __u16 cmd_flags;
  __u32 resv;
  union {
    struct io_uring_bpf_filter filter;
  };
};
#endif
