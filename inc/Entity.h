
#pragma once
#include <SFML/Graphics.hpp>

class Entity {
public:
	sf::Vector2f pos;
	sf::Vector2f vel;
	int health = 100;

	void move();
};