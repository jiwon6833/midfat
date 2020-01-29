PAGESIZE:= $(shell getconf PAGESIZE)
CC=libtool --tag=CC --mode=compile gcc -prefer-pic
LINKER=libtool --tag=CC --mode=link gcc
INCLUDES=-I. -I../gperftools-metalloc/src/ -I$(OBJDIR)
ifeq ($(TEST),0)
CC=libtool --tag=CC --mode=compile gcc -prefer-pic
LINKER=libtool --tag=CC --mode=link gcc
CFLAGS=-fPIC -c -Werror -Wall -O0 -std=gnu11 -DSYSTEM_PAGESIZE=$(PAGESIZE) -g -fno-inline
else
CC=libtool --tag=CC --mode=compile clang -prefer-pic
LINKER=libtool --tag=CC --mode=link clang 
CFLAGS=-target riscv64-unknown-linux-gnu -fPIC -c -Werror -Wall -O0 -std=gnu11 -DSYSTEM_PAGESIZE=$(PAGESIZE) -g -fno-inline -mriscv=RV64IMAFD -nostdinc -isystem /home/jwseo/workspace/MTE/riscv/lowrisc-chip/riscv/lib/gcc/riscv-linux/4.6.1/include -isystem /home/jwseo/workspace/MTE/riscv/lowrisc-chip/riscv/lib/gcc/riscv-linux/4.6.1/include-fixed -isystem /home/jwseo/workspace/MTE/riscv/lowrisc-chip/riscv/riscv-linux/include -isystem /home/jwseo/workspace/MTE/riscv/lowrisc-chip/sysroot/usr/include -DRISCV
endif
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


