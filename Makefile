CC = clang++
RM = rm -f

SRCS = $(shell ls *.cpp)
DEPS = $(SRCS:.cpp=.dep)
OBJS = $(SRCS:.cpp=.o)
PROGRAM = product
CFLAGS = -Wall -g -O2 -std=c++0x
LDFLAGS = -lstdc++ -lm

.PHONY: all clean

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.dep:%.c
	$(SHELL) -c '$(CC) -MM $< > $@'
	-include $(DEPS)

%.o:%.cpp
	$(CC) -c -O2 -o $@ $< $(CFLAGS)

clean: 
	$(RM) $(OBJS) $(DEPS) $(PROGRAM)

