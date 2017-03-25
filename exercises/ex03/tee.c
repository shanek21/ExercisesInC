/*
 * Tee reads from stdin and outputs to both stdout and a file
 */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char ch;
    int append = 0;

    // Read command line options
    while ((ch = getopt(argc, argv, "a")) != -1) {
        switch (ch) {
        case 'a':
            append = 1;
            break;
        default:
            return 1;
        }
    }

    // Increment through already parsed arguments
    argc -= optind;
    argv += optind;

    int i = 0;
    FILE *files[argc];
    char word[100];

    // Fill an array with pointers to each file
    for (i = 0; i < argc; i++) {
        files[i] = fopen(argv[i], (append ? "a" : "w"));
    }

    // Write stdin to stdout and each file
    while (fscanf(stdin, "%s", word) == 1) {
        for (i = -1; i < argc; i++) {
            if (i == -1) {
                fprintf(stdout, "%s ", word);
            } 
            else {
                fprintf(files[i], "%s ", word);
            }
        }
    }

    // Send newline to stdout and all files, then close
    fprintf(stdout, "\n"); 
    for (i = 0; i < argc; i++) {
        fprintf(files[i], "\n");
        fclose(files[i]);
    }

return 0;

}

// Exercise Questions:
// 3) I was able to use some code from HFC, which helped for the optarg part,
//    but figuring out how to write stdin to multiple files was very tricky.
// 4) The professional code has a lot of error checking and directly uses
//    buffers to read stdin and write to the files.
