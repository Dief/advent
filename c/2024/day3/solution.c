#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INPUT_FILE "../../../inputs/2024/day3/input.txt"
#define MAX_LINE 4096
#define MAX_BLOB MAX_LINE * 8

int mul(char *str) {
    char *c, *start2;
    if (strncmp(str, "mul(", 4) == 0) {
        c = str + 4;
        if (!isdigit(*c))
        {
            return 0;
        }
        while (*c != ',')
        {
            if (isdigit(*c))
            {
                c++;
            }
            else
            {
                return 0;
            }
        }
        start2 = ++c;
        if (!isdigit(*c))
        {
            return 0;
        }
        while (*c != ')')
        {
            if (isdigit(*c))
            {
                c++;
            }
            else
            {
                return 0;
            }
        }
        return atoi(str + 4) * atoi(start2);
    }
    return 0;
}

int part1(char *input, int len) {
    int i, total = 0;
    for (i = 0; i < len; i++)
    {
        total += mul(input + i);
    }
    return total;
}

int part2(char *input, int len) {
    int i, total = 0, in = 1;
    for (i = 0; i < len; i++)
    {
        if (in)
        {
            total += mul(input + i);
            if (strncmp(input + i, "don't()", 7) == 0)
            {
                in = 0;
            }
        }
        else if (strncmp(input + i, "do()", 4) == 0)
        {
            in = 1;
        }
    }
    return total;
}

int main()
{
    char line[MAX_LINE], input[MAX_BLOB];
    FILE *file = fopen(INPUT_FILE, "r");
    int len;
    bzero(input, MAX_BLOB);
    while (fgets(line, MAX_LINE, file) != NULL)
    {
        line[strlen(line) - 1] = '\0';
        strcat(input, line);
    }
    fclose(file);
    len = strlen(input);
    printf("Part 1: %d\n", part1(input, len));
    printf("Part 2: %d\n", part2(input, len));
    return 0;
}
