#pragma once
#include<SFML/Graphics.hpp>
#include<cstdlib>
#include<iostream>
#include "Animation.h"
#include "Definition.h"
class Enemy
{
public:
	Enemy(int small = 4, int medium = 3, int large = 2, int shark = 1);
	~Enemy();
	int GetType();
	void Initialize(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::RenderWindow& _window);
	void Update(float deltaTime, sf::RenderWindow& _window);
	void Draw(sf::RenderWindow& _window);
	sf::Sprite GetSprite();
	bool getIsRemove();

private:
	sf::Sprite body;
	sf::Vector2i _direction;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	sf::Clock _clock, _remove;
	float _time;
	float x, y;
	int _type;
	bool isremove;
};

