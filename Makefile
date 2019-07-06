CC			= gcc

CFLAGS		+= -O2 -W -Wall -g3

#PROGRAM		= $(basename $(pwd))
PROGRAM		= file_dump
OBJS		= $(PROGRAM).o common.o

$(PROGRAM):	$(OBJS)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJS)

$(PROGRAM).o:	$(PROGRAM).c
	$(CC) $(CFLAGS) -c $(PROGRAM).c

common.o:	common.c
	$(CC) $(CFLAGS) -c common.c

.PHONY:		clean
clean:
	rm -f *.o
