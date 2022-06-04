#ifndef CROSS_HPP
#define CROSS_HPP

#include <SFML/Graphics.hpp>
#include<iostream>
#include<math.h>

class Cross {
private:
	sf::RectangleShape mCross1;
	sf::RectangleShape mCross2;

public:
	void setLocation(float x, float y) {
		mCross1.setPosition(x, y);
		mCross1.setRotation(-45.f);
		mCross1.setSize(sf::Vector2f(10, 180 * sqrt(2)));

		mCross2.setPosition(x + 180, y);
		mCross2.setRotation(45.f);
		mCross2.setSize(sf::Vector2f(10, 180 * sqrt(2)));

	}

	void crossRender(sf::RenderWindow& wn) {
		wn.draw(mCross1);
		wn.draw(mCross2);
	}

	void setWin(bool win) {
		if (win == true) {
			mCross1.setFillColor(sf::Color::Green);
			mCross2.setFillColor(sf::Color::Green);
		}
	}
};

#endif // !Cross_HPP