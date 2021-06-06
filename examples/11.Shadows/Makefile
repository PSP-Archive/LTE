TARGET = Shadows
OBJS = main.o 

INCDIR =
CFLAGS = -G0  -O2
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
LDFLAGS =
LIBS= -lengine -lpspwlan -lglut -lGLU -lGL -lpspvfpu -lm -lstdc++ -lpsppower -lpsprtc -lpspaudio

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = LTE GE Example - Shadows

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak