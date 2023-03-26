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

        // Write modified line to output file
        fprintf(output_file, "- DOMAIN,%s,REJECT\n", line);
    }

    fclose(input_file);
    fclose(output_file);
    printf("\n");
    printf("Your rules should have been converted, please check the new file yourself!");
    printf("\n");
	printf("您的规则应该已经转换好了，请自行查看新文件!");
    printf("\n");
	return 0;
}
