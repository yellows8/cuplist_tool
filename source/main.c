#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char cupbuf[0x800];

int main(int argc, char **argv)
{
	unsigned int tidindex;
	unsigned int total_titles = 0;
	unsigned long long *tidlist = (unsigned long long*)cupbuf;
	FILE *f;

	if(argc==1)return 0;
	memset(cupbuf, 0, 0x800);
	
	f = fopen(argv[1], "rb");
	fread(cupbuf, 1, 0x800, f);
	fclose(f);

	for(tidindex=0; tidindex<0x100; tidindex++)
	{
		if(tidlist[tidindex]==0)break;
		total_titles++;
	}

	printf("Total titles: %u\n", total_titles);
	for(tidindex=0; tidindex<total_titles; tidindex++)
	{
		printf("%u: %016llx\n", tidindex, tidlist[tidindex]);
	}

	return 0;
}

