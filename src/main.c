#include <stdlib.h>
#include <string.h>
#include "spark.h"

signed
main (signed argc, char * argv []) {

    size_t arglen = (size_t )argc;

    uintmax_t * data = malloc(arglen * sizeof (uintmax_t));
    if ( !data || arglen <= 1 ) {
        fputs("Everything's on fire\n", stderr);
        return EXIT_FAILURE;
    }

    for ( size_t i = 1; i < arglen; ++ i ) {
        sscanf(argv[i], "%" SCNuMAX, &data[i - 1]);
    }

    char buffer[arglen * 3 + 1];
    memset(buffer, 0, arglen * 3 + 1);

    spark_char(arglen - 1, data, buffer);
    puts(buffer);

    return EXIT_SUCCESS;
}
