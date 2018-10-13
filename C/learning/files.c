#include <stdio.h>

int main() {

    // reading from the file
    FILE * fp;           // pointer to the file
    fp = fopen("read.txt", "r");     // r here is the mode and currently set to reading mode
    char line[256];                // temporary storage of the lines, because this program is reading line by line
    while (fgets(line, sizeof(line), fp)) {
        // fgets() function gets, a line of size of line
        printf("%s", line);      // just printing the line to the user
    }

    // Closing the FILE
    fclose(fp);

    // Writing to the FILE
    fp = fopen("read.txt", "w");     // w here is the mode and currently set to writing mode
    char *towrite = "i love cheese\nbacons\nbeef\n";      // Things i want to write to the file
    fprintf(fp, "%s", towrite);     // This function writes to the file essentially overwriting to it

    // Closing the FILE
    fclose(fp);

    // Writing to the FILE
    fp = fopen("read.txt", "a");     // a here is the mode and currently set to append mode
    towrite = "porkchop\n";
    fprintf(fp, "%s", towrite);

    // Closing the FILE
    fclose(fp);

    return 0;
}
