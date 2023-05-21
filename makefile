CC=gcc
CFLAGS=-c -Wall
LDFLAGS=                                                
SOURCES=main.c algorithm_steps.c stack_implementation.c list_implementation.c hash_implementation.c hash_list_implementation.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main.x

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
