# Makefile for Lr-Hammerfest


# default stuff goes here, so that config can override
TARGET ?= lr-hammerfest
CFLAGS += -Wall -ggdb -Iinclude -ffast-math
ifndef DEBUG
CFLAGS += -O2 -DNDEBUG
endif
CXXFLAGS += $(CFLAGS)
#DRC_DBG = 1
#PCNT = 1


all: target_


CC_LINK ?= $(CC)
CC_AS ?= $(CC)
LDFLAGS += $(MAIN_LDFLAGS)
EXTRA_LDFLAGS ?= -Wl,-Map=$@.map
LDLIBS += $(MAIN_LDLIBS)
ifdef PCNT
CFLAGS += -DPCNT
endif


#OBJECT TO COMPILE
OBJS += src/libretro/libretro.o
OBJS += src/hammerfest/Hammerfest.o
OBJS += src/hammerfest/MyWrapper.o




#COMPILATION
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CFLAGS) -c -o $@ $<


target_: $(TARGET)


#LINK
$(TARGET): $(OBJS)	
	$(CXX) -o $@ $^ $(LDFLAGS) $(LDLIBS) $(LIBS) $(EXTRA_LDFLAGS)


#CLEAN
clean: $(PLAT_CLEAN) 
	$(RM) $(TARGET) $(OBJS) $(TARGET).map