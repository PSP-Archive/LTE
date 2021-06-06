PSPPATH := $(shell psp-config --psp-prefix)

install:
	mkdir -p $(PSPPATH)/include $(PSPPATH)/lib
	mkdir -p $(PSPPATH)/include/GL $(PSPPATH)/include/GLES
	cp include/GL/*.h $(PSPPATH)/include/GL/
	cp include/*.h $(PSPPATH)/include/
	cp include/GLES/*.h $(PSPPATH)/include/GLES/
	cp lib/*.a $(PSPPATH)/lib/