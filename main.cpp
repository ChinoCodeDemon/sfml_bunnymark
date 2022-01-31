#include<iostream>
#include<string>
#include<vector>
#include"Bunny.hpp"
#include"RandomGen.hpp"

// You could change these
#define AMOUNT_OF_BUNNIES 0
#define BUNNIES_TO_ADD 100
#define RESOLUTION 1280, 720

sf::Font font;

int main(int argc, char** args){
    sf::RenderWindow rw(sf::VideoMode(RESOLUTION), "Bunny Mark SFML", sf::Style::Default);
    
    sf::View v(sf::FloatRect{0, 0, RESOLUTION});
    rw.setView(v);

    sf::Vector2f vsize = v.getSize();

    Bunny::setTexture("rabbitv3.png");
    font.loadFromFile("Roboto-Regular.ttf");

    
    std::vector<Bunny*> bunnies;
    for(int i = 0; i < AMOUNT_OF_BUNNIES; i++){
        bunnies.push_back(new Bunny(sf::Vector2f(RandomGen::generate(0, 1280), RandomGen::generate(0, 200))));
    }

    
    sf::Text fpsText("00", font);
    fpsText.setCharacterSize(30);
    fpsText.setStyle(sf::Text::Style::Regular);
    fpsText.setFillColor(sf::Color::Red);
    fpsText.setOutlineColor(sf::Color::White);
    fpsText.setOutlineThickness(1);

    sf::Text countText(std::to_string(bunnies.size()), font);
    countText.setCharacterSize(30);
    countText.setStyle(sf::Text::Style::Regular);
    countText.setFillColor(sf::Color::Red);
    countText.setOutlineColor(sf::Color::White);
    countText.setOutlineThickness(1);
    countText.setPosition(sf::Vector2f(0, 40));

    sf::Clock clock;
    float lastTime = 0;
    sf::Event event;
    while(rw.isOpen()){
        while(rw.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                rw.close();
            }
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
            int x = sf::Mouse::getPosition(rw).x;
            for(int i = 0; i < BUNNIES_TO_ADD; i++){
                bunnies.push_back(new Bunny(sf::Vector2f(RandomGen::generate(-10, 10) + x, RandomGen::generate(0, 200))));
            }
        }

        rw.clear();

        for(Bunny* b : bunnies){
            b->update(vsize);
            rw.draw(*b);
        }

        rw.draw(fpsText);
        rw.draw(countText);
        
        rw.display();

        float fps = 1.f / clock.restart().asSeconds();
        fpsText.setString(std::to_string((int)(fps * 100) * 0.01));
        countText.setString(std::to_string(bunnies.size()));
    }
    return 0;
}