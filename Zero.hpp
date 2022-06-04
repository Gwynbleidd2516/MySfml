#ifndef ZERO_HPP
#define ZERO_HPP

#include <SFML/Graphics.hpp>
#include<iostream>

class Zero {

private:
	sf::CircleShape mZero;
public:
	void setLocation(int x, int y) {
		mZero.setPosition(x, y);
		mZero.setRadius(90.f);
		mZero.setFillColor(sf::Color::Black);
		mZero.setOutlineThickness(10);
		mZero.setOutlineColor(sf::Color::White);
	}

	void zeroRender(sf::RenderWindow& wn) {
		wn.draw(mZero);
	}

	void setWin(bool win) {
		if (win == true) {
			mZero.setOutlineColor(sf::Color::Red);
		}
	}
};
#endif // !ZERO_HPP