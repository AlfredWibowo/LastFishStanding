#include "SplashState.h"
#include<iostream>

SplashState::SplashState()
{
}

SplashState::~SplashState()
{
}

void SplashState::Init(sf::RenderWindow& _window)
{
	if (!_texture.loadFromFile(Splash_State_BG_Filepath))
	{
		std::cout << "Failed To Open File" << std::endl;
	}
	_sprite.setTexture(_texture);
	_sprite.setScale(_window.getSize().x / _sprite.getGlobalBounds().width, _window.getSize().y / _sprite.getGlobalBounds().height);
	_clock.restart();
}

void SplashState::Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state)
{
	while (_window.pollEvent(_event))
	{
		if (_event.type == _event.Closed)
		{
			_window.close();
		}		
	}
}

void SplashState::Update(sf::RenderWindow& _window, std::vector<State*>& _state)
{
	if (_clock.getElapsedTime().asSeconds() >= Splash_Time)
	{
		_state.push_back(new MainMenuState);
		_state.back()->Init(_window);
	}
}

void SplashState::Draw(sf::RenderWindow& _window)
{
	_window.clear();
	_window.draw(_sprite);
	_window.display();
}
