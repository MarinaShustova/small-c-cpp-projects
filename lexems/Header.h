#ifndef PROG_H
#define PROG_H
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#define NO_ERR 0
#define ERR_NOSTR 1
int lex(char *str, int *out);
#endif
