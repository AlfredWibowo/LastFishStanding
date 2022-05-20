#include "GameOverState.h"

GameOverState::GameOverState(int score)
{
	this->score = score;
	highscore = 0;
}

GameOverState::~GameOverState()
{
}

void GameOverState::Init(sf::RenderWindow& _window)
{
	if(!_texture.loadFromFile(Main_Menu_State_BG_Filepath))
	{
		std::cout << "Failed To Load File" << std::endl;
	}
	_bg.setTexture(_texture);
	_bg.setScale(_window.getSize().x / _bg.getGlobalBounds().width, _window.getSize().y / _bg.getGlobalBounds().height);
	if (!_music.openFromFile(Game_Over_Music_Filepath))
	{
		std::cout << "Failed To Load File" << std::endl;
	}
	_music.setLoop(true);
	_music.play();
	if (!_font.loadFromFile(Main_Menu_Font_Filepath))
	{
		std::cout << "Failed To Load File" << std::endl;
	}
	_title.setFont(_font);
	_title.setString("Game Over");
	_title.setCharacterSize(75);
	_title.setFillColor(sf::Color(255, 255, 255, 255));
	_title.setOutlineThickness(5);
	_title.setOutlineColor(sf::Color::Black);
	_title.setPosition((_window.getSize().x / 2) - (_title.getGlobalBounds().width / 2), (_title.getGlobalBounds().height));

	std::string temp = "Score : " + std::to_string(score);
	_score.setFont(_font);
	_score.setString(temp);
	_score.setCharacterSize(75);
	_score.setFillColor(sf::Color(255, 255, 255, 255));
	_score.setOutlineThickness(5);
	_score.setOutlineColor(sf::Color::Black);
	_score.setPosition((_window.getSize().x / 2) - (_score.getGlobalBounds().width / 2), 3 * (_score.getGlobalBounds().height));

	_back.setFont(_font);
	_back.setString("Main Menu");
	_back.setCharacterSize(75);
	_back.setFillColor(sf::Color(255, 255, 255, 255));
	_back.setOutlineThickness(5);
	_back.setOutlineColor(sf::Color::Black);
	_back.setPosition((_window.getSize().x / 2) - (_back.getGlobalBounds().width / 2), 4.25 * (_back.getGlobalBounds().height));

	_exit.setFont(_font);
	_exit.setString("Exit");
	_exit.setCharacterSize(75);
	_exit.setFillColor(sf::Color(255, 255, 255, 255));
	_exit.setOutlineThickness(5);
	_exit.setOutlineColor(sf::Color::Black);
	_exit.setPosition((_window.getSize().x / 2) - (_exit.getGlobalBounds().width / 2), 6 * (_exit.getGlobalBounds().height));

	highscore_file.open("highscore.bin", std::ios::in | std::ios::binary);
	if (highscore_file.is_open())
	{
		highscore_file.read((char*)& highscore, sizeof(highscore));
		highscore_file.close();
	}
	if (score >= highscore)
	{
		highscore = score;
	}
	highscore_file.open("highscore.bin", std::ios::out | std::ios::binary);
	if (highscore_file.is_open())
	{
		highscore_file.write((char*)& highscore, sizeof(highscore));
		highscore_file.close();
	}
	std::string temp2 = "Highscore : " + std::to_string(highscore);
	_highscore.setFont(_font);
	_highscore.setString(temp2);
	_highscore.setCharacterSize(75);
	_highscore.setFillColor(sf::Color(255, 255, 255, 255));
	_highscore.setOutlineThickness(5);
	_highscore.setOutlineColor(sf::Color::Black);
	_highscore.setPosition((_window.getSize().x / 2) - (_highscore.getGlobalBounds().width / 2), 8 * (_highscore.getGlobalBounds().height));
}

void GameOverState::Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state)
{
	while (_window.pollEvent(_event))
	{
		if (_event.type == _event.Closed)
		{
			_window.close();
		}
		if (IsTextHovered(_back, _window))
		{
			_back.setFillColor(sf::Color(255, 255, 255, 150));
		}
		else
		{
			_back.setFillColor(sf::Color(255, 255, 255, 255));
		}
		if (IsTextHovered(_exit, _window))
		{
			_exit.setFillColor(sf::Color(255, 255, 255, 150));
		}
		else
		{
			_exit.setFillColor(sf::Color(255, 255, 255, 255));
		}
		if (IsTextClicked(_back, sf::Mouse::Left, _window))
		{
			_music.stop();
			_state.push_back(new MainMenuState);
			_state.back()->Init(_window);
		}
		if (IsTextClicked(_exit, sf::Mouse::Left, _window))
		{
			_window.close();
		}
	}
}

void GameOverState::Update(sf::RenderWindow& _window, std::vector<State*>& _state)
{
}

void GameOverState::Draw(sf::RenderWindow& _window)
{
	_window.clear();
	_window.draw(_bg);
	_window.draw(_title);
	_window.draw(_score);
	_window.draw(_back);
	_window.draw(_exit);
	_window.draw(_highscore);
	_window.display();
}
