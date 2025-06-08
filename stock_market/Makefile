CC = gcc
CFLAGS = -Wall -ansi -pedantic-errors
TARGET = stock_market
SRCS = main.c stock_market.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c stock_market.h
stock_market.o: stock_market.c stock_market.h

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
