#include "drawer.h"
#include <iostream>
#include "merrors.h"
#include "appcontroller.h"

Drawer::Drawer() {}

bool Drawer::init()
{
	bool success = true;
	// list string , list task errors
	bg.a = 255;
	return success;
}

bool Drawer::loadMedia() {
	bool success = true;

	return success;
}

/*bool Drawer::loadTexture(const std::string& name) {
	bool success = true;
	if (mTextures.find(name) == mTextures.end()) {
		LTexture* newTexture = new LTexture();
		if (!newTexture->loadFromFile(mediaFolder + name, mRenderer)) {
			// errors.add(...)
			mErrorLog::stream << "Failed to load image: " << name << std::endl;
			success = false; //= errors.isNotEmpty()
		}
		else {
			mTextures[name] = newTexture;
		}
	}
	return success;
}*/

void Drawer::setColor(int r, int g, int b, int a) {
	mColor = sf::Color(r, g, b, a);
}

void Drawer::drawPoint(const Vector& v) {
	drawPoint(v.x(), v.y());
}

void Drawer::drawPoint(int x, int y) {
	sf::RenderWindow& mWindow = AppController::getInstance()->window;

	sf::Vertex point(sf::Vector2f(10, 10), mColor);
	mWindow.draw(&point, 1, sf::Points);
}

void Drawer::drawLine(int x1, int y1, int x2, int y2) {
	sf::RenderWindow& mWindow = AppController::getInstance()->window;

	sf::Vertex line[] = {
		sf::Vertex(sf::Vector2f(x1, y1)),
		sf::Vertex(sf::Vector2f(x2, y2))
	};
	mWindow.draw(line, 2, sf::Lines);
}

void Drawer::drawLine(const Vector& a, const Vector& b) {
	drawLine(a.x(), a.y(), b.x(), b.y());
}

void Drawer::drawLines(const std::vector<Vector>& v) {
	sf::RenderWindow& mWindow = AppController::getInstance()->window;

	sf::VertexArray verticies(sf::Lines, v.size());
	for (int i = 0; i < v.size(); ++i) {
		verticies[i] = sf::Vertex(convert(v[i]));
	}

	mWindow.draw(verticies);
}

void Drawer::drawRect(const Vector& a, const Vector& b) {
	sf::RenderWindow& mWindow = AppController::getInstance()->window;

	sf::RectangleShape rect(
		sf::Vector2f(b.x() - a.x(), b.y() - a.y())
	);

	rect.setFillColor(mColor);
	rect.setPosition(convert(a));

	mWindow.draw(rect);
}

void Drawer::drawRect(const Rect& rect) {
	drawRect(rect.first, rect.second);
}

/*bool Drawer::drawEllipse(const Vector& a, const Vector& b) {
	Vector center = (a + b) * 0.5;
	return false;
}*/

void Drawer::drawCircle(const Vector& center, double radius) {
	sf::RenderWindow& mWindow = AppController::getInstance()->window;

	sf::CircleShape circle(radius);
	circle.setFillColor(mColor);
	circle.setPosition(convert(center));

	mWindow.draw(circle);
}

/*bool Drawer::drawTexture(const std::string& name, double x, double y) {
	bool success = true;
	if (mTextures.find(name) == mTextures.end()) {
		//errors.add(...)
		mErrorLog::stream << "Did not find texture: " << name << std::endl;
	}
	else {
		mTextures[name]->render(mRenderer, int(x), int(y));
	}
	return success;
}*/

void Drawer::render() {
	sf::RenderWindow& mWindow = AppController::getInstance()->window;

	mWindow.display();

	mWindow.clear(bg);
}

void Drawer::cleanup() {
	
}

sf::Vector2f Drawer::convert(const Vector& v) const {
	return sf::Vector2f(v.x(), v.y());
}
