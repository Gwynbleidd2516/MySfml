#include <SFML/Graphics.hpp>
#include<iostream>
#include<math.h>
#include"cross.hpp"
#include"Zero.hpp"
#include<vector>


int main()
{
    sf::RenderWindow window(sf::VideoMode(620, 620), "SFML works!");
    sf::RectangleShape vertical1;
    sf::RectangleShape vertical2;
    sf::RectangleShape gorizontal1;
    sf::RectangleShape gorizontal2;

    std::vector<Cross> X(9);
    std::vector<Zero> O(9);

    std::vector<std::vector<int>> cell(3, std::vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int r = 0; r < 3; r++) {
            cell[i][r];
        }
    }

    sf::Vector2i cordVertical1(200, 0);
    sf::Vector2i cordVertical2(400, 0);
    sf::Vector2i cordGorizonatl1(0, 200);
    sf::Vector2i cordGorizonatl2(0, 400);

    bool click = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (sf::Mouse::getPosition(window).x < cordVertical1.x and sf::Mouse::getPosition(window).y < cordGorizonatl1.y)
                    {
                        if (cell[0][0] == 0) {
                            O[0].setLocation(10, 10);
                            cell[0][0] = 1;
                        }
                    }

                    if (sf::Mouse::getPosition(window).x < cordVertical1.x and sf::Mouse::getPosition(window).y > cordGorizonatl1.y and sf::Mouse::getPosition(window).y < cordGorizonatl2.y)
                    {
                        if (cell[1][0] == 0) {
                            O[1].setLocation(10, 210);
                            cell[1][0] = 1;
                        }
                    }

                    if (sf::Mouse::getPosition(window).x < cordVertical1.x and sf::Mouse::getPosition(window).y > cordGorizonatl2.y)
                    {
                        if (cell[2][0] == 0) {
                            O[2].setLocation(10, 420);
                            cell[2][0] = 1;
                        }
                    }

                    if (sf::Mouse::getPosition(window).x > cordVertical1.x and sf::Mouse::getPosition(window).x < cordVertical2.x and sf::Mouse::getPosition(window).y < cordGorizonatl1.y)
                    {
                        if (cell[0][1] == 0) {
                            O[3].setLocation(210, 10);
                            cell[0][1] = 1;
                        }
                    }

                    if (sf::Mouse::getPosition(window).x > cordVertical2.x and sf::Mouse::getPosition(window).y < cordGorizonatl1.y)
                    {
                        if (cell[0][2] == 0) {
                            O[4].setLocation(420, 10);
                            cell[0][2] = 1;
                        }
                    }

                    if (sf::Mouse::getPosition(window).x > cordVertical1.x and sf::Mouse::getPosition(window).x < cordVertical2.x and sf::Mouse::getPosition(window).y > cordGorizonatl1.y and sf::Mouse::getPosition(window).y < cordGorizonatl2.y)
                    {
                        if (cell[1][1] == 0) {
                            O[5].setLocation(210, 210);
                            cell[1][1] = 1;
                        }
                    }

                    if (sf::Mouse::getPosition(window).x > cordVertical2.x and sf::Mouse::getPosition(window).y < cordVertical2.x and sf::Mouse::getPosition(window).y > cordGorizonatl1.y)
                    {
                        if (cell[1][2] == 0) {
                            O[6].setLocation(420, 210);
                            cell[1][2] = 1;
                        }
                    }

                    if (sf::Mouse::getPosition(window).x > cordVertical1.x and sf::Mouse::getPosition(window).x < cordVertical2.x and sf::Mouse::getPosition(window).y > cordGorizonatl2.y)
                    {
                        if (cell[2][1] == 0) {
                            O[7].setLocation(210, 420);
                            cell[2][1] = 1;
                        }
                    }
                }
            }

        }

        vertical1.setPosition(200, 0);
        vertical1.setSize(sf::Vector2f(10, 620));
        vertical2.setPosition(400, 0);
        vertical2.setSize(sf::Vector2f(10, 620));

        gorizontal1.setPosition(0, 200);
        gorizontal1.setSize(sf::Vector2f(620, 10));
        gorizontal2.setPosition(0, 400);
        gorizontal2.setSize(sf::Vector2f(620, 10));



        window.clear();
        window.draw(vertical1);
        window.draw(vertical2);
        window.draw(gorizontal1);
        window.draw(gorizontal2);
        O[0].zeroRender(window);
        O[1].zeroRender(window);
        O[2].zeroRender(window);
        O[3].zeroRender(window);
        O[4].zeroRender(window);
        O[5].zeroRender(window);
        O[6].zeroRender(window);
        O[7].zeroRender(window);
        window.display();
    }

    return 0;
}