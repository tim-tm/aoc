#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("Failed to open: %s\n", argv[1]);
        return 1;
    }

    int colors[3];

    // NOTE: This is unfinished
    char* line = NULL;
    size_t len;
    size_t sum = 0;
    while (getline(&line, &len, file) != -1) {
        size_t slen = strlen(line);
     
        char* token = strtok(line, " ");
        while (token) {
            printf("%s\n", token);
            token = strtok(NULL, " ");
        }
    }
    return 0;
}
