#ifndef JOGO_H
#define JOGO_H

#include <allegro5/allegro.h>

#include "escudo.h"
#include "tanque.h"
#include "missil.h"
#include "buffer.h"

#define FPS 60
#define N_KEYS 3
#define N_ESCUDOS 4

enum MYKEYS {
   KEY_LEFT, KEY_RIGHT, KEY_SPACE
};

enum GAME_STATE {
	MENU_INICIAL, PLAY, MENU_PAUSA, GAME_OVER
};

struct Jogo{
	bool sair, redraw;

	int largura, altura;
	int vidas;

	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_TIMER* timer;
	GAME_STATE estado_do_jogo;
	bool key[N_KEYS];
	
	Buffer* buffer;
	Escudo* escudo[4];
	Tanque* tanque;
};

void inicializa_jogo(Jogo* jogo, int largura, int altura);

void destroi_jogo(Jogo* jogo);

void main_loop_jogo(Jogo* jogo);

#endif