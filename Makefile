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
OBJS += src/hammerfest/definition/Drawable.o
OBJS += src/hammerfest/definition/Position.o
OBJS += src/hammerfest/definition/HitBox.o
OBJS += src/hammerfest/level/Decor.o
OBJS += src/hammerfest/level/Door.o
OBJS += src/hammerfest/level/Lock.o
OBJS += src/hammerfest/level/Ennemie.o
OBJS += src/hammerfest/level/Event.o
OBJS += src/hammerfest/level/Platform.o
OBJS += src/hammerfest/level/Rayon.o
OBJS += src/hammerfest/level/Teleporter.o
OBJS += src/hammerfest/level/Vortex.o
OBJS += src/hammerfest/level/Level.o
OBJS += src/hammerfest/utils/LevelService.o
OBJS += src/hammerfest/game/Game.o
OBJS += src/hammerfest/game/Bombe.o
OBJS += src/hammerfest/game/Player.o
OBJS += src/hammerfest/item/Family.o
OBJS += src/hammerfest/item/Item.o
OBJS += src/hammerfest/item/ItemFileSystem.o
OBJS += src/hammerfest/item/Quest.o
OBJS += src/hammerfest/utils/GameConfig.o
OBJS += src/hammerfest/utils/Jsoncpp.o
OBJS += src/hammerfest/utils/Sound.o
OBJS += src/hammerfest/utils/Sprite.o
OBJS += src/hammerfest/utils/Text.o


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