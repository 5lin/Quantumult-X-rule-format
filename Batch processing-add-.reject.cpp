#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file %s\n", argv[1]);
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file %s\n", argv[2]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        // Remove newline character at the end of the line
        line[strcspn(line, "\n")] = '\0';

        // Find the position of the comma after "- IP-CIDR"
        char *comma_position = strstr(line, ",") + 1;

        // Write modified line to output file
        fprintf(output_file, "%s.REJECT\n", comma_position);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
