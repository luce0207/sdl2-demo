// SDL2 Demo by aurelien.esnard@u-bordeaux.fr

#include "model.h"
#include <SDL.h>
#include <SDL_image.h>  // required to load transparent texture from PNG
#include <SDL_ttf.h>    // required to use TTF fonts
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* **************************************************************** */

#define FONT "res/arial.ttf"
#define FONTSIZE 36
#define BACKGROUND "res/background.png"

/* **************************************************************** */

struct Env_t {
  /* PUT YOUR VARIABLES HERE */
  SDL_Texture *background;
  SDL_Texture *square;
};

/* **************************************************************** */

Env *init(SDL_Window *win, SDL_Renderer *ren, int argc, char *argv[]) {
  Env *env = malloc(sizeof(struct Env_t));

  /* PUT YOUR CODE HERE TO INIT TEXTURES, ... */
  PRINT("This is a test to see how to print\n");

  int w, h;
  SDL_GetWindowSize(win, &w, &h);

  env->background = IMG_LoadTexture(ren, BACKGROUND);
  if (!env->background) ERROR("IMG_LoadTexture: %s\n", BACKGROUND);

  return env;
}

/* **************************************************************** */

void render(SDL_Window *win, SDL_Renderer *ren, Env *env) {
  /* PUT YOUR CODE HERE TO RENDER TEXTURES, ... */
  int w, h;
  SDL_GetWindowSize(win, &w, &h);
  h = 1000;
  w = 1000;

  SDL_RenderCopy(ren, env->background, NULL, NULL);

  SDL_SetRenderDrawColor(ren, 80, 80, 80, SDL_ALPHA_OPAQUE);
  for (int i = 1; i < 10; i++) {
    SDL_RenderDrawLine(ren, 100, 100 * i, w - 100, 100 * i);
  }
  for (int i = 1; i < 10; i++) {
    SDL_RenderDrawLine(ren, 100 * i, 100, 100 * i, h - 100);
  }
}

/* **************************************************************** */

bool process(SDL_Window *win, SDL_Renderer *ren, Env *env, SDL_Event *e) {
  if (e->type == SDL_QUIT) {
    return true;
  }

  /* PUT YOUR CODE HERE TO PROCESS EVENTS */
  return false;
}

/* **************************************************************** */

void clean(SDL_Window *win, SDL_Renderer *ren, Env *env) {
  /* PUT YOUR CODE HERE TO CLEAN MEMORY */
  SDL_DestroyTexture(env->background);

  free(env);
}

/* **************************************************************** */
