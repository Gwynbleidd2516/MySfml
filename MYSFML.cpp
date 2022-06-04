#include <SFML/Graphics.hpp>
#include<iostream>
#include<math.h>
#include"cross.hpp"
#include"Zero.hpp"
#include<vector>
#include<ctime>
using namespace sf;
using namespace std;

int main()
{
	
	RenderWindow window(sf::VideoMode(610, 610), "tic-tac-toe",Style::Close);
	window.setFramerateLimit(30);

	sf::RectangleShape vertical1;
	sf::RectangleShape vertical2;
	sf::RectangleShape vertical3;
	sf::RectangleShape gorizontal1;
	sf::RectangleShape gorizontal2;

	vector<Cross> X(9);
	vector<Zero> O(9);
	int crossCount = 0;



	std::vector<std::vector<int>> cell(3, std::vector<int>(3));
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cell[y][x];
		}
	}

	std::vector<std::vector<sf::Vector2i>> cord(3, std::vector<sf::Vector2i>(3));
	int x1 = 10;
	int y1 = 10;
	for (int y = 0; y < 3; y++) {
		x1 = 10;
		for (int x = 0; x < 3; x++) {
			cord[y][x] = sf::Vector2i(x1, y1);
			x1 += 200;
		}
		y1 += 200;
	}

	sf::Vector2i cordVertical1(200, 0);
	sf::Vector2i cordVertical2(400, 0);
	sf::Vector2i cordGorizonatl1(0, 200);
	sf::Vector2i cordGorizonatl2(0, 400);

	bool click = false;
	
	while (window.isOpen())
	{
		bool h = false;
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					if (sf::Mouse::getPosition(window).x < cordVertical1.x and sf::Mouse::getPosition(window).y < cordGorizonatl1.y)
					{
						if (cell[0][0] == 0) {
							X[0].setLocation(10, 10);
							cell[0][0] = 1;
						}
						else {
							break;
						}
					}
					else if (sf::Mouse::getPosition(window).x < cordVertical1.x and sf::Mouse::getPosition(window).y > cordGorizonatl1.y and sf::Mouse::getPosition(window).y < cordGorizonatl2.y)
					{
						if (cell[1][0] == 0) {
							X[1].setLocation(10, 210);
							cell[1][0] = 1;
						}
						else {
							break;
						}
					}

					else if (sf::Mouse::getPosition(window).x < cordVertical1.x and sf::Mouse::getPosition(window).y > cordGorizonatl2.y)
					{
						if (cell[2][0] == 0) {
							X[2].setLocation(10, 420);
							cell[2][0] = 1;
						}
						else {
							break;
						}
					}

					else if (sf::Mouse::getPosition(window).x > cordVertical1.x and sf::Mouse::getPosition(window).x < cordVertical2.x and sf::Mouse::getPosition(window).y < cordGorizonatl1.y)
					{
						if (cell[0][1] == 0) {
							X[3].setLocation(210, 10);
							cell[0][1] = 1;
						}
						else {
							break;
						}
					}

					else if (sf::Mouse::getPosition(window).x > cordVertical2.x and sf::Mouse::getPosition(window).y < cordGorizonatl1.y)
					{
						if (cell[0][2] == 0) {
							X[4].setLocation(420, 10);
							cell[0][2] = 1;
						}
						else {
							break;
						}
					}

					else if (sf::Mouse::getPosition(window).x > cordVertical1.x and sf::Mouse::getPosition(window).x < cordVertical2.x and sf::Mouse::getPosition(window).y > cordGorizonatl1.y and sf::Mouse::getPosition(window).y < cordGorizonatl2.y)
					{
						if (cell[1][1] == 0) {
							X[5].setLocation(210, 210);
							cell[1][1] = 1;
						}
						else {
							break;
						}
					}

					else if (sf::Mouse::getPosition(window).x > cordVertical2.x and sf::Mouse::getPosition(window).y < cordVertical2.x and sf::Mouse::getPosition(window).y > cordGorizonatl1.y)
					{
						if (cell[1][2] == 0) {
							X[6].setLocation(420, 210);
							cell[1][2] = 1;
						}
						else {
							break;
						}
					}

					else if (sf::Mouse::getPosition(window).x > cordVertical1.x and sf::Mouse::getPosition(window).x < cordVertical2.x and sf::Mouse::getPosition(window).y > cordGorizonatl2.y)
					{
						if (cell[2][1] == 0) {
							X[7].setLocation(210, 420);
							cell[2][1] = 1;
						}
						else {
							break;
						}
					}

					else if (sf::Mouse::getPosition(window).x > cordVertical2.x and sf::Mouse::getPosition(window).y > cordGorizonatl2.y)
					{
						if (cell[2][2] == 0) {
							X[8].setLocation(420, 420);
							cell[2][2] = 1;
						}
						else {
							break;
						}
					}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

					while (h=true) {
						srand(time(0));
						int rn1 = rand() % 3;
						int rn2 = rand() % 3;
						int randCordx = rn1;
						int randCordy = rn2;
						int randTreker = 0;
						for (int y1 = 0; y1 < 3; y1++) {
							for (x1 = 0; x1 < 3; x1++) {
								if (cell[y1][x1] == 0) {
									randTreker++;
								}
								
							}
						}
						if (randTreker<1) break;
						if (cell[randCordy][randCordx] == 0) {
							cell[randCordy][randCordx] = 2;
							if (crossCount == 9) {
									crossCount = 0;
							}
							O[crossCount].setLocation(cord[randCordy][randCordx].x, cord[randCordy][randCordx].y);
							crossCount++;
							h = true;
							break;
						}
						
						
					}
					
				}
			}

		}

		vertical1.setPosition(200, 0);
		vertical1.setSize(sf::Vector2f(10, 620));
		vertical2.setPosition(400, 0);
		vertical2.setSize(sf::Vector2f(10, 620));
		vertical3.setPosition(610, 0);
		vertical3.setSize(sf::Vector2f(10, 620));


		gorizontal1.setPosition(0, 200);
		gorizontal1.setSize(sf::Vector2f(620, 10));
		gorizontal2.setPosition(0, 400);
		gorizontal2.setSize(sf::Vector2f(620, 10));

		window.clear();
		window.draw(vertical1);
		window.draw(vertical2);
		window.draw(vertical3);
		window.draw(gorizontal1);
		window.draw(gorizontal2);
		X[0].crossRender(window);
		X[1].crossRender(window);
		X[2].crossRender(window);
		X[3].crossRender(window);
		X[4].crossRender(window);
		X[5].crossRender(window);
		X[6].crossRender(window);
		X[7].crossRender(window);
		X[8].crossRender(window);
		O[0].zeroRender(window);
		O[1].zeroRender(window);
		O[2].zeroRender(window);
		O[3].zeroRender(window);
		O[4].zeroRender(window);
		O[5].zeroRender(window);
		O[6].zeroRender(window);
		O[7].zeroRender(window);
		O[8].zeroRender(window);
		window.display();
	}

	return 0;
}