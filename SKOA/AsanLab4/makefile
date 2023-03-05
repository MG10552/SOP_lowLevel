OBJS=program1 program2 program3 program4 program5
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
	

    
		