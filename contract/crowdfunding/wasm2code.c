#include <stdio.h>
#include "crowdfunding.wasm.h"

int main()
{
	if (sizeof(crowdfunding_wasm) != crowdfunding_wasm_len)
	{
		printf("wrong code");
		return -1;
	}
	
	for (int i = 0; i < crowdfunding_wasm_len; i++)
	{
		printf("%02x", crowdfunding_wasm[i]);
	}
	printf("\n");
	return 0;
}
