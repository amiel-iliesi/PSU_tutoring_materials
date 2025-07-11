#include <stdio.h> // IO
#include <stdlib.h> // basic macros: EXIT_SUCCESS
#include <unistd.h> // getopt
#include <stdbool.h> // bool

// user supplies 2 numbers to do a math problem:
// we want to calculate: (n / d)
// * n, d are required to have an argument
// * v has no argument

int main(int argc, char * argv[])
{
    // flags
    bool n_given = false;
    bool d_given = false;

    // variables
    long n;
    long d;
    bool verbose = false;

    // get options from command line
    int opt;
    while ((opt = getopt(argc, argv, "n:d:v")) != -1) {
        switch (opt) {
            case 'n':
                n = strtol(optarg, NULL, 10);

                n_given = true;
                break;
            case 'd':
                d = strtol(optarg, NULL, 10);

                d_given = true;
                break;
            case 'v':
                verbose = true;
                break;
            case '?':
            default:
                fprintf(stderr, "ERROR, not all arguments supplied; usage:\n%s -n # -d # [-v]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // error case(s)
    if (!n_given || !d_given) {
        fprintf(stderr, "ERROR, not all arguments supplied; usage:\n%s -n # -d # [-v]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // do work
    if (verbose) {
        fprintf(stderr, "~~ supplied: {n=%li, d=%li}\n", n, d);
    }

    printf("%li / %li = %f\n", n, d, ((float)n/d));

    return EXIT_SUCCESS;
}
