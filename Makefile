.SUFFIXES: .c .o
CC = gcc
EXEC = networkMST
CCFLAGS = -g -pedantic -Wall -Wextra
OBJS = main1.o create_graph.o

${EXEC}: ${OBJS}
	${CC} ${CCFLAGS} -lm -o ${EXEC} ${OBJS}

.c.o:
	${CC} ${CCFLAGS} -c $<

run: ${EXEC}
	./${EXEC}

clean:
	rm -f ${EXEC} ${OBJS}

main1.o: main1.c
create_graph.o: create_graph.c create_graph.h
