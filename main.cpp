#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <netinet/in.h>

#include "read_4bytes.h"

int main(int argc, char** argv){
	if(argc != 3){
		printf("wrong number of arguments: should be 2, got %d", argc - 1);
		return 0;
	}
	uint32_t num1 = read_4bytes(argv[1]);
	uint32_t num2 = read_4bytes(argv[2]);
	
	num1 = ntohl(num1);
	num2 = ntohl(num2);
	uint32_t sum = num1 + num2;

	printf("%u(0x%x) + %u(0x%x)", num1, num1, num2, num2);
	printf(" = %u(0x%x)", sum, sum);
	return 0;
}
