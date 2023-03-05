OBJS=program1a program1b program1c program3 program4
CC=gcc
CFLAGS=-std=c99
;CFLAGS=-Wall

all: $(OBJS)

$(OBJS): %:%.c
	$(CC) $(CFLAGS) $(LFLAGS) $< -o $@
clean:
	rm -f $(OBJS)
get: 
	mkdir -p ~/SOP2013/LAB4/source
	cp ~aadolph/SOP2013/LAB4/program*.c ~/SOP2013/LAB4/source	
	

    
		