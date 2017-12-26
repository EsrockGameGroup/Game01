#pragma once
#include <SFML/Graphics.hpp>

class Entity {
public:
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f spd = sf::Vector2f(2.5f, 2.5f);
	sf::Vector2f selfSize = sf::Vector2f(20, 20);
	sf::Vector2f hitPos;
	sf::RectangleShape hitBox = sf::RectangleShape(selfSize);
	sf::RectangleShape velBox;
	sf::Rect<float> selfBox, newPosBox;
	sf::Rect<float> blocker;
	int health = 100;

	sf::Vector2f precise(sf::Vector2f newPos, sf::Vector2f oldPos, sf::Vector2f vel, sf::Rect<float> self, sf::Rect<float> target);
	sf::Vector2f inputs(sf::Vector2f vel);
	sf::Vector2f move(sf::Vector2f pos, sf::Vector2f vel);
	sf::RectangleShape getSelf();
	sf::RectangleShape getHit();
	void moveVelBox();
	void moveBasic();
	void setBlocker(sf::Rect<float> in);
	Entity(sf::Vector2f position);
};
