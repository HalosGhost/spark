CC = clang
PROJNM = spark
CFLAGS = -std=c11 -Weverything -Wno-vla -Werror -ggdb -O0
SRCDIR = ./src
BLDDIR = ./dist

.PHONY: all clean dynamic static

all: clean dynamic

clean:
	@rm -rf -- $(BLDDIR)

$(BLDDIR):
	@mkdir -p $(BLDDIR)

dynamic: $(BLDDIR)
	$(CC) $(CFLAGS) -shared -fPIC $(SRCDIR)/$(PROJNM).c -o $(BLDDIR)/lib$(PROJNM).so
	$(CC) $(CFLAGS) -fPIE -L$(BLDDIR) -l$(PROJNM) $(SRCDIR)/main.c -o $(BLDDIR)/$(PROJNM)

static: $(BLDDIR)
	$(CC) $(CFLAGS) $(SRCDIR)/{main,$(PROJNM)}.c -o $(BLDDIR)/$(PROJNM)
