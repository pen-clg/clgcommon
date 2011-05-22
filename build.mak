TARGET ?= unnamed
INCDIR := $(INCDIR) .

ifdef PSPSDK
CC  = psp-gcc
CXX = psp-g++
AS  = psp-gcc
LD  = psp-gcc
AR  = psp-ar
INCDIR := $(INCDIR) $(PSPSDK)/include $(PSPSDK)/include/libc
endif

CFLAGS   := $(addprefix -I,$(INCDIR)) $(CFLAGS)
CXXFLAGS := $(CFLAGS) $(CXXFLAGS)
ASFLAGS  := $(CFLAGS) $(ASFLAGS)
ARFLAGS  := rv
LIBPATH  := .

ifdef PSPSDK
ifeq ($(USE_KERNEL_LIBC),1)
CFLAGS := -I$(PSPSDK)/include/libc $(CFLAGS)
else
ifeq ($(USE_PSPSDK_LIBC),1)
CFLAGS := -I$(PSPSDK)/include/libc $(CFLAGS)
endif
endif
endif

ifdef WITH_LIBS_DEBUG
	CFLAGS += -fno-builtin-printf -g -DDEBUG=1
endif

all: $(LIBPATH)/lib$(TARGET).a

$(LIBPATH)/lib$(TARGET).a: $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -rf $(LIBPATH)/lib$(TARGET).a $(OBJS)

rebuild: clean all
