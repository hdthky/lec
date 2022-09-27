SRCS = lec.c
CFLAGS = -O2 -g -static
TARGET = lec

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) -lpthread

all: $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

install:
	cp lec /usr/local/bin/
