C = gcc
CFLAGS = -Wall -Werror -g -pedantic
OUPUT = ./dl
EXEOBJ = ./main.o
LIBOBJ = ./doubly-list.o
LIBDL = ./libdl.a
HEADERS = ./*.h
default: $(OUTPUT)
all: default

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDL): $(LIBOBJ)
	ar rc $(LIBDL) $(LIBOBJ)

$(OUTPUT): $(EXEOBJ) $(LIBDL)
	$(CC) $(CFLAGS) $(EXEOBJ) $(LIBDL) doubly-list.h -o $@

clean:
	rm -f *.o $(OUTPUT)
	rm -f $(LIBDL)
