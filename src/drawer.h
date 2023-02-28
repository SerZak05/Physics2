#pragma once
#include <SDL.h>

#include <string>
#include <map>
#include <vector>
#include "geomtypedefs.h"
#include "ltexture.h"



class Drawer {
public:
	const int SCREEN_WIDTH = 1280, SCREEN_HEIGHT = 720;
	bool init();

	bool loadMedia();

	bool setColor(int r, int g, int b, int a = 255);
	bool drawPoint(const Vector&);
	bool drawPoint(int x, int y);
	bool drawLine(int x1, int y1, int x2, int y2);
	bool drawLine(const Vector&, const Vector&);
	bool drawLines(const std::vector<Vector>&);
	bool drawRect(const Vector& leftUpperCorner, const Vector& rightLowerCorner);
	bool drawRect(const SDL_Rect*);
	bool drawRect(const Rect&);
	bool drawEllipse(const Vector&, const Vector&);
	bool drawEllipse(const Rect&);
	bool drawCircle(const Vector& center, double radius);

	bool loadTexture(const std::string& path);
	bool drawTexture(const std::string& name, double x, double y);
	bool drawTexture(const std::string& name, SDL_Rect* textureRect, SDL_Rect* renderRect);

	void render();

	void cleanup();

private:
	std::string mediaFolder = "assets/";

	SDL_Window* mWindow = NULL;
	SDL_Renderer* mRenderer = NULL;
	std::map<std::string, LTexture*> mTextures;

	struct Color {
		int r, g, b, a;
		Color() : r(0), g(0), b(0), a(0) {}
		Color(int r, int g, int b, int a = 255) : r(r), g(g), b(b), a(a) {}
	} mColor, bg;
};