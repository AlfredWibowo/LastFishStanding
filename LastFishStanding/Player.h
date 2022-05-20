#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include"Enemy.h"
#include "Food.h"

class Player
{
public:
	Player(sf::Texture texture, sf::Vector2u imageCount, float switchTime);
	Player();
	~Player();

	void Initialize(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::RenderWindow& _window);
	void Update(float deltaTime, sf::RenderWindow& _window);
	void Draw(sf::RenderWindow &window);
	void setAnimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	bool IsColliding(Enemy _enemy);
	bool IsColliding(Food* _enemy);
	int GetSize();
	sf::Sprite getSprite();
	void AddSize(sf::RenderWindow& _window);
	void AddScore(int x = 1);
	int getScore();

private:
	sf::Sprite body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	int _score, _size;
};