#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char * xor_encrypt(char *buffer, char *key) {

    char *output = buffer;

    // Iterating over the letters
    int j = 0;
    for (int i = 0; i < strlen(buffer); i++) {
	output[i] = buffer[i] ^ key[j];
	j++;
	if (j >= strlen(key)) {
	    j = 0;
	}
    }

    return output;
}


int main(int argc, char **argv) {
    
    // checking the arguments
    if (argc != 4) {
	printf("Usage: %s [input file] [output file] [key]", argv[0]);
	return 1;
    }

    // getting the files
    FILE *infile;
    FILE *outfile;
    infile = fopen(argv[1], "r");
    outfile = fopen(argv[2], "a");

    // encoding everything with the key
    char content[256];
    while (fgets(content, sizeof(content), infile)) {
	strncpy(content, xor_encrypt(content, argv[3]), sizeof(content));
	fprintf(outfile, "%s", content);
    }

    return 0;
}
