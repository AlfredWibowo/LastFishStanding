#include "MainMenuState.h"
#include<iostream>

MainMenuState::MainMenuState()
{
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::Init(sf::RenderWindow& _window)
{
	if (!_music.openFromFile(Main_Menu_Music_Filepath))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_music.setLoop(true);
	_music.play();
	if (!_texture.loadFromFile(Main_Menu_State_BG_Filepath))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_bg.setTexture(_texture);
	_bg.setScale(_window.getSize().x / _bg.getGlobalBounds().width, _window.getSize().y / _bg.getGlobalBounds().height);
	if (!_font.loadFromFile(Main_Menu_Font_Filepath))
	{
		std::cout << "Failed to Open Font" << std::endl;
	}
	_title.setFont(_font);
	_title.setString("Last Fish Standing");
	_title.setCharacterSize(75);
	_title.setFillColor(sf::Color(255, 255, 255, 255));
	_title.setOutlineThickness(5);
	_title.setOutlineColor(sf::Color::Black);
	_title.setPosition((_window.getSize().x / 2) - (_title.getGlobalBounds().width / 2), (_title.getGlobalBounds().height));

	_play.setFont(_font);
	_play.setString("Play");
	_play.setCharacterSize(75);
	_play.setFillColor(sf::Color(255, 255, 255, 255));
	_play.setOutlineThickness(5);
	_play.setOutlineColor(sf::Color::Black);
	_play.setPosition((_window.getSize().x / 2) - (_play.getGlobalBounds().width / 2), (_play.getGlobalBounds().height / 2) + (2.5 * (_title.getGlobalBounds().height)));

	_tutorial.setFont(_font);
	_tutorial.setString("Tutorial");
	_tutorial.setCharacterSize(75);
	_tutorial.setFillColor(sf::Color(255, 255, 255, 255));
	_tutorial.setOutlineThickness(5);
	_tutorial.setOutlineColor(sf::Color::Black);
	_tutorial.setPosition((_window.getSize().x / 2) - (_tutorial.getGlobalBounds().width / 2), (_tutorial.getGlobalBounds().height / 2) + (4 * (_title.getGlobalBounds().height)));

	_exit.setFont(_font);
	_exit.setString("Exit");
	_exit.setCharacterSize(75);
	_exit.setFillColor(sf::Color(255, 255, 255, 255));
	_exit.setOutlineThickness(5);
	_exit.setOutlineColor(sf::Color::Black);
	_exit.setPosition((_window.getSize().x / 2) - (_exit.getGlobalBounds().width / 2), _window.getSize().y - (3.5 * _exit.getGlobalBounds().height));
}

void MainMenuState::Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state)
{
	while (_window.pollEvent(_event))
	{
		if (_event.type == _event.Closed)
		{
			_window.close();
		}
		if (IsTextHovered(_play, _window))
		{
			_play.setFillColor(sf::Color(255, 255, 255, 150));
		}
		else
		{
			_play.setFillColor(sf::Color(255, 255, 255, 255));
		}
		if (IsTextHovered(_tutorial, _window))
		{
			_tutorial.setFillColor(sf::Color(255, 255, 255, 150));
		}
		else
		{
			_tutorial.setFillColor(sf::Color(255, 255, 255, 255));
		}
		if (IsTextHovered(_exit, _window))
		{
			_exit.setFillColor(sf::Color(255, 255, 255, 150));
		}
		else
		{
			_exit.setFillColor(sf::Color(255, 255, 255, 255));
		}
		if (IsTextClicked(_play, sf::Mouse::Left, _window))
		{
			_music.stop();
			_state.push_back(new GameState);
			_state.back()->Init(_window);
		}
		if (IsTextClicked(_tutorial, sf::Mouse::Left, _window))
		{
			_music.stop();
			_state.push_back(new TutorialState);
			_state.back()->Init(_window);
		}
		if (IsTextClicked(_exit, sf::Mouse::Left, _window))
		{
			_window.close();
		}
	}
}

void MainMenuState::Update(sf::RenderWindow& _window, std::vector<State*>& _state)
{

}

void MainMenuState::Draw(sf::RenderWindow& _window)
{
	_window.clear();
	_window.draw(_bg);
	_window.draw(_title);
	_window.draw(_play);
	_window.draw(_tutorial);
	_window.draw(_exit);
	_window.display();
}
