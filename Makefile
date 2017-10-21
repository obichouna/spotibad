SRC := linked_list.c spotibad.c test.c
OBJ := $(SRC:.c=.o)

all: spotibad

$(OBJ): Makefile linked_list.h

spotibad: $(OBJ)
	@echo "[LD] $@"
	@$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	@echo "[CC] $@"
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f spotibad $(OBJ)

run: spotibad
	./spotibad
