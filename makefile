CC = gcc
CFLAGS = -Wall -g 
TARGET = dt
.SUFFIXES = .c .o .h
OBJ = traverse.o
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

traverse.o: traverse.c traverse.h
	$(CC) -c $(CFLAGS) traverse.c

clean:
	/bin/rm -f  $(OBJ) $(TARGET)
