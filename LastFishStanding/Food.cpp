#include "Food.h"

void Food::Initialize(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::RenderWindow& _window)
{
	animation.setAnimation(texture, imageCount, switchTime);
	this->speed = speed;
	row = 0;
	faceRight = true;
	body.setTexture(*texture);
	body.setScale(0.3, 0.3);
	int tempx = _window.getSize().x - (body.getGlobalBounds().width / 3);
	body.setPosition(rand() % tempx, 0);
	_direction.x = 0;
	_direction.y = 1;
	isremove = false;
}

void Food::Update(float deltaTime, sf::RenderWindow& _window)
{
	sf::Vector2f movement(0.0f, 0.0f);

	movement.x = (speed * deltaTime) * _direction.x;
	movement.y = (speed * deltaTime) * _direction.y;
	row = 0;
	if (body.getPosition().y + body.getGlobalBounds().height + movement.y >= _window.getSize().y)
	{
		isremove = true;
	}
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement.x, movement.y);
}

void Food::Draw(sf::RenderWindow& _window)
{
	_window.draw(body);
}

bool Food::getIsRemove()
{
	return isremove;
}

sf::Sprite Food::GetSprite()
{
	return body;
}
