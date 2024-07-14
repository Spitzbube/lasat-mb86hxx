

#include "data.h"
#include "lwip/tcpip.h"
#include "lwip/netif.h"
#include "lwip/dhcp.h"

#if 0

extern void web_interface_http_thread();
extern void web_interface_streaming_thread();
extern void sub_2345ace8();


//0x234920e8
int Data_234920e8 = 0; //234920e8 +0
void (*Data_234920ec)() = 0; //234920ec +4
int Data_234920f0 = 0; //234920f0 +8
#endif
struct netif* network_pNetIF = 0; //234920f4 +0xc
#if 0
int Data_234920f8; //234920f8 +0x10
ip_addr_t network_ipaddr; //23492100
ip_addr_t network_netmask; //23492104
ip_addr_t network_gw; //23492108
ip_addr_t network_dns; //2349210c

struct netif Data_235b0c60; //235b0c60

#endif


/* 23418eac - todo */
static void on_tcpip_init_done(void* arg)
{
#if 1
	console_send_string("on_tcpip_init_done (todo.c): TODO\r\n");
#endif

	//sub_23487ab0();
	sys_sem_signal(arg);
}


/* 23418eb0 - todo */
int network_lwip_init()
{
#if 1
	console_send_string("network_lwip_init (todo.c): TODO\r\n");
#endif

	sys_sem_t tcpip_init_sema; //sp_0x54

#if 0
	struct
	{
		int fill_0; //0

	} sp_0x3c;

	struct
	{
		int Data_0; //0
		int Data_4; //4
		//8?
	} sp_0x34;

	struct
	{
		ip_addr_t Data_0; //0
		ip_addr_t Data_4; //4
		ip_addr_t Data_8; //8
		//12?
	} sp_0x28;

	struct Struct_234fd8f0_Inner_489DC sp_0x14;

	struct Struct_234fd8f0_Inner_489DC sp;
#endif

	int sl = 0;

#if 0
	if (0 != sub_23437044())
	{
		//loc_23419118
		return 0xff;
	}
	//23418ec8
	sub_2340c9b0(1, &sp_0x28);
	sub_2340ca1c(1, &sp_0x14);

	if (sp_0x14.Data_4 & 1)
	{
		ip_addr_copy(network_ipaddr, sp_0x28.Data_0);
		ip_addr_copy(network_netmask, sp_0x28.Data_4);
		ip_addr_copy(network_gw, sp_0x28.Data_8);
	}
	else
	{
		IP4_ADDR(&network_ipaddr, 0,0,0,0);
		IP4_ADDR(&network_netmask, 0,0,0,0);
		IP4_ADDR(&network_gw, 0,0,0,0);
	}

	if (Data_234920ec != 0)
	{
		(Data_234920ec)(&sp_0x3c, &sp_0x34);
	}
#endif

	sys_sem_new(&tcpip_init_sema, 0);

	tcpip_init(on_tcpip_init_done, &tcpip_init_sema);

#if 0
	sys_mutex_lock(&tcpip_init_sema, 0);
#else
	sys_sem_wait(&tcpip_init_sema);
#endif

	sys_sem_free(&tcpip_init_sema);

#if 0 //Don't start the FAPI based Ethernet Interface
	if ((sp_0x34.Data_0 == 11) &&
			(sp_0x34.Data_4 == 0x12345678))
	{
		//23418f6c
		sl = 2;

		network_ipaddr = ipaddr_addr("192.168.0.5");
		network_netmask = ipaddr_addr("255.255.255.0");
		network_gw = ipaddr_addr("000.000.000.0");
	}
	//loc_23418f94
	if (0 != sub_23436e68(0, &sp_0x3c))
	{
		//loc_23419118
		return 0xff;
	}
	//23418fa8
	extern err_t ethif_fapi_init(struct netif *netif);

	network_pNetIF = netif_add(&Data_235b0c60,
			&network_ipaddr,
			&network_netmask,
			&network_gw,
			NULL, //state
			ethif_fapi_init,
			tcpip_input);
#endif

#if 0
	if (network_pNetIF == NULL)
	{
		//->loc_23419118
		return 0xff;
	}
	//23418fd8
	Data_235b0c60.flags |= NETIF_FLAG_IGMP;

	if (Data_235b0c60.flags & NETIF_FLAG_IGMP)
	{
		//23418ff0
		igmp_init();
		igmp_start(&Data_235b0c60);
	}
	//loc_23418ffc
	netif_set_default(&Data_235b0c60);

	if (Data_235b0c60.ip_addr.addr != 0)
	{
		//23419010
		netif_set_up(&Data_235b0c60);

		network_dns.addr = sp_0x14.Data_0;

		dns_setserver(0, &network_dns);
		//->loc_2341910c
	}
	else
	{
		//loc_23419030
		sub_234114e4();

		dhcp_start(&Data_235b0c60);

		int32_t r4 = 0;

		while (Data_235b0c60.ip_addr.addr == 0)
		{
			//loc_23419048
			sub_23469970(500);
			dhcp_fine_tmr();

			r4 += 500;

			if (r4 >= 60000)
			{
				//23419060
				dhcp_coarse_tmr();

				r4 = 0;
				//->loc_23419078
				break;
			}
			//loc_2341906c
		} //while
		//loc_23419078
		dhcp_stop(&Data_235b0c60);

		if (Data_235b0c60.ip_addr.addr != 0)
		{
			//2341908c
			netif_set_up(&Data_235b0c60);

			if (Data_235b0c60.dhcp->bData_0xf != 0)
			{
				//234190a4
				sub_2340ca1c(1, &sp);

				sp.Data_16 = Data_235b0c60.dhcp->Data_0x30.addr;

				sub_2340ca1c(0, &sp);
			}
			//loc_234190c8
		}
		//loc_234190c8
		if (r4 == 0)
		{
			//234190d0
			network_ipaddr = sp_0x28.Data_0;
			network_netmask = sp_0x28.Data_4;
			network_gw = sp_0x28.Data_8;

			netif_set_addr(&Data_235b0c60,
					&network_ipaddr,
					&network_netmask,
					&network_gw);

			netif_set_default(&Data_235b0c60);

			netif_set_up(&Data_235b0c60);
		}
		//loc_2341910c
	}
#endif
	//loc_2341910c
	return sl;
}

