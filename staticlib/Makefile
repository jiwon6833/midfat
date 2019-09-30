CC=clang
METAPAGETABLEDIR=../metapagetable
INCLUDES=-I. -I$(METAPAGETABLEDIR)
CFLAGS=-target riscv64-unknown-linux-gnu -c -Werror -Wall -flto -fPIC -std=gnu11 -mriscv=RV64IMAFD -nostdinc  -isystem /home/jsshin/projects/riscv/all_tools_linux/riscv/lib/gcc/riscv64-unknown-linux-gnu/5.3.0/include -isystem /home/jsshin/projects/riscv/all_tools_linux/riscv/lib/gcc/riscv64-unknown-linux-gnu/5.3.0/include-fixed -isystem /home/jsshin/projects/riscv/all_tools_linux/riscv/riscv64-unknown-linux-gnu/include -isystem /home/jsshin/projects/riscv/all_tools_linux/riscv/sysroot/usr/include
OBJDIR=./obj

CFLAGS += -O3

EXE=$(OBJDIR)/libmetadata.a

SRCS    := $(wildcard *.c)
OBJS    := $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))
DEPS    := $(OBJS:.o=.d)

ifdef MIDFAT_POINTERS
	CFLAGS += -DMIDFAT_POINTERS
endif

ifdef METALLOC_STATISTICS
	CFLAGS += -DMETALLOC_STATISTICS
endif

all: directories $(EXE) $(EXE2)

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)
	rm -f $(EXE)

$(EXE): $(OBJS) directories
	llvm-ar crv $@ $(OBJS)
	llvm-ranlib $@

-include $(DEPS)

$(OBJDIR)/%.o: %.c directories
	$(CC) $(INCLUDES) $(CFLAGS) -MMD -o $@ $<

directories:
	mkdir -p $(OBJDIR)

