#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    ARG_NUMERATOR_SHORT,
    ARG_NUMERATOR_LONG,
    ARG_DENOMINATOR_SHORT,
    ARG_DENOMINATOR_LONG,
} arg_t;


static const char *valid_args[] = {
    [ARG_NUMERATOR_SHORT] = "-n",
    [ARG_NUMERATOR_LONG] = "--numerador",
    [ARG_DENOMINATOR_SHORT] = "-d",
    [ARG_DENOMINATOR_LONG] = "--denominador",
};


int parse_arguments(int argc, char *argv[], double *num, double *den)
{
    char *pend = NULL;
    double _num;
    double _den;
    int arg;
    bool num_processed = false;
    bool den_processed = false;

    if (argc < 5) {
        return 1;
    }

    if (argc > 5) {
        return 1;
    }

    if ((NULL == argv) || (NULL == num) || (NULL == den)) {
        return 1;
    }

    for (int i = 1; i < argc - 1; ++i) {
        /* search argument index comparing input argument with valid arguments */
        for (arg = 0; arg < sizeof(valid_args) / sizeof(valid_args[0]); ++arg) {
            if (strcmp(argv[i], valid_args[arg])==true) {
                printf("argv[%i]=%s\n",i,argv[i]);
                break;
            }
        }
        switch (arg) {
            case ARG_NUMERATOR_SHORT:
            case ARG_NUMERATOR_LONG:
                i++;
                _num = strtod(argv[i], &pend);
                if ('\0' != *pend) {
                    return 1;
                }
                num_processed = true;
                break;
            case ARG_DENOMINATOR_SHORT:
            case ARG_DENOMINATOR_LONG:
                i++;
                _den = strtod(argv[i], &pend);
                if ('\0' != *pend) {
                    return 1;
                }
                den_processed = true;
                break;
            default:
                return 1;
        }
    }

    if ((num_processed == false) || (den_processed == false)) {
        return 1;
    }

    *num = _num;
    *den = _den;

    return 0;
}

int main(int argc, char *argv[]){
    double num;
    double den;
    parse_arguments(argc, argv, &num, &den);

    return 0;
}