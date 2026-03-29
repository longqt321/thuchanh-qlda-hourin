CC := g++

WARN := -Wall -Werror
INTERNAL_CFLAGS := $(WARN) -MMD
override CFLAGS += $(INTERNAL_CFLAGS)

SRC_FILES := $(wildcard *.cxx)
OBJ_FILES := $(SRC_FILES:.cxx=.o)

all: main

main: $(OBJ_FILES)
	$(CC) $^ $(CFLAGS) $(LIBS) -o $@

%.o: %.cxx
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	rm -f *.o *.d

-include $(OBJ_FILES:.o=.d)

.PHONY: clean all

