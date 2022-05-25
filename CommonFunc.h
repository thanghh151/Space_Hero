#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include<iostream>
#include<windows.h>
#include<string>
#include<SDL_image.h>
#include<SDL.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;
static SDL_Renderer* g_renderer = NULL;
static SDL_Surface* g_bullet_img = NULL;
static SDL_Texture* g_bullet_tex = NULL;
static SDL_Surface* g_life_img = NULL;
static SDL_Texture* g_life_tex = NULL;
static SDL_Surface* g_player = NULL;
static SDL_Texture* g_player_tex = NULL;
static SDL_Surface* g_threat = NULL;
static SDL_Texture* g_threat_tex = NULL;
static SDL_Surface* g_background = NULL;
static SDL_Texture* g_background_tex = NULL;
static SDL_Surface* g_load = NULL;
static SDL_Texture* g_load_tex = NULL;
static SDL_Surface* g_gameover_img = NULL;
static SDL_Texture* g_gameover_tex = NULL;

const int NUM_LIVES = 3;

//Screen
const int SCREEN_WIDTH = 1300;
const int SCREEN_HEIGHT = 750;
const int SCREEN_BPP = 32;
const int SPEED = 350;
const int FPS = 60;
const int NUM_BULLETS = 20;
const int BULLET_DELAY = 1000;


using namespace std;
#endif
