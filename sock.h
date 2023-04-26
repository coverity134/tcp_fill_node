typedef __signed__ char __s8;
typedef unsigned char __u8;

typedef __signed__ short __s16;
typedef unsigned short __u16;

typedef __signed__ int __s32;
typedef unsigned int __u32;
typedef unsigned int sk_buff_data_t;


typedef signed int s32;
typedef unsigned int u32;

typedef signed short s16;
typedef unsigned short u16;
#define AF_UNSPEC	0


typedef signed char	      int8_t;
typedef unsigned char	    u_int8_t;
typedef short		     int16_t;
typedef unsigned short	   u_int16_t;
typedef int		     int32_t;
typedef unsigned int	   u_int32_t;
#define IFNAMSIZ 16

enum {
	RTM_BASE	= 16,
#define RTM_BASE	RTM_BASE

	RTM_NEWLINK	= 16,
#define RTM_NEWLINK	RTM_NEWLINK
	RTM_DELLINK,
#define RTM_DELLINK	RTM_DELLINK
	RTM_GETLINK,
#define RTM_GETLINK	RTM_GETLINK
	RTM_SETLINK,
#define RTM_SETLINK	RTM_SETLINK

	RTM_NEWADDR	= 20,
#define RTM_NEWADDR	RTM_NEWADDR
	RTM_DELADDR,
#define RTM_DELADDR	RTM_DELADDR
	RTM_GETADDR,
#define RTM_GETADDR	RTM_GETADDR

	RTM_NEWROUTE	= 24,
#define RTM_NEWROUTE	RTM_NEWROUTE
	RTM_DELROUTE,
#define RTM_DELROUTE	RTM_DELROUTE
	RTM_GETROUTE,
#define RTM_GETROUTE	RTM_GETROUTE

	RTM_NEWNEIGH	= 28,
#define RTM_NEWNEIGH	RTM_NEWNEIGH
	RTM_DELNEIGH,
#define RTM_DELNEIGH	RTM_DELNEIGH
	RTM_GETNEIGH,
#define RTM_GETNEIGH	RTM_GETNEIGH

	RTM_NEWRULE	= 32,
#define RTM_NEWRULE	RTM_NEWRULE
	RTM_DELRULE,
#define RTM_DELRULE	RTM_DELRULE
	RTM_GETRULE,
#define RTM_GETRULE	RTM_GETRULE

	RTM_NEWQDISC	= 36,
#define RTM_NEWQDISC	RTM_NEWQDISC
	RTM_DELQDISC,
#define RTM_DELQDISC	RTM_DELQDISC
	RTM_GETQDISC,
#define RTM_GETQDISC	RTM_GETQDISC

	RTM_NEWTCLASS	= 40,
#define RTM_NEWTCLASS	RTM_NEWTCLASS
	RTM_DELTCLASS,
#define RTM_DELTCLASS	RTM_DELTCLASS
	RTM_GETTCLASS,
#define RTM_GETTCLASS	RTM_GETTCLASS

	RTM_NEWTFILTER	= 44,
#define RTM_NEWTFILTER	RTM_NEWTFILTER
	RTM_DELTFILTER,
#define RTM_DELTFILTER	RTM_DELTFILTER
	RTM_GETTFILTER,
#define RTM_GETTFILTER	RTM_GETTFILTER

	RTM_NEWACTION	= 48,
#define RTM_NEWACTION   RTM_NEWACTION
	RTM_DELACTION,
#define RTM_DELACTION   RTM_DELACTION
	RTM_GETACTION,
#define RTM_GETACTION   RTM_GETACTION

	RTM_NEWPREFIX	= 52,
#define RTM_NEWPREFIX	RTM_NEWPREFIX

	RTM_GETMULTICAST = 58,
#define RTM_GETMULTICAST RTM_GETMULTICAST

	RTM_GETANYCAST	= 62,
#define RTM_GETANYCAST	RTM_GETANYCAST

	RTM_NEWNEIGHTBL	= 64,
#define RTM_NEWNEIGHTBL	RTM_NEWNEIGHTBL
	RTM_GETNEIGHTBL	= 66,
#define RTM_GETNEIGHTBL	RTM_GETNEIGHTBL
	RTM_SETNEIGHTBL,
#define RTM_SETNEIGHTBL	RTM_SETNEIGHTBL

	RTM_NEWNDUSEROPT = 68,
#define RTM_NEWNDUSEROPT RTM_NEWNDUSEROPT

