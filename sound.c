#include "sound.h"
#include <stdio.h>

SOUND_MANAGER* inicializa_sound_manager(){

	SOUND_MANAGER* sound = (SOUND_MANAGER*) malloc(sizeof(SOUND_MANAGER));

	sound->mudo = false;
	sound->volume = 1.0;
	
	sound->sample[SHOOT] = al_load_sample("sons/shoot.wav");
	sound->sample[TANQUE_EXPLOSION] = al_load_sample("sons/explosion.wav");
	sound->sample[ALIEN_MOVE_1] = al_load_sample("sons/fastinvader1.wav");
	sound->sample[ALIEN_MOVE_2] = al_load_sample("sons/fastinvader2.wav");
	sound->sample[ALIEN_MOVE_3] = al_load_sample("sons/fastinvader3.wav");
	sound->sample[ALIEN_MOVE_4] = al_load_sample("sons/fastinvader4.wav");
	sound->sample[ALIEN_EXPLOSION] = al_load_sample("sons/invaderkilled.wav");
	sound->sample[UFO_HIGHPITCH] = al_load_sample("sons/ufo_highpitch.wav");
	sound->sample[UFO_LOWPITCH] = al_load_sample("sons/ufo_highpitch.wav");
	for(int i = 0; i < N_SAMPLES; i++)
		if(!sound->sample[i]){
			printf("%s %d %s\n", "Falha ao carregar sample: ", i, ".\n");
			exit(1);
		}

	return sound;
}

void toggle_sound_state(void* ptr){
	SOUND_MANAGER* sound = (SOUND_MANAGER*) ptr;
	sound->mudo = !sound->mudo;
}

void rise_sound_volume(void* ptr){
	SOUND_MANAGER* sound = (SOUND_MANAGER*) ptr;
	sound->volume += .1;
}

void low_sound_volume(void* ptr){
	SOUND_MANAGER* sound = (SOUND_MANAGER*) ptr;
	sound->volume -= .1;
}

void play_sound(SOUND_MANAGER *sound, SAMPLES type, ALLEGRO_PLAYMODE playmode){
	if(!sound->mudo)
		al_play_sample(sound->sample[type], sound->volume, 0.0, 1.0, playmode, NULL);
}

SOUND_MANAGER* finaliza_sound_manager(SOUND_MANAGER* sound){
	for(int i = 0; i < N_SAMPLES; i++)
		al_destroy_sample(sound->sample[i]);
	free(sound);
	sound = NULL;
	return sound;
}
