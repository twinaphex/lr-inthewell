#ifndef IS_OSX
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#else
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#endif

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <map>

#ifndef __MYCLASS_SPRITE
#define __MYCLASS_SPRITE

#include "json/json.h"

class Sprite {

	public:
		static Sprite& Instance();
		Sprite();
		~Sprite();
		SDL_Surface * getAnimation(std::string name, int index);
	private:
		Sprite& operator=(const Sprite&);
		Sprite(const Sprite&);
		static Sprite m_instance;

		/***********************
		 * VARIABLES
		 ***********************/
		SDL_Surface * surfaceToParse;
		std::map<std::string, SDL_Surface **> sprites;

		/***********************
		 * FUNCTIONS
		 ***********************/
		void parseJsonFile();
		void releaseSurfaceToParse();
		void loadSurfaceToSprite(std::string name);
};
#endif
