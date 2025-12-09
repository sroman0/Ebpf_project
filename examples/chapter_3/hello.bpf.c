#include <linux/bpf.h>  
#include <bpf/bpf_helpers.h>

int counter = 0;

SEC("xdp")	//the macro SEC() defines a section called xdp that you'll be able to see in the compiled object file.
int hello(void *ctx){	//actual bpf program

	bpf_printk("Hello World %d", counter);
	counter++;
	return XDP_PASS;	//this inicate the final verdict of the network packet: pass., the kernel process the packet as normal
}

char LICENSE[] SEC("license") = "Dual BSD/GPL";		//crucial requirement for eBPF programs, this is a license string. the verifier will check this license string
