CC = gcc
LDLIBS =
CFLAGS = -fPIC

SDIR = src
ODIR = obj

OBJ = $(patsubst $(SDIR)/%.c,$(ODIR)/%.o,$(wildcard $(SDIR)/*.c))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LDLIBS)

build: $(OBJ)
	$(CC) -shared -o libretro_drakari.dylib $^ $(CFLAGS) $(LDLIBS)

clean:
	rm $(ODIR)/*.o

.PHONY: build clean
