#include "string_manip.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_occurrence(const char *src, const char *occurrence)
{
    char *occ_p = (char *)occurrence, *src_p = (char *)src;
    while (*occ_p != '\0')
        if (*occ_p++ != *src_p++) return 0;
    return 1;
}

const char *str_replace(char *dest, const char *src, const char *r_text, const char *n_text)
{
    char *dest_p = dest, *src_p = (char *)src, *r_text_p = (char *)r_text, *n_text_p = (char *)n_text, *src_p_temp;
    int eq;
    while (*src_p != '\0') {
        if (*src_p == *r_text_p) {
            src_p_temp = src_p, eq = 1;
            while (*r_text_p != '\0')
                // if replace text differs from source at any position
                if (*r_text_p++ != *src_p++) {
                    src_p = src_p_temp, eq = 0;
                    *dest_p++ = *src_p++;
                    break;
                }
            if (eq) {
                while (*n_text_p != '\0')
                    *dest_p++ = *n_text_p++;
                n_text_p = (char *)n_text;
            }
            r_text_p = (char *)r_text;
        } else {
            *dest_p++ = *src_p++;
        }
    }
    *dest_p = '\0';
    return dest;
}

char **str_split(char ***dest, const char *src, const char *delim)
{
    int occur = str_occurrences(src, delim) + 2;
    char *src_temp = (char *)malloc((strlen(src) + 1) * sizeof(char)), *token;
    char **dest_p = *dest = (char **)malloc(occur * sizeof(char *));
    sprintf(src_temp, "%s", src);
    for(token = strtok(src_temp, delim); token != NULL; token = strtok(NULL, delim), dest_p++) {
        *dest_p = (char *)malloc(strlen(token) + 1 * sizeof(char));
        sprintf(*dest_p, "%s", token);
    }
    *dest_p = NULL;
    free(src_temp);
    return *dest;
}

void str_split_free(char ***dest)
{
    char **dest_p = *dest;
    while (*dest_p != NULL)
        free(*dest_p), dest_p++;
    free(*dest);
}

const char *str_capitalize(char *dest, const char *src, int from_idx, int to_idx)
{
    return dest;
}

int str_occurrences(const char *src, const char *occurrence)
{
    char *src_p = (char *)src, *occ_p = (char *)occurrence, *src_p_temp;
    int i, eq;
    for (i = 0; *src_p != '\0'; src_p++)
        if (*src_p == *occ_p) {
            src_p_temp = src_p, eq = 1;
            while (*occ_p != '\0')
                if (*occ_p++ != *src_p++) {
                    src_p = src_p_temp, eq = 0;
                    break;
                }
            if (eq) ++i;
            occ_p = (char *)occurrence;
            // if (is_occurrence(src_p + 1, occ_p + 1)) ++i;
        }
    return i;
}
