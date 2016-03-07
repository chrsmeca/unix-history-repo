/*
 * Crude test driver for processing the VST and MCT testvector files
 * generated by the CMVP RNGVS product.
 *
 * Note the input files are assumed to have a _very_ specific format
 * as described in the NIST document "The Random Number Generator
 * Validation System (RNGVS)", May 25, 2004.
 *
 */
#include <openssl/opensslconf.h>

#ifndef OPENSSL_FIPS
# include <stdio.h>

int main(int argc, char **argv)
{
    printf("No FIPS RNG support\n");
    return 0;
}
#else

# include <openssl/bn.h>
# include <openssl/dsa.h>
# include <openssl/fips.h>
# include <openssl/err.h>
# include <openssl/rand.h>
# include <openssl/fips_rand.h>
# include <openssl/x509v3.h>
# include <string.h>
# include <ctype.h>

# include "fips_utl.h"

static void vst()
{
    unsigned char *key = NULL;
    unsigned char *v = NULL;
    unsigned char *dt = NULL;
    unsigned char ret[16];
    char buf[1024];
    char lbuf[1024];
    char *keyword, *value;
    long i, keylen;

    keylen = 0;

    while (fgets(buf, sizeof buf, stdin) != NULL) {
        fputs(buf, stdout);
        if (!strncmp(buf, "[AES 128-Key]", 13))
            keylen = 16;
        else if (!strncmp(buf, "[AES 192-Key]", 13))
            keylen = 24;
        else if (!strncmp(buf, "[AES 256-Key]", 13))
            keylen = 32;
        if (!parse_line(&keyword, &value, lbuf, buf))
            continue;
        if (!strcmp(keyword, "Key")) {
            key = hex2bin_m(value, &i);
            if (i != keylen) {
                fprintf(stderr, "Invalid key length, expecting %ld\n",
                        keylen);
                return;
            }
        } else if (!strcmp(keyword, "DT")) {
            dt = hex2bin_m(value, &i);
            if (i != 16) {
                fprintf(stderr, "Invalid DT length\n");
                return;
            }
        } else if (!strcmp(keyword, "V")) {
            v = hex2bin_m(value, &i);
            if (i != 16) {
                fprintf(stderr, "Invalid V length\n");
                return;
            }

            if (!key || !dt) {
                fprintf(stderr, "Missing key or DT\n");
                return;
            }

            FIPS_rand_set_key(key, keylen);
            FIPS_rand_seed(v, 16);
            FIPS_rand_set_dt(dt);
            if (FIPS_rand_bytes(ret, 16) <= 0) {
                fprintf(stderr, "Error getting PRNG value\n");
                return;
            }

            pv("R", ret, 16);
            OPENSSL_free(key);
            key = NULL;
            OPENSSL_free(dt);
            dt = NULL;
            OPENSSL_free(v);
            v = NULL;
        }
    }
}

static void mct()
{
    unsigned char *key = NULL;
    unsigned char *v = NULL;
    unsigned char *dt = NULL;
    unsigned char ret[16];
    char buf[1024];
    char lbuf[1024];
    char *keyword, *value;
    long i, keylen;
    int j;

    keylen = 0;

    while (fgets(buf, sizeof buf, stdin) != NULL) {
        fputs(buf, stdout);
        if (!strncmp(buf, "[AES 128-Key]", 13))
            keylen = 16;
        else if (!strncmp(buf, "[AES 192-Key]", 13))
            keylen = 24;
        else if (!strncmp(buf, "[AES 256-Key]", 13))
            keylen = 32;
        if (!parse_line(&keyword, &value, lbuf, buf))
            continue;
        if (!strcmp(keyword, "Key")) {
            key = hex2bin_m(value, &i);
            if (i != keylen) {
                fprintf(stderr, "Invalid key length, expecting %ld\n",
                        keylen);
                return;
            }
        } else if (!strcmp(keyword, "DT")) {
            dt = hex2bin_m(value, &i);
            if (i != 16) {
                fprintf(stderr, "Invalid DT length\n");
                return;
            }
        } else if (!strcmp(keyword, "V")) {
            v = hex2bin_m(value, &i);
            if (i != 16) {
                fprintf(stderr, "Invalid V length\n");
                return;
            }

            if (!key || !dt) {
                fprintf(stderr, "Missing key or DT\n");
                return;
            }

            FIPS_rand_set_key(key, keylen);
            FIPS_rand_seed(v, 16);
            for (i = 0; i < 10000; i++) {
                FIPS_rand_set_dt(dt);
                if (FIPS_rand_bytes(ret, 16) <= 0) {
                    fprintf(stderr, "Error getting PRNG value\n");
                    return;
                }
                /* Increment DT */
                for (j = 15; j >= 0; j--) {
                    dt[j]++;
                    if (dt[j])
                        break;
                }
            }

            pv("R", ret, 16);
            OPENSSL_free(key);
            key = NULL;
            OPENSSL_free(dt);
            dt = NULL;
            OPENSSL_free(v);
            v = NULL;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "%s [mct|vst]\n", argv[0]);
        exit(1);
    }
    if (!FIPS_mode_set(1)) {
        do_print_errors();
        exit(1);
    }
    FIPS_rand_reset();
    if (!FIPS_rand_test_mode()) {
        fprintf(stderr, "Error setting PRNG test mode\n");
        do_print_errors();
        exit(1);
    }
    if (!strcmp(argv[1], "mct"))
        mct();
    else if (!strcmp(argv[1], "vst"))
        vst();
    else {
        fprintf(stderr, "Don't know how to %s.\n", argv[1]);
        exit(1);
    }

    return 0;
}
#endif
