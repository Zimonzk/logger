/** @file
 *  \brief implementation of the logging utilities
 *
 */
#include "zimonzk/logger.h"

int global_verbosity;

void set_verbosity(int v)
{
  global_verbosity = v;
}

void zlog(int verbosity, char* fmt, ...)
{
  if(global_verbosity >= verbosity) {
    va_list args;
    va_start(args, fmt);
    printf("LOG:   ");
    vprintf(fmt, args);
    va_end(args);
    printf("\n");
  }
}

void warn(char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    printf("\x1B[33mWARN:  ");
    vprintf(fmt, args);
    va_end(args);
    printf("\x1B[0m\n");
}

void error(char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "\x1B[31mERROR: \x1B[31m");
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, "\x1B[0m\n");
}

void f_fatal(unsigned long line, char* file, char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "\x1B[31mFATAL ERROR in file %s at line %lu: \x1B[31m\n", file, line);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, "\nExiting\x1B[0m\n");
		exit(-1);
}