	RTM_NEWADDRLABEL = 72,
#define RTM_NEWADDRLABEL RTM_NEWADDRLABEL
	RTM_DELADDRLABEL,
#define RTM_NEWADDRLABEL RTM_NEWADDRLABEL
	RTM_GETADDRLABEL,
#define RTM_GETADDRLABEL RTM_GETADDRLABEL

	RTM_GETDCB = 78,
#define RTM_GETDCB RTM_GETDCB
	RTM_SETDCB,
#define RTM_SETDCB RTM_SETDCB

	__RTM_MAX,
#define RTM_MAX		(((__RTM_MAX + 3) & ~3) - 1)
};


enum
{
	TCA_UNSPEC,
	TCA_KIND,
	TCA_OPTIONS,
	TCA_STATS,
	TCA_XSTATS,
	TCA_RATE,
	TCA_FCNT,
	TCA_STATS2,
	TCA_STAB,
	__TCA_MAX
};



#define __be16	u_int16_t
#define __be32	u_int32_t
#define __be64	u_int64_t

struct sk_buff {
	/* These two members must be first. */
	struct sk_buff		*next;
	struct sk_buff		*prev;
	struct net_device	*dev;
	unsigned long		_skb_dst;
	unsigned int		len,data_len;
	
	sk_buff_data_t		tail;
	sk_buff_data_t		end;
	unsigned char		*head, *data;

};

struct net_device
{
	char 			*ifalias;
	unsigned long		mem_end;	/* shared mem end	*/
	unsigned long		mem_start;	/* shared mem start	*/
	unsigned long		base_addr;	/* device I/O address	*/
	unsigned int		irq;		/* device IRQ number	*/
	int			ifindex;

};

struct tcf_result
{
	unsigned long	class;
	u32		classid;
};

struct tcf_proto
{
	/* Fast access part */
	struct tcf_proto	*next;
	void			*root;
	int			(*classify)(struct sk_buff*, struct tcf_proto*,
					struct tcf_result *);
	__be16			protocol;

	/* All the rest */
	u32			prio;
	u32			classid;
	struct Qdisc		*q;
	void			*data;
	struct tcf_proto_ops	*ops;
};

struct tcmsg
{
	unsigned char	tcm_family;
	unsigned char	tcm__pad1;
	unsigned short	tcm__pad2;
	int		tcm_ifindex;
	__u32		tcm_handle;
	__u32		tcm_parent;
	__u32		tcm_info;
};

struct tcf_proto_ops
{
	struct tcf_proto_ops	*next;
	char			kind[IFNAMSIZ];
	int			(*dump)(struct tcf_proto*, unsigned long,
					struct sk_buff *skb, struct tcmsg*);
};


struct netdev_queue {
/*
 * read mostly part
 */
	struct net_device	*dev;
	
	unsigned long		state;
	
/*
 * write mostly part
 */

	int			xmit_lock_owner;
	/*
	 * please use this field instead of dev->trans_start
	 */
	unsigned long		trans_start;
	unsigned long		tx_bytes;
	unsigned long		tx_packets;
	unsigned long		tx_dropped;
} ____cacheline_aligned_in_smp;



struct Qdisc
{
	
	
	
	unsigned		flags;
#define TCQ_F_BUILTIN		1
#define TCQ_F_THROTTLED		2
#define TCQ_F_INGRESS		4
#define TCQ_F_WARN_NONWC	(1 << 16)
	int			padded;
	struct Qdisc_ops	*ops;
	

	u32			handle;
	u32			parent;


	int			(*reshape_fail)(struct sk_buff *skb,
					struct Qdisc *q);

	void			*u32_node;

	/* This field is deprecated, but it is still used by CBQ
	 * and it will live until better solution will be invented.
	 */
	
	struct netdev_queue	*dev_queue;
	

	
	/*
	 * For performance sake on SMP, we put highly modified fields at the end
	 */
	unsigned long		state;
	
};








struct nlmsghdr
{
	__u32		nlmsg_len;	/* Length of message including header */
	__u16		nlmsg_type;	/* Message content */
	__u16		nlmsg_flags;	/* Additional flags */
	__u32		nlmsg_seq;	/* Sequence number */
	__u32		nlmsg_pid;	/* Sending process port ID */
};

inline int skb_is_nonlinear(const struct sk_buff *skb)
{
	return skb->data_len;
}

inline int skb_tailroom(const struct sk_buff *skb)
{
	return skb_is_nonlinear(skb) ? 0 : skb->end - skb->tail;
}

 inline struct net_device *qdisc_dev(struct Qdisc *qdisc)
{
	return qdisc->dev_queue->dev;
}
 inline unsigned char *skb_tail_pointer(const struct sk_buff *skb)
{
	return skb->head + skb->tail;
}