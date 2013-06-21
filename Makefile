CC = g++
RM = rm -f

SRCS = $(shell ls *.cpp)
DEPS = $(SRCS:.cpp=.dep)
OBJS = $(SRCS:.cpp=.o)
PROGRAM = product
CFLAGS = -lm -Wall -g -O2

.PHONY: all clean

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.dep:%.c
	$(SHELL) -c '$(CC) -MM $< > $@'
	-include $(DEPS)

%.o:%.cpp
	$(CC) -c -O2 -o $@ $<

clean: 
	$(RM) $(OBJS) $(DEPS) $(PROGRAM)

