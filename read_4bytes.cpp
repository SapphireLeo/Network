#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define READ_BYTE 4
#define MAX_FILE_NAME_LEN 100

uint32_t read_4bytes(char* fileName)
{
	FILE* file_stream;
	if(strlen(fileName) > MAX_FILE_NAME_LEN){
		perror("read_4bytes: file name is too long");
		return 0;
	}
	char file_name[MAX_FILE_NAME_LEN + 2] = "./";
	strcat(file_name, fileName);
	uint32_t buffer;
	
	if ((file_stream = fopen(file_name, "rb")) != NULL){
		memset(&buffer, 0, sizeof(buffer));
		fseek(file_stream, 0, SEEK_SET);
		int num = fread(&buffer, sizeof(buffer), 1, file_stream);
		if (num) {
			fclose(file_stream);
			return buffer;
		}
		else {
			perror("Error with reading file.");
		}
	} else {
		perror("Error with opening file.");
	}
	return 0;
}


