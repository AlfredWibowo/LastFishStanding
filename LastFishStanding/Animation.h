#pragma once
#include<SFML/Graphics.hpp>

class Animation
{
public:
	Animation(sf::Texture texture,sf::Vector2u imageCount,float switchTime);
	Animation();
	~Animation();

	void Update(int row, float deltaTime, bool FaceRight);
	void setAnimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};