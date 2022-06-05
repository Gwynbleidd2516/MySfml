#include <SFML/Graphics.hpp>
#include<iostream>
#include"cross.hpp"
#include"Zero.hpp"
#include<vector>
#include<ctime>
using namespace sf;
using namespace std;

int main()
{

	RenderWindow window(sf::VideoMode(610, 610), "Tic-tac-toe", Style::Close);
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

	bool xWin = false;
	bool oWin = false;

	while (window.isOpen())
	{
		bool h = false;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{

				if (event.mouseButton.button == sf::Mouse::Left && xWin==false && oWin==false)
				{

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

					else if (sf::Mouse::getPosition(window).x > cordVertical1.x and sf::Mouse::getPosition(window).x < cordVertical2.x and sf::Mouse::getPosition(window).y > cordGorizonatl1.y and sf::Mouse::getPosition(window).y < cordGorizonatl2.y)
					{
						if (cell[1][1] == 0) {
							X[4].setLocation(210, 210);
							cell[1][1] = 1;
						}
						else {
							break;
						}
					}

					else if (sf::Mouse::getPosition(window).x > cordVertical1.x and sf::Mouse::getPosition(window).x < cordVertical2.x and sf::Mouse::getPosition(window).y > cordGorizonatl2.y)
					{
						if (cell[2][1] == 0) {
							X[5].setLocation(210, 420);
							cell[2][1] = 1;
						}
						else {
							break;
						}
					}

					else if (sf::Mouse::getPosition(window).x > cordVertical2.x and sf::Mouse::getPosition(window).y < cordGorizonatl1.y)
					{
						if (cell[0][2] == 0) {
							X[6].setLocation(420, 10);
							cell[0][2] = 1;
						}
						else {
							break;
						}
					}

					else if (sf::Mouse::getPosition(window).x > cordVertical2.x and sf::Mouse::getPosition(window).y < cordVertical2.x and sf::Mouse::getPosition(window).y > cordGorizonatl1.y)
					{
						if (cell[1][2] == 0) {
							X[7].setLocation(420, 210);
							cell[1][2] = 1;
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

					for (int i = 0; i < 3; i++) {
						if (cell[0][i] == 1 && cell[1][i] == 1 && cell[2][i] == 1) {
							X[i].setWin(true);
							X[i + 1].setWin(true);
							X[i + 2].setWin(true);
							xWin = true;
							break;
						}
						if (cell[i][0] == 1 && cell[i][1] == 1 && cell[i][2] == 1) {
							X[i].setWin(true);
							X[i + 3].setWin(true);
							X[i + 6].setWin(true);
							xWin = true;
							break;
						}
					}

					if (cell[0][0] == 1 && cell[1][1] == 1 && cell[2][2] == 1) {
						X[0].setWin(true);
						X[4].setWin(true);
						X[8].setWin(true);
						xWin = true;
					}
					if (cell[0][2] == 1 && cell[1][1] == 1 && cell[2][0] == 1) 
					{ 
						X[6].setWin(true);
						X[4].setWin(true);
						X[2].setWin(true);
						xWin = true;
					}
					
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
					while (h == false) {
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
						if (randTreker < 1) break;
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
*/
				
					for (int i = 0; i < 3; i++) {
						/////
						if (cell[1][1] == 1) {
							if (cell[0][0] == 0) {
								cell[0][0] = 2;
								if (crossCount == 9) {
									crossCount = 0;
								}
								O[crossCount].setLocation(cord[0][0].x, cord[0][0].y);
								crossCount++;
								break;
							}
							else if (cell[2][0] == 0) {
								cell[2][0] = 2;
								if (crossCount == 9) {
									crossCount = 0;
								}
								O[crossCount].setLocation(cord[2][0].x, cord[2][0].y);
								crossCount++;
								break;
							}
							else if (cell[0][2] == 0) {
								cell[0][2] = 2;
								if (crossCount == 9) {
									crossCount = 0;
								}
								O[crossCount].setLocation(cord[0][2].x, cord[0][2].y);
								crossCount++;
								break;
							}
							else if (cell[2][2] == 0) {
								cell[2][2] = 2;
								if (crossCount == 9) {
									crossCount = 0;
								}
								O[crossCount].setLocation(cord[2][2].x, cord[2][2].y);
								crossCount++;
								break;
							}
						}
						//////

						if (cell[0][i] == 1) {
							if (cell[1][i] == 0) {
								cell[1][i] = 2;
								if (crossCount == 9) {
									crossCount = 0;
								}
								O[crossCount].setLocation(cord[1][i].x, cord[1][i].y);
								crossCount++;
								break;
							}
							else if (cell[2][i] == 0) {
								cell[2][i] = 2;
								if (crossCount == 9) {
									crossCount = 0;
								}
								O[crossCount].setLocation(cord[2][i].x, cord[2][i].y);
								crossCount++;
								break;
							}
						}
						if (cell[i][0] == 1) {
							if (cell[i][1] == 0) {
								cell[i][1] = 2;
								if (crossCount == 9) {
									crossCount = 0;
								}
								O[crossCount].setLocation(cord[i][1].x, cord[i][1].y);
								crossCount++;
								break;
							}
							else if (cell[i][2] == 0) {
								cell[i][2] = 2;
								if (crossCount == 9) {
									crossCount = 0;
								}
								O[crossCount].setLocation(cord[i][2].x, cord[i][2].y);
								crossCount++;
								break;
							}
						}

						if (cell[2][i] == 1) {
							if (cell[1][i] == 0) {
								cell[1][i] = 2;
								if (crossCount == 9) {
									crossCount = 0;
								}
								O[crossCount].setLocation(cord[1][i].x, cord[1][i].y);
								crossCount++;
								break;
							}
							else if (cell[0][i] == 0) {
								cell[0][i] = 2;
								if (crossCount == 9) {
									crossCount = 0;
								}
								O[crossCount].setLocation(cord[0][i].x, cord[0][i].y);
								crossCount++;
								break;
							}
						}
						if (cell[i][2] == 1) {
							if (cell[i][0] == 0) {
								cell[i][0] = 2;
								if (crossCount == 9) {
									crossCount = 0;
								}
								O[crossCount].setLocation(cord[i][0].x, cord[i][0].y);
								crossCount++;
								break;
							}
							else if (cell[i][1] == 0) {
								cell[i][1] = 2;
								if (crossCount == 9) {
									crossCount = 0;
								}
								O[crossCount].setLocation(cord[i][1].x, cord[i][1].y);
								crossCount++;
								break;
							}
						}
					}
					
					for (int i = 0; i < 3; i++) {
						if (cell[0][i] == 2 && cell[1][i] == 2 && cell[2][i] == 2) {
							O[i].setWin(true);
							O[i + 1].setWin(true);
							O[i + 2].setWin(true);
							oWin = true;
							break;
						}
						if (cell[i][0] == 2 && cell[i][1] == 2 && cell[i][2] == 2) {
							O[i].setWin(true);
							O[i + 3].setWin(true);
							O[i + 6].setWin(true);
							oWin = true;
							break;
						}
					}

					if (cell[0][0] == 2 && cell[1][1] == 2 && cell[2][2] == 2) {
						O[0].setWin(true);
						O[4].setWin(true);
						O[8].setWin(true);
						oWin = true;
					}
					if (cell[0][2] == 2 && cell[1][1] == 2 && cell[2][0] == 2)
					{
						O[6].setWin(true);
						O[4].setWin(true);
						O[2].setWin(true);
						oWin = true;
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