
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

#include "../inc/Entity.h"

using namespace std;

void sleep (int x) {
	this_thread::sleep_for(std::chrono::milliseconds(x));
}

float dist (sf::Vector2f a, sf::Vector2f b) {
	return pow(pow(a.x-b.x, 2) + pow(a.y-b.y, 2), 0.5);
}

int main ()
{
	sf::Vector2i m_loc;
	bool m_down = false;
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "In the halls of the omniking");
	//creates test blocker
    sf::RectangleShape shape(sf::Vector2f(200, 200));
    //creates test entity
    Entity ent(sf::Vector2f(200, 200));

	srand(time(0));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !m_down) {
			m_down = true;
			m_loc = sf::Mouse::getPosition(window);
			//moves entity
			ent.pos = sf::Vector2f(m_loc.x, m_loc.y);
			printf("Pressed: %d, %d\n", m_loc.x, m_loc.y);
			fflush(stdout);
		}

		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			m_down = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}

		window.clear();
		//creates blocker hitbox
		sf::Rect<float> shapeRect(400, 400, 200, 200);
		//sets the hitbox
		ent.setBlocker(shapeRect);
		//move loop for entity
        ent.moveBasic();

        //sets position of blocker
		shape.setPosition(400, 400);
		//sets color of shape
		shape.setFillColor(sf::Color(100, 0, 0));
		//draws stuff
        window.draw(shape);
		window.draw(ent.getSelf());
		window.draw(ent.getHit());
		window.display();

		// Comment this out to go fast like sanic
		sleep(10);
	}

	return 0;
}
