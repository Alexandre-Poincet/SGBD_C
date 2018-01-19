C=gcc
CFLAGS=-Wall -g
LDFLAGS=
EXEC=sgbd

.PHONY: clean, mrproper

SRCDIR=src
INCDIR=inc
OBJDIR=obj
BINDIR=bin

SRC=$(wildcard src/*.c)
OBJ=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

all: $(EXEC)

run: $(EXEC)
	./$(BINDIR)/$(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $(BINDIR)/$@ $^ $(CLFLAGS) $(LDFLAGS)


$(OBJDIR)/main.o: $(INCDIR)/func.h
$(OBJDIR)/func.o: $(INCDIR)/func.h


$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)
	
clean:
	rm -f $(OBJDIR)/*.o

mrproper: clean
	rm -f $(BINDIR)/$(EXEC)
