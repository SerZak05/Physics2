#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <vector>
#include "geomtypedefs.h"
#include "ltexture.h"



class Drawer {
public:
	const int SCREEN_WIDTH = 1280, SCREEN_HEIGHT = 720;
	Drawer();
	bool init();

	bool loadMedia();

	void setColor(int r, int g, int b, int a = 255);
	void drawPoint(const Vector&);
	void drawPoint(int x, int y);
	void drawLine(int x1, int y1, int x2, int y2);
	void drawLine(const Vector&, const Vector&);
	void drawLines(const std::vector<Vector>&);
	void drawRect(const Vector& leftUpperCorner, const Vector& rightLowerCorner);
	// bool drawRect(const SDL_Rect*);
	void drawRect(const Rect&);
	void drawEllipse(const Vector&, const Vector&);
	void drawEllipse(const Rect&);
	void drawCircle(const Vector& center, double radius);

	bool loadTexture(const std::string& path);
	bool drawTexture(const std::string& name, double x, double y);
	// bool drawTexture(const std::string& name, SDL_Rect* textureRect, SDL_Rect* renderRect);

	void render();

	void cleanup();

private:
	std::string mediaFolder = "assets/";
	// std::map<std::string, LTexture*> mTextures;

	/*struct Color {
		int r, g, b, a;
		Color() : r(0), g(0), b(0), a(0) {}
		Color(int r, int g, int b, int a = 255) : r(r), g(g), b(b), a(a) {}
	} mColor, bg;*/
	sf::Color mColor, bg;

	sf::Vector2f convert(const Vector&) const;
};