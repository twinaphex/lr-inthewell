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

#ifndef __MYCLASS_TEXT
#define __MYCLASS_TEXT

#include "json/json.h"
#include "GameConfig.h"

enum textColor {
	red = 0, blue = 1, green = 2, gold = 3, white = 4
};

class Text {

	public:
		static Text& Instance();
		Text();
		~Text();
		SDL_Color getSDL_Color(int color);
		void drawText(SDL_Surface* surfaceToDraw, std::string fontName, int x, int y, const char* text, int color, bool alignCenter);
		void drawTextTranslated(SDL_Surface* surfaceToDraw, std::string fontName, int x, int y, std::string key, int color, bool alignCenter);
	private:
		Text& operator=(const Text&);
		Text(const Text&);
		static Text m_instance;

		void parseJsonFile();

		/***********************
		 *        FONT
		 ***********************/
		std::map<std::string, TTF_Font *> fonts;
		std::map<std::string, std::map<std::string, std::string> > texts;
};
#endif
