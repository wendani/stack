AM_CFLAGS := -g -Wall -O2 -std=c++11

CC        := g++
CFLAGS    := $(AM_CFLAGS)

LD        := g++

APPS      := parenthess
OBJS      := $(APPS).o
SRCS      := $(APPS).cpp

parenthess: parenthess.o
	$(LD) $(AM_CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -fr $(APPS) *.o *.out
