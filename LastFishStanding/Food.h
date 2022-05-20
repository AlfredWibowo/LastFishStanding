#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
class Food 
{
public:
	void Initialize(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::RenderWindow& _window);
	void Update(float deltaTime, sf::RenderWindow& _window);
	void Draw(sf::RenderWindow& _window);
	bool getIsRemove();
	sf::Sprite GetSprite();
private:
	sf::Sprite body;
	sf::Vector2i _direction;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	bool isremove;
};

