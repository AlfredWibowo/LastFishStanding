#include "TutorialState.h"
#include<iostream>

TutorialState::TutorialState()
{
}

TutorialState::~TutorialState()
{
}

void TutorialState::Init(sf::RenderWindow& _window)
{
	if (!_music.openFromFile(Main_Menu_Music_Filepath))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_music.setLoop(true);
	_music.play();
	if (!_texture1.loadFromFile(page_1_Tutorial_Filepath))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_page1.setTexture(_texture1);
	_page1.setScale(_window.getSize().x / _page1.getGlobalBounds().width, _window.getSize().y / _page1.getGlobalBounds().height);
	if (!_texture2.loadFromFile(page_2_Tutorial_Filepath))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_page2.setTexture(_texture2);
	_page2.setScale(_window.getSize().x / _page2.getGlobalBounds().width, _window.getSize().y / _page2.getGlobalBounds().height);
	if (!_font.loadFromFile(Main_Menu_Font_Filepath))
	{
		std::cout << "Failed to Open Font" << std::endl;
	}
	_next.setFont(_font);
	_next.setString("Next");
	_next.setCharacterSize(45);
	_next.setFillColor(sf::Color(255, 255, 255, 255));
	_next.setOutlineThickness(5);
	_next.setOutlineColor(sf::Color::Black);
	_next.setPosition(_window.getSize().x - 1.5 * _next.getGlobalBounds().width , _window.getSize().y - 1.5 * _next.getGlobalBounds().height);

	_prev.setFont(_font);
	_prev.setString("Prev");
	_prev.setCharacterSize(45);
	_prev.setFillColor(sf::Color(255, 255, 255, 255));
	_prev.setOutlineThickness(5);
	_prev.setOutlineColor(sf::Color::Black);
	_prev.setPosition(_window.getSize().x - 1.5 * _next.getGlobalBounds().width - 1.5 * _prev.getGlobalBounds().width, _window.getSize().y - 1.5 * _prev.getGlobalBounds().height);

	_back.setFont(_font);
	_back.setString("Menu");
	_back.setCharacterSize(45);
	_back.setFillColor(sf::Color(255, 255, 255, 255));
	_back.setOutlineThickness(5);
	_back.setOutlineColor(sf::Color::Black);
	_back.setPosition(0.5 * _prev.getGlobalBounds().width, _window.getSize().y - 1.5 * _prev.getGlobalBounds().height);

	page = 1;
}

void TutorialState::Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state)
{
	while (_window.pollEvent(_event))
	{
		if (_event.type == _event.Closed)
		{
			_window.close();
		}
		if (IsTextHovered(_next, _window))
		{
			_next.setFillColor(sf::Color(255, 255, 255, 150));
		}
		else
		{
			_next.setFillColor(sf::Color(255, 255, 255, 255));
		}
		if (IsTextHovered(_prev, _window))
		{
			_prev.setFillColor(sf::Color(255, 255, 255, 150));
		}
		else
		{
			_prev.setFillColor(sf::Color(255, 255, 255, 255));
		}
		if (IsTextHovered(_back, _window))
		{
			_back.setFillColor(sf::Color(255, 255, 255, 150));
		}
		else
		{
			_back.setFillColor(sf::Color(255, 255, 255, 255));
		}
		if (IsTextClicked(_next, sf::Mouse::Left, _window) && page == 1 && _clock.getElapsedTime().asSeconds() >= 0.1f)
		{
			page = 2;
			_clock.restart();
		}
		if (IsTextClicked(_prev, sf::Mouse::Left, _window) && page == 2 && _clock.getElapsedTime().asSeconds() >= 0.1f)
		{
			page = 1;
			_clock.restart();
		}
		if (IsTextClicked(_back, sf::Mouse::Left, _window))
		{
			_music.stop();
			_state.push_back(new MainMenuState);
			_state.back()->Init(_window);
		}
	}
}

void TutorialState::Update(sf::RenderWindow& _window, std::vector<State*>& _state)
{

}

void TutorialState::Draw(sf::RenderWindow& _window)
{
	_window.clear();
	switch (page)
	{
	case 1:
		_window.draw(_page1);
		_window.draw(_next);
		break;
	case 2:
		_window.draw(_page2);
		_window.draw(_prev);
		break;
	}
	_window.draw(_back);
	_window.display();
}
