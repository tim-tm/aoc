#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("%s not found!\n", argv[1]);
        return 1;
    }

    char* line = NULL;
    size_t len = 0;
    size_t sum = 0;
    while (getline(&line, &len, file) != -1) {
        size_t slen = strlen(line);
        int left = -1;
        for (size_t i = 0; i < slen; ++i) {
            if (!line[i]) continue;

            if (isdigit(line[i])) {                    
                left = line[i] - 0x30;
                break;
            }
        }

        int right = -1;
        for (size_t i = slen; i > 0; --i) {
            if (!line[i]) continue;

            if (isdigit(line[i])) {
                right = line[i] - 0x30;
                break;
            }
        }

        size_t num = 0;
        if (left == -1) {
            num = (right * 10) + right;
            sum += num;
        } else if (right == -1) {
            num = (left * 10) + left;
            sum += num;
        } else {
            num = (left * 10) + right;
            sum += num;
        }
    }
    printf("%zu\n", sum);
    return 0;
}
