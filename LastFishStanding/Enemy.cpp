#include "Enemy.h"

Enemy::Enemy(int small, int medium, int large, int shark)
{
	int temp = rand() % 10 + 1;
	if (temp <= small)
		_type = 1;
	else if (temp <= small + medium)
		_type = 2;
	else if (temp <= small + medium + large)
		_type = 3;
	else
		_type = 4;
	isremove = false;
}

Enemy::~Enemy()
{
}

int Enemy::GetType()
{
	return _type;
}


void Enemy::Initialize(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::RenderWindow& _window)
{
	animation.setAnimation(texture, imageCount, switchTime);
	this->speed = speed;
	row = 0;
	faceRight = true;

	switch (_type)
	{
	case 1:
		body.setScale(0.2, 0.2);
		break;
	case 2:
		body.setScale(0.3, 0.3);
		break;
	case 3:
		body.setScale(0.5, 0.5);
		break;
	case 4:
		body.setScale(0.55, 0.55);
		break;
	}
	body.setTexture(*texture);
	body.setTextureRect(animation.uvRect);
	int tempx, tempy;
	switch (_type)
	{
	case 1:
		tempx = _window.getSize().x - (body.getGlobalBounds().width);
		tempy = _window.getSize().y - (body.getGlobalBounds().height);
		break;
	case 2:
		tempx = _window.getSize().x - (body.getGlobalBounds().width);
		tempy = _window.getSize().y - (body.getGlobalBounds().height);
		break;
	case 3:
		tempx = _window.getSize().x - (body.getGlobalBounds().width);
		tempy = _window.getSize().y - (body.getGlobalBounds().height);
		break;
	case 4:
		tempx = _window.getSize().x - (body.getGlobalBounds().width);
		tempy = _window.getSize().y - (body.getGlobalBounds().height);
		break;
	}
	int pos = rand() % 4 + 1;
	switch (pos)
	{
	case 1:
		body.setPosition(rand() % tempx, 0);
		break;
	case 2:
		body.setPosition(rand() % tempx, tempy);
		break;
	case 3:
		body.setPosition(0, rand() % tempy);
		break;
	case 4:
		body.setPosition(tempx, rand() % tempy);
		break;
	}
	do {
		_direction.x = rand() % 3 - 1;
		_direction.y = rand() % 3 - 1;
	} while (_direction.x == 0 && _direction.y == 0);
	x = static_cast<float> (rand() / static_cast<float> (RAND_MAX)) + 0.3;
	y = static_cast<float> (rand() / static_cast<float> (RAND_MAX)) + 0.3;
	_time = rand() % 5 + 5;
	_clock.restart();
	_remove.restart();
}

void Enemy::Update(float deltaTime, sf::RenderWindow& _window)
{
	sf::Vector2f movement(0.0f, 0.0f);
	
	movement.x = (speed * deltaTime) * _direction.x * x;
	movement.y = (speed * deltaTime) * _direction.y * y;
	
	row = 0;
	if (movement.x >= 0.0f)
		faceRight = true;
	else
		faceRight = false;

	if (body.getPosition().x + movement.x <= 0 || body.getPosition().x + body.getGlobalBounds().width + movement.x >= _window.getSize().x)
	{
		movement.x *= -1;
		_direction.x *= -1;
		if (_remove.getElapsedTime().asSeconds() > Fish_Time)
		{
			movement.x = 0;
			_direction.x = 0;
			isremove = true;
		}
	}
	if (body.getPosition().y + movement.y <= 0 || body.getPosition().y + body.getGlobalBounds().height + movement.y >= _window.getSize().y)
	{
		movement.y *= -1;
		_direction.y *= -1;
		if (_remove.getElapsedTime().asSeconds() > Fish_Time)
		{
			movement.y = 0;
			_direction.y = 0;
			isremove = true;
		}
	}
	if (body.getPosition().x + body.getGlobalBounds().width > _window.getSize().x)
	{
		body.setPosition(_window.getSize().x - body.getGlobalBounds().width, body.getPosition().y);
	}
	if (body.getPosition().y + body.getGlobalBounds().height > _window.getSize().y)
	{
		body.setPosition(body.getPosition().x, _window.getSize().y - body.getGlobalBounds().height);
	}
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement.x, movement.y);
	if (_clock.getElapsedTime().asSeconds() >= _time)
	{
		do {
			_direction.x = rand() % 3 - 1;
			_direction.y = rand() % 3 - 1;
		} while (_direction.x == 0 && _direction.y == 0);
		x = static_cast<float> (rand() / static_cast<float> (RAND_MAX)) + 0.3;
		y = static_cast<float> (rand() / static_cast<float> (RAND_MAX)) + 0.3;
		_clock.restart();
	}
}

void Enemy::Draw(sf::RenderWindow& _window)
{
	_window.draw(body);
}

sf::Sprite Enemy::GetSprite()
{
	return body;
}

bool Enemy::getIsRemove()
{
	return isremove;
}


