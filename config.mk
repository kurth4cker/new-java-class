PREFIX = /usr/local
BINDIR = $(PREFIX)/bin

CC = cc

CFLAGS = -g -pedantic -pedantic-errors -Wall -Wextra
LDFLAGS =
LDLIBS =


NEW_JAVA_CLASS_CFLAGS = $(CFLAGS)
NEW_JAVA_CLASS_LDFLAGS = $(LDFLAGS) 
NEW_JAVA_CLASS_LDLIBS = $(LDLIBS) 
