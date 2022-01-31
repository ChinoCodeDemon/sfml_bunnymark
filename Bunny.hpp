#include<random>
#include<SFML/Graphics.hpp>

class Bunny : public sf::Drawable{
private:
    static sf::Texture bunnyTexture;
    float gravity = 0.75;
    float speedX, speedY; // 0 to 10, 5 to -5
    sf::Vector2f position;
    sf::Sprite bunnySprite;
    
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        target.draw(this->bunnySprite);
    }

public:
    static void setTexture(const std::string& path){
        Bunny::bunnyTexture.loadFromFile(path);
        Bunny::bunnyTexture.setSmooth(false);
    }
    Bunny(const sf::Vector2f& pos);

    void update(const sf::Vector2f& bounding);
};