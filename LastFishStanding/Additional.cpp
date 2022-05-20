#include "Additional.h"

bool IsTextHovered(sf::Text object, sf::RenderWindow& _window)
{
	sf::IntRect temp(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
	if (temp.contains(sf::Mouse::getPosition(_window)))
	{
		return true;
	}
	return false;
}

bool IsSpriteHovered(sf::Sprite object, sf::RenderWindow& _window)
{
	sf::IntRect temp(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
	if (temp.contains(sf::Mouse::getPosition(_window)))
	{
		return true;
	}
	return false;
}
bool IsTextClicked(sf::Text object, sf::Mouse::Button button, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		sf::IntRect temp(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
		if (temp.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
	}
	return false;
}
bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		sf::IntRect temp(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
		if (temp.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
	}
	return false;
}
