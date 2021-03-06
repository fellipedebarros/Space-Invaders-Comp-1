lall: jogo.o escudo.o alien.o wave.o missil.o tanque.o buffer.o menu.o botao.o sound.o space.c
	g++ space.c jogo.o escudo.o alien.o wave.o missil.o tanque.o buffer.o menu.o botao.o sound.o -o space -lallegro -lallegro_dialog -lallegro_image -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_audio -lallegro_acodec
alien.o: alien.c alien.h
	g++ -c alien.c
botao.o: botao.c botao.h
	g++ -c botao.c
buffer.o: buffer.c buffer.h
	g++ -c buffer.c
escudo.o: escudo.c escudo.h
	g++ -c escudo.c
jogo.o: jogo.c jogo.h
	g++ -c jogo.c
menu.o: menu.c menu.h
	g++ -c menu.c 
missil.o: missil.c missil.h
	g++ -c missil.c
tanque.o: tanque.c tanque.h
	g++ -c tanque.c
wave.o: wave.c wave.h
	g++ -c wave.c
sound.o:sound.c sound.h
	g++ -c sound.c
clean:
	rm -f jogo.o escudo.o alien.o missil.o tanque.o vetor.o buffer.o botao.o menu.o wave.o sound.o
git:
	git add --all
	git commit
	git push
