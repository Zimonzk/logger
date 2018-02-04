CC 	= gcc
CFLAGS 	= -I ./include -Wall -std=c99

lib:main.c include/zimonzk/logger.h
	$(CC) $(CFLAGS) -c $<
	ar -rcs liblogger.a main.o


	
