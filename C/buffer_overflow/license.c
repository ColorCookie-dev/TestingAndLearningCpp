#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(char **argv) {
    printf("USAGE: %s <license>\n", argv[0]);
    exit(1);
}

int main(int argc, char **argv) {
    int key = 728;
    int sum = 0;
    if (argc != 2) {
        usage(argv);
    }

    for (int i=0; i < strlen(argv[1]); i++) {
        sum += (int)(*(argv[1]+i));
    }

    if (sum == key) {
        printf("Access Granted\n");
    }
    else {
        printf("License is wrong: %s\n", argv[1]);
    }

    return 0;
}
