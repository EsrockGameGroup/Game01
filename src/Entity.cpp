
#include <cmath>
/*
    Probably should be done in its own class that deals with calculations used all around the game?
*/

#include "../inc/Entity.h"

/*
Added a bunch of stuff to entity,
*/

/*

    Move loop, used in main, should figure out how to do it in a way that allows for multiple entities (inherit from new Class baseObject (dealing with solids and collision detection) into entity?)

*/
void Entity::moveBasic()
{
    vel = Entity::inputs(spd);
    //creates a velocity vector from inputs
    sf::Vector2f newPos = Entity::move(pos, vel);
    //creates the possible new position
    selfBox = sf::Rect<float>(pos, selfSize);
    newPosBox= sf::Rect<float>(newPos, selfSize);
    //sets hitboxes to their positions
    pos = Entity::precise(newPos, pos, vel, newPosBox, blocker);
    //checks if a collision happens
    Entity::hitBox.setPosition(pos);
    Entity::moveVelBox();
    //moves the graphical display of the entity
}

sf::Vector2f Entity::move(sf::Vector2f pos, sf::Vector2f vel)
{
    pos += vel;
    return pos;
}

sf::Vector2f Entity::inputs(sf::Vector2f spd)
{
    sf::Vector2f vel;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        vel.x -= spd.x;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        vel.x += spd.x;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        vel.y -= spd.y;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        vel.y += spd.y;
    }
    return vel;
}

sf::RectangleShape Entity::getSelf()
{
    //gets the current position hitbox
    return Entity::hitBox;
}

sf::RectangleShape Entity::getHit()
{
    //gets the new position hitbox
    return Entity::velBox;
}

Entity::Entity(sf::Vector2f position)
{
    //creates a new entity with the position. should be extended to account for variable sizes and speeds
    pos = position;
}

void Entity::moveVelBox()
{
    Entity::hitPos = Entity::pos;
    hitPos.x += Entity::vel.x;
    hitPos.y += Entity::vel.y;
    //sets the position of the newpos hitbox
    Entity::velBox = sf::RectangleShape(selfSize);
    //creates it
    Entity::velBox.setFillColor(sf::Color(0, 100, 0, 200));
    //colors it
    Entity::velBox.setPosition(hitPos);
    //moves it
}

//collision detection
/*

stops movement if the velocity causes a collision with something.
Doesn't account for the vector elements that don't necessarily cause a collision.

*/
sf::Vector2f Entity::precise(sf::Vector2f newPos, sf::Vector2f oldPos, sf::Vector2f vel, sf::Rect<float> self, sf::Rect<float> target)
{
    sf::Vector2f outPos(oldPos);
    //gets what to output with a base value
    if(self.intersects(target))
    {
        //checks for a collision with the newPos hitbox on target
        sf::Rect<float> checkPrecise = sf::Rect<float>(oldPos, selfSize);
        //generates a hitbox utilized in making an exact collision

        //this part should be in its own class? (getMag and getNorm or something like that)
        sf::Vector2f diffVect = (newPos - oldPos);
        //gets the difference in positions for use.
        float mag = pow(diffVect.x, 2) + pow(diffVect.y, 2);
        //gets magnitude
        sf::Vector2f norm = sf::Vector2f(diffVect.x / mag, diffVect.y / mag);
        //gets normalized vector

        if(!checkPrecise.intersects(target))
        {
            //if there's no collision with the oldPos hitbox(what the precise hitbox is set as) even though there is a collision with the newPos one
            for(int i = 0; i < mag; i++)
            {
                sf::Vector2f current;
                //Check x
                //moves the output position

                current = oldPos;
                current.x = outPos.x;
                checkPrecise = sf::Rect<float>(current, selfSize);
                if(!checkPrecise.intersects(target))
                {
                    outPos.x += norm.x;
                }

                //Check y
                //moves the output position

                current = oldPos;
                current.y = outPos.y;
                checkPrecise = sf::Rect<float>(current, selfSize);
                if(!checkPrecise.intersects(target))
                {
                    outPos.y += norm.y;
                }
            }
            //undoes the change in position that caused the collision
            if(vel.x != 0)
            {
                outPos.x -= norm.x;
            }
            if(vel.y != 0)
            {
                outPos.y -= norm.y;
            }
        }
    }
    else
    {
        //skip all that and just get the new position
        outPos = newPos;
    }
    return outPos;
}

void Entity::setBlocker(sf::Rect<float> in)
{
    //set the target
    Entity::blocker = in;
}
