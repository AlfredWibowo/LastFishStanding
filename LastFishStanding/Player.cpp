#include"Player.h"

Player::Player(sf::Texture texture, sf::Vector2u imageCount, float switchTime):animation(texture,imageCount,switchTime)
{

}
Player::Player()
{
}
Player::~Player()
{

}
void Player::Initialize(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::RenderWindow& _window)
{
	_score = 0;
	animation.setAnimation(texture, imageCount, switchTime);
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setScale(0.2, 0.2);
	body.setTexture(*texture);
	body.setPosition(_window.getSize().x/2 - (body.getGlobalBounds().width / 2), _window.getSize().y/2 - (body.getGlobalBounds().height / 2));
	_score = 0;
	_size = 1;
}
void Player::Update(float deltaTime, sf::RenderWindow& _window)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		movement.x -= speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		movement.x += speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		movement.y -= speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		movement.y += speed * deltaTime;
	}

	if (body.getPosition().x + movement.x <= 0 || body.getPosition().x + body.getGlobalBounds().width + movement.x >= _window.getSize().x)
	{
		movement.x = 0;
	}
	if (body.getPosition().y + movement.y <= 0 || body.getPosition().y + body.getGlobalBounds().height + movement.y >= _window.getSize().y)
	{
		movement.y = 0;
	}

	row = 0;
	if (movement.x >= 0.0f)
		faceRight = true;
	else
		faceRight = false;

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::setAnimation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	animation.setAnimation(texture, imageCount, switchTime);
}

bool Player::IsColliding(Enemy _enemy)
{
	if (body.getGlobalBounds().intersects(_enemy.GetSprite().getGlobalBounds()))
		return true;

	return false;
}

bool Player::IsColliding(Food* _enemy)
{
	if (body.getGlobalBounds().intersects(_enemy->GetSprite().getGlobalBounds()))
		return true;

	return false;
}

int Player::GetSize()
{
	return _size;
}

sf::Sprite Player::getSprite()
{
	return body;
}

void Player::AddSize(sf::RenderWindow& _window)
{
	if (_size < 3)
		_size++;
	switch (_size)
	{
	case 1:
		body.setScale(0.2, 0.2);
		break;
	case 2:
		body.setScale(0.3, 0.3);
		break;
	default:
		body.setScale(0.4, 0.4);
		break;
	}
	if (body.getPosition().x + body.getGlobalBounds().width > _window.getSize().x)
	{
		body.setPosition(_window.getSize().x - body.getGlobalBounds().width, body.getPosition().y);
	}
	if (body.getPosition().y + body.getGlobalBounds().height > _window.getSize().y)
	{
		body.setPosition(body.getPosition().x, _window.getSize().y - body.getGlobalBounds().height);
	}
}

void Player::AddScore(int x)
{
	_score += x;
}

int Player::getScore()
{
	return _score;
}
