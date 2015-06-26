#ifndef TANQUE_H
#define TANQUE_H

#include <allegro5/allegro.h>
#include "missil.h"

#define PASSO 5

struct Tanque{
	int posicao_x, posicao_y, delta_x;
	ALLEGRO_BITMAP* imagem;
	Missil* missil;
	float velocidade;
};

Tanque* inicializa_tanque( int posicao_x, int posicao_y);

void desenha_tanque(Tanque* tanque);

void tanque_move_esquerda(Tanque* tanque);

void tanque_move_direita(Tanque* tanque);

void atira_tanque(Tanque* tanque);

int get_posicao_x_min_tanque (Tanque* tanque);

int get_posicao_x_max_tanque (Tanque* tanque);

void processa_tanque(Tanque* tanque);

Tanque* destroi_tanque(Tanque* tanque);

#endif