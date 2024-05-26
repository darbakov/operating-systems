.PHONY: run clean

CFLAGS= -g -O0

run: fact
	./$<

fact: fact.o fun.o
	$(CC) $(CFLAGS) -o $@ $?

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o *~ fact


