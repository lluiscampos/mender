

all: code doc app

mender-dbus.c mender-dbus.h: AuthenticationManager1.xml
	gdbus-codegen --generate-c-code mender-dbus --c-namespace Mender \
		--interface-prefix com.Mender. AuthenticationManager1.xml

code: mender-dbus.c mender-dbus.h

doc/doc-com.mender.Authentication1.html doc/doc-com.mender.Authentication1.md: AuthenticationManager1.xml
	mkdir -p doc
	gdbus-codegen AuthenticationManager1.xml --generate-docbook doc --output-directory doc
	pandoc --from docbook --to html --output doc/doc-com.mender.Authentication1.html doc/doc-com.mender.Authentication1.xml
	pandoc --from docbook --to markdown --output doc/doc-com.mender.Authentication1.md doc/doc-com.mender.Authentication1.xml

doc: doc/doc-com.mender.Authentication1.html

a.out: main.c mender-dbus.c
	gcc main.c mender-dbus.c -I /usr/include/gio-unix-2.0/ $(shell pkg-config --libs --cflags gio-2.0)

app: a.out

clean:
	rm -f mender-dbus.c mender-dbus.h
	rm -rf doc
	rm -f a.out


.PHONY: all
.PHONY: code
.PHONY: doc
.PHONY: clean