/* 23419120 - complete */
int network_init(uint32_t r4)
{
	int sp;

#if 1
	console_send_string("network_init (todo.c): TODO\r\n");
#endif

	int r0 = network_lwip_init();

#if 0
	Data_234920f0 = r4;

	if (r0 == 0)
	{
		sub_2345b270();

		sys_thread_new("\n HTTP", web_interface_http_thread, 0, 0, THREAD_PRIO_NETWORK_HTTP);
		//->loc_234191b8
		sys_thread_new("\n streaming", web_interface_streaming_thread, 0, 0, THREAD_PRIO_NETWORK_STREAMING);

		return 0;
	}
	//loc_23419178
	if (r0 == 2)
	{
		//->loc_23419190
		while (0 == sub_2346c10c(&Data_235b0c60))
		{
			//loc_23419188
			rtos_task_wait(5);
		}
		//0x234191a0
		sys_thread_new("\n firsttime INIT ", sub_2345ace8, 0, 0, THREAD_PRIO_NETWORK_INIT);

		return 0;
	}
//#else
	sys_thread_new("\n HTTP", web_interface_http_thread, 0, 0, THREAD_PRIO_NETWORK_HTTP);
	sys_thread_new("\n streaming", web_interface_streaming_thread, 0, 0, THREAD_PRIO_NETWORK_STREAMING);
#endif
	//loc_234191c0
	return 0xff;
}

#if 0

