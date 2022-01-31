#include"Bunny.hpp"
#include"RandomGen.hpp"
#include<iostream>
sf::Texture Bunny::bunnyTexture = sf::Texture();

Bunny::Bunny(const sf::Vector2f& pos){
    this->bunnySprite.setTexture(Bunny::bunnyTexture);
    sf::Vector2u vecSize = Bunny::bunnyTexture.getSize();
    this->bunnySprite.setOrigin(vecSize.x * 0.5, vecSize.y * 0.5);
    this->bunnySprite.setPosition(pos);
    this->position = pos;
    this->speedX = (RandomGen::generate(0, 1000) * 0.01) - 5;
    this->speedY = (RandomGen::generate(0, 1000) * 0.01);
}

void Bunny::update(const sf::Vector2f& bounding){
    this->position.x += this->speedX;
    this->position.y += this->speedY;
    this->speedY += this->gravity;

    if(this->position.x < 0){
        this->speedX *= -1;
        this->position.x = 0;
    }
    
    if(this->position.x > bounding.x){
        this->speedX *= -1;
        this->position.x = bounding.x;
    }

    if(this->position.y < 0){
        this->speedY = 0;
        this->position.y = 0;
    }

    if(this->position.y > bounding.y){
        this->speedY *= -0.95;
        this->position.y = bounding.y;
    }
    this->bunnySprite.setPosition(this->position);
}