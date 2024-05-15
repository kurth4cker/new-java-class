.POSIX:
include config.mk

BIN = new-java-class
OBJ = \
	main.o

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(NEW_JAVA_CLASS_LDFLAGS) -o $@ $(OBJ) $(NEW_JAVA_CLASS_LDLIBS)

clean:
	rm -f $(BIN) *.o

install:
	mkdir -p $(DESTDIR)$(BINDIR)
	cp -f $(BIN) $(DESTDIR)$(BINDIR)

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/$(BIN)

.SUFFIXES: .c .o
.c.o:
	$(CC) $(NEW_JAVA_CLASS_CFLAGS) -c $<
