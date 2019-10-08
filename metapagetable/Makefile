PAGESIZE:= $(shell getconf PAGESIZE)
CC=libtool --tag=CC --mode=compile riscv64-unknown-linux-gnu-gcc -prefer-pic
LINKER=libtool --tag=CC --mode=link riscv64-unknown-linux-gnu-gcc
INCLUDES=-I. -I../gperftools-metalloc/src/ -I$(OBJDIR)
CFLAGS= -fPIC -c -Werror -Wall -O3 -std=gnu99 -DSYSTEM_PAGESIZE=$(PAGESIZE) -nostdinc  -isystem /home/jsshin/projects/riscv/all_tools_linux/riscv/lib/gcc/riscv64-unknown-linux-gnu/5.3.0/include -isystem /home/jsshin/projects/riscv/all_tools_linux/riscv/lib/gcc/riscv64-unknown-linux-gnu/5.3.0/include-fixed -isystem /home/jsshin/projects/riscv/all_tools_linux/riscv/riscv64-unknown-linux-gnu/include -isystem /home/jsshin/projects/riscv/all_tools_linux/riscv/sysroot/usr/include

LDFLAGS=-static
OBJDIR=obj

EXE=$(OBJDIR)/libmetapagetable.la

SRCS    := $(wildcard *.c)
OBJS    := $(patsubst %.c,$(OBJDIR)/%.lo,$(SRCS))
DEPS    := $(OBJS:.lo=.d)

all: $(OBJDIR)/metapagetable.h $(OBJDIR)/metapagetable_core.h $(EXE)

clean:
	rm -rf $(OBJDIR)
	rm -f linker-options
	rm -f metapagetable.h

$(EXE): $(OBJS) directories
	$(LINKER) $(OBJS) $(LDFLAGS) -o $@
#ar crv $@ $(OBJS)
#ranlib $@

-include $(DEPS)

$(OBJDIR)/%.lo: %.c directories
	$(CC) $(INCLUDES) $(CFLAGS) -MT $@ -MMD -o $@ $<

$(OBJDIR)/metapagetable.h: metapagetable.h.in linker-options.in config_metapagetable.cmake directories
	rm -f metapagetable.h
	rm -f linker-options
	rm -f $(OBJDIR)/metapagetable.h
	rm -f $(OBJDIR)/linker-options
	cmake $(METALLOC_OPTIONS) -P ./config_metapagetable.cmake
	mv linker-options $(OBJDIR)
	mv metapagetable.h $(OBJDIR)

$(OBJDIR)/metapagetable_core.h: metapagetable_core.h directories
	cp metapagetable_core.h $(OBJDIR)

touch_config:
	touch metapagetable.h.in
	touch linker-options.in

config: touch_config
	$(MAKE) $(OBJDIR)/metapagetable.h

directories:
	mkdir -p $(OBJDIR)


