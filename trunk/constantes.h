/**
 * \file constantes.h
 *
 *  \author Mrah Mehdi
 *
 *  \brief Constantes utiles pour l'interface
 */

#if defined(linux) || defined(__linux) || defined(__linux__)
#include <SDL/SDL.h>
#endif
#if defined(__APPLE__)
#include <SDL/SDL.h>
#endif
#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
#include <SDL\SDL.h>
#endif


#ifndef CONSTANTES_H_
#define CONSTANTES_H_


#define LARGEUR 800
#define LONGUEUR 800
#define TAILLECARRE 80

/** Structure definissant un carre fonce */
typedef struct {
	int est_libre;
	int numero_case;
	SDL_Rect position;
	SDL_Surface *surface;
} Carre_fonce;

/** Structure definissant un carre clair */
typedef struct {
	int est_libre;
	int numero_case;
	SDL_Rect position;
	SDL_Surface *surface;
} Carre_clair;

/** Structure definissant un pion clair */
typedef struct{
	int est_dame;
	SDL_Surface *surface;
	SDL_Rect position;
} Pion_clair;

/** Structure definissant un pion fonce */
typedef struct{
	int est_dame;
	SDL_Surface *surface;
	SDL_Rect position;
} Pion_fonce;

#endif
