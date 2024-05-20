#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *option = argv[1];
    char *filename = argv[2];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    if (strcmp(option, "-c") == 0) {
        int char_count = 0;
        int c;
        while ((c = fgetc(file)) != EOF) {
            char_count++;
        }
        printf("×Ö·ûÊý£º%d\n", char_count);
    } else if (strcmp(option, "-w") == 0) {
        int word_count = 0;
        int in_word = 0;
        int c;
        while ((c = fgetc(file)) != EOF) {
            if (c == ' ' || c == '\n' || c == '\t') {
                if (in_word) {
                    word_count++;
                    in_word = 0;
                }
            } else {
                in_word = 1;
            }
        }
        if (in_word) {
            word_count++;
        }
        printf("µ¥´ÊÊý£º%d\n", word_count);
    } else {
        printf("Invalid option. Please use -c or -w.\n");
    }

    fclose(file);
    return 0;
}
