rabc: rabc.c
	gcc -o rabc rabc.c -lm

DESTDIR=/usr/local/bin
install:
	cp rabc $(DESTDIR)
	cp rabc.1 /usr/share/man/man1
	bzip2 -f /usr/share/man/man1/rabc.1
