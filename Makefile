# See LICENSE file for copyright and license details.

include config.mk

all: mupaint

mupaint: window.o

.c.o: config.mk
	@echo CC -c $<
	@${CC} -c $< ${CFLAGS}

mupaint tint3_path:
	@echo CC -o $@
	@${CC} -o $@ $+ ${LDFLAGS}

clean:
	@echo cleaning
	@rm -f tint3 *.o

install: tint3
	cp tint3 /usr/bin/tint3

uninstall:
	rm -f /usr/bin/tint3

update: clean tint3
