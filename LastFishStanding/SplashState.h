#pragma once
#include<SFML/Graphics.hpp>
#include "Definition.h"
#include "Additional.h"
#include "State.h"
#include "MainMenuState.h"
class SplashState : public State
{
public:
	SplashState();
	~SplashState();

	void Init(sf::RenderWindow& _window);
	void Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state);
	void Update(sf::RenderWindow& _window, std::vector<State*>& _state);
	void Draw(sf::RenderWindow& _window);
private:
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Clock _clock;
};

