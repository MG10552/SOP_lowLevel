OBJS=program5 program6
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
	

    
		