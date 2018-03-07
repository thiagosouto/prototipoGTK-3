all:radio

radio:botao
	g++ radiobutton.c -o radiobutton `pkg-config --cflags --libs gtk+-3.0`
botao:box
	g++ botao.c -o botao `pkg-config --cflags --libs gtk+-3.0`
box:check
	g++ box.c -o box `pkg-config --cflags --libs gtk+-3.0`
check:cunvas
	g++ checkbutton.c -o checkbutton `pkg-config --cflags --libs gtk+-3.0`
cunvas:entry
	g++ cunvas.c -o cunvas `pkg-config --cflags --libs gtk+-3.0`
entry:grid
	g++ entry.c -o entry `pkg-config --cflags --libs gtk+-3.0`
grid:label
	g++ grid.c -o grid `pkg-config --cflags --libs gtk+-3.0`
label:link
	g++ label.c -o label `pkg-config --cflags --libs gtk+-3.0`
link:lock
	g++ link.c -o link `pkg-config --cflags --libs gtk+-3.0`
lock:scale
	g++ lockbutton.c -o lockbutton `pkg-config --cflags --libs gtk+-3.0`
scale:scrollbar
	g++ scale.c -o scale `pkg-config --cflags --libs gtk+-3.0`
scrollbar:spin
	g++ scrollbar.c -o scrollbar `pkg-config --cflags --libs gtk+-3.0`
spin:toggle
	g++ spin.c -o spin `pkg-config --cflags --libs gtk+-3.0`
toggle:volume
	g++ togglebutton.c -o togglebutton `pkg-config --cflags --libs gtk+-3.0`
volume:switc
	g++ volume.c -o volume `pkg-config --cflags --libs gtk+-3.0`
switc:limpar
	g++ switch.c -o switch `pkg-config --cflags --libs gtk+-3.0`
limpar:
	clear||cls
clean:
	rm -f tp *.o radiobutton switch botao box checkbutton cunvas togglebutton entry grid label link lockbutton scale scrollbar spin volume
