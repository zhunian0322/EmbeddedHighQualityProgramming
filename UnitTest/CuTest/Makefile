

TARGET = stringTest
CFLAGS = -g -Wall
SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SOURCES))
LIBS = 
CC = gcc


all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

	
$(OBJS):$(SOURCES)
	$(CC) -c $(CFLAGS) $*.c -o $@ 
	
clean:
	rm -f $(OBJS)
	rm -f $(TARGET)