/* 2341930c - todo */
int network_set_defaults(struct Struct_23546128* r5, struct Struct_234fd8f0_Inner_489DC* r8)
{
#if 0
	console_send_string("network_set_defaults (todo.c): TODO\r\n");
#endif

	if (network_ipaddr.addr == 0)
	{
		sub_23487ab8(&Data_235b0c60);
	}

	if ((r8->Data_4 & 1) == 0)
	{
		network_ipaddr.addr = 0;
		network_netmask.addr = 0;
		network_gw.addr = 0;

		netif_set_addr(&Data_235b0c60, &network_ipaddr, &network_netmask, &network_gw);
		dhcp_start(&Data_235b0c60);

		int r4 = 0;
		//->loc_234193ac
		while (Data_235b0c60.ip_addr.addr == 0)
		{
			//loc_2341937c
			sub_23469970(500);
			dhcp_fine_tmr();

			r4 += 500;

			if (r4 >= 60000)
			{
				dhcp_coarse_tmr();

				if (Data_235b0c60.ip_addr.addr != 0)
				{
					//->0x234193a8 -> loc_234193b8
					break;
				}
				//->loc_234193d8
				dhcp_stop(&Data_235b0c60);
				//->loc_234193e0
				network_ipaddr.addr = r5->Data_0;
				network_netmask.addr = r5->Data_4;
				network_gw.addr = r5->Data_8;

				netif_set_addr(&Data_235b0c60, &network_ipaddr, &network_netmask, &network_gw);
				netif_set_default(&Data_235b0c60);
				netif_set_up(&Data_235b0c60);
				//->loc_234193c4
				dns_setserver(0, &network_dns);

				return 0;
			}
			//loc_234193ac
		} //while (Data_235b0c60.ip_addr.addr == 0)
		//loc_234193b8
		network_dns.addr = ipaddr_addr("208.67.222.222"); //resolver1.opendns.com
		//loc_234193c4
		dns_setserver(0, &network_dns);
	}
	else
	{
		//loc_234193e0
		network_ipaddr.addr = r5->Data_0;
		network_netmask.addr = r5->Data_4;
		network_gw.addr = r5->Data_8;

		netif_set_addr(&Data_235b0c60, &network_ipaddr, &network_netmask, &network_gw);
		netif_set_default(&Data_235b0c60);
		netif_set_up(&Data_235b0c60);
		//->loc_234193c4
		dns_setserver(0, &network_dns);

	}
	//loc_234193c4
//	dns_setserver(0, &network_dns);

	return 0;
}

#endif

/* 23419430 - todo */
struct netif* network_get_device()
{
#if 0
	console_send_string("network_get_device (todo.c): TODO\r\n");
#endif

	return network_pNetIF;
}

#if 0

/* 2341943c - todo */
uint32_t network_get_ipaddr()
{
#if 0
	console_send_string("network_get_ipaddr (todo.c): TODO\r\n");
#endif

	return Data_235b0c60.ip_addr.addr;
}


/* 23419454 - todo */
void sub_23419454(void (*a)())
{
#if 0
	console_send_string("sub_23419454 (todo.c): TODO\r\n");
#endif

	Data_234920ec = a;

}


/* 23419520 - todo */
void sub_23419520 ()
{
	console_send_string("sub_23419520 (todo.c): TODO\r\n");

}


/* 234197d0 - complete */
void* sub_234197d0(int a)
{
#if 0
	console_send_string("sub_234197d0 (todo.c): TODO\r\n");
#endif

	ip_addr_t sp;

	rtos_task_wait(100);

	struct udp_pcb* pcb = udp_new();

	sp.addr = 0xfe7f02e0; //224.02.127.254
	igmp_joingroup(IP_ADDR_ANY, &sp);

	sp.addr = 0xffffc0ef;
	igmp_joingroup(IP_ADDR_ANY, &sp);

	sp.addr = 0x10;
	igmp_joingroup(IP_ADDR_ANY, &sp);

	sp.addr = 0xff0000e0;
	igmp_joingroup(IP_ADDR_ANY, &sp);

	Data_234920f8 = a;

	udp_bind(pcb, IP_ADDR_ANY, 9875);
	udp_recv(pcb, sub_23419520, NULL);

	return pcb;
}

#endif
