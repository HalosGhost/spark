#include "spark.h"

static const char * spark_bars [] = { "▂", "▃", "▄", "▅", "▆","▇","█" };
static const size_t spark_barsl = sizeof spark_bars / sizeof *spark_bars;

static const char *
spark_bar(uintmax_t, uintmax_t, uintmax_t);

char *
spark_char (size_t len, const uintmax_t * data, char * buf) {

    if ( !buf ) {
        return NULL;
    }

    uintmax_t min = UINTMAX_MAX, max = 0;
    for ( size_t i = 0; i < len; ++ i ) {
        uintmax_t tmp = data[i];
        max = tmp > max ? tmp : max;
        min = tmp < min ? tmp : min;
    }

    for ( size_t i = 0; i < len; ++i ) {
        const char * str = spark_bar(data[i], min, max);
        sprintf(buf + i * 3, "%3s", str);
    }

    return buf;
}

static const char *
spark_bar(uintmax_t x, uintmax_t base, uintmax_t max) {

    const size_t idx = spark_barsl * (x - base) / (max - base);
    return spark_bars[idx >= spark_barsl ? spark_barsl - 1 : idx];
}
