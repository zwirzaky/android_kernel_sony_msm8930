#ifndef _XT_MARK_H
#define _XT_MARK_H

#include <linux/types.h>

struct xt_mark_tginfo2 {
	__u32 mark, mask;
};

struct xt_mark_mtinfo1 {
	__u32 mark, mask;
	__u8 invert;
};

enum {
	XT_HMARK_SADDR_MASK,
	XT_HMARK_DADDR_MASK,
	XT_HMARK_SPI,
	XT_HMARK_SPI_MASK,
	XT_HMARK_SPORT,
	XT_HMARK_DPORT,
	XT_HMARK_SPORT_MASK,
	XT_HMARK_DPORT_MASK,
	XT_HMARK_PROTO_MASK,
	XT_HMARK_RND,
	XT_HMARK_MODULUS,
	XT_HMARK_OFFSET,
	XT_HMARK_CT,
	XT_HMARK_METHOD_L3,
	XT_HMARK_METHOD_L3_4,
};
#define XT_HMARK_FLAG(flag)	(1 << flag)

union hmark_ports {
	struct {
		__u16	src;
		__u16	dst;
	} p16;
	struct {
		__be16	src;
		__be16	dst;
	} b16;
	__u32	v32;
	__be32	b32;
};

struct xt_hmark_info {
	union nf_inet_addr	src_mask;
	union nf_inet_addr	dst_mask;
	union hmark_ports	port_mask;
	union hmark_ports	port_set;
	__u32			flags;
	__u16			proto_mask;
	__u32			hashrnd;
	__u32			hmodulus;
	__u32			hoffset;	/* Mark offset to start from */
};

#endif /*_XT_MARK_H*/
