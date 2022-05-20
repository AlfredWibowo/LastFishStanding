#pragma once
#include<SFML/Graphics.hpp>

bool IsTextHovered(sf::Text object, sf::RenderWindow& _window);
bool IsSpriteHovered(sf::Sprite object, sf::RenderWindow& _window);
bool IsTextClicked(sf::Text object, sf::Mouse::Button button, sf::RenderWindow& window);
bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);