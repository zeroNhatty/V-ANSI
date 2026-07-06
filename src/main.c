#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "include/values.h"
#include "include/colors.h"

void findVideo(char* path) {
    FILE *f;

    f= fopen(path, "r");
    if (!f) {
        fprintf(stderr, "Can't open file %s\n", path);
        return;
    }


}

void warnWrongUsage(char* msg) {
    printf("%sWarning:\033[m %s!", YELLOW_ANSI_COLOR, msg );
    printf("%s", helpCommand);
}

int main(const int argc, char* argv[]) {
    char *argument = NULL;
    switch (argc) {
        case 1:
            warnWrongUsage("arguments must be provided!");
            return -1;
        case 2:
            argument = argv[1];
            bool isHelp = strcmp(argument, "help") == 0;
            if(isHelp) {
                printf("%s", helpCommand);
                return 0;
            }
            else {
                warnWrongUsage("unknown arguments!");
            }
            break;
        case 3:
            argument = argv[1];
            bool is_d_argument = strcmp(argument, "-d") == 0;
            if(is_d_argument) findVideo(argv[2]);
            else {
                warnWrongUsage("unknown arguments!");
            }
            break;
        default:
            warnWrongUsage("too much number of arguments!");
            break;
    }
    /*
     * let's assume we have 3 flags
     * -d to tell the program
     * whatever comes next is the path for the media file
     * help to get description of commands
     * so we only strictly use -d <path> and help alone so a max of 3
     */
}