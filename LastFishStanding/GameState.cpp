#include "GameState.h"
#include "MainMenuState.h"
#include<iostream>

GameState::GameState()
{
}

GameState::~GameState()
{
	if (isfoodexist)
		delete _food;
}

void GameState::Init(sf::RenderWindow& _window)
{
	_window.setMouseCursorVisible(false);
	start = true;
	if (!_bitebuffer.loadFromFile(Bite_Sound_Filepath))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_bite.setBuffer(_bitebuffer);
	if (!_music.openFromFile(Game_State_Music_Filepath))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_music.setLoop(true);
	_music.play();
	if (!_texture.loadFromFile(Game_Menu_State_BG_Filepath))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_bg.setTexture(_texture);
	_bg.setScale(_window.getSize().x / _bg.getGlobalBounds().width, _window.getSize().y / _bg.getGlobalBounds().height);

	if (!_pausetexture.loadFromFile(Pause_Screen_Filepath))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_pause.setTexture(_pausetexture);
	_pause.setScale(_window.getSize().x / _pause.getGlobalBounds().width, _window.getSize().y / _pause.getGlobalBounds().height);	
	_pause.setColor(sf::Color(255, 255, 255, 100));
	if (!_foodtetxture.loadFromFile(Food_Texture_Filepath))
	{
		std::cout << "Failed to Open File" << std::endl;
	}	
	if (!_font.loadFromFile(Main_Menu_Font_Filepath))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_pausetext.setFont(_font);
	_pausetext.setString("Pause");
	_pausetext.setCharacterSize(75);
	_pausetext.setFillColor(sf::Color(255, 255, 255, 255));
	_pausetext.setOutlineThickness(5);
	_pausetext.setOutlineColor(sf::Color::Black);
	_pausetext.setPosition((_window.getSize().x / 2) - (_pausetext.getGlobalBounds().width / 2), _window.getSize().y - (7 * _pausetext.getGlobalBounds().height));

	_mainmenu.setFont(_font);
	_mainmenu.setString("Main Menu");
	_mainmenu.setCharacterSize(75);
	_mainmenu.setFillColor(sf::Color(255, 255, 255, 255));
	_mainmenu.setOutlineThickness(5);
	_mainmenu.setOutlineColor(sf::Color::Black);
	_mainmenu.setPosition((_window.getSize().x / 2) - (_mainmenu.getGlobalBounds().width / 2), _window.getSize().y - (4 * _mainmenu.getGlobalBounds().height));

	_exit.setFont(_font);
	_exit.setString("Exit");
	_exit.setCharacterSize(75);
	_exit.setFillColor(sf::Color(255, 255, 255, 255));
	_exit.setOutlineThickness(5);
	_exit.setOutlineColor(sf::Color::Black);
	_exit.setPosition((_window.getSize().x / 2) - (_exit.getGlobalBounds().width / 2), _window.getSize().y - (3 * _exit.getGlobalBounds().height));
	
	_continue.setFont(_font);
	_continue.setString("Continue");
	_continue.setCharacterSize(75);
	_continue.setFillColor(sf::Color(255, 255, 255, 255));
	_continue.setOutlineThickness(5);
	_continue.setOutlineColor(sf::Color::Black);
	_continue.setPosition((_window.getSize().x / 2) - (_continue.getGlobalBounds().width / 2), _window.getSize().y - (5.5 * _continue.getGlobalBounds().height));

	_score.setFont(_font);
	_score.setString(std::to_string(_player.getScore()));
	_score.setCharacterSize(75);
	_score.setFillColor(sf::Color(255, 255, 255, 150));
	_score.setPosition(0 , 0);

	_gameover.setFont(_font);
	_gameover.setString("Game Over");
	_gameover.setCharacterSize(75);
	_gameover.setFillColor(sf::Color(255, 255, 255, 255));
	_gameover.setOutlineThickness(5);
	_gameover.setOutlineColor(sf::Color::Black);
	_gameover.setPosition((_window.getSize().x / 2) - (_gameover.getGlobalBounds().width / 2), (_window.getSize().y / 2) - (_gameover.getGlobalBounds().height / 2));

	if (!_playertexture.loadFromFile(Player_Sprite_Texture_Filepath))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	_player.Initialize(&_playertexture, sf::Vector2u(5, 2), 0.2f, 500.0f, _window);
	if (!_enemy1texture.loadFromFile(Enemy_1_Sprite_Texture_Filepath))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	if (!_enemy2texture.loadFromFile(Enemy_2_Sprite_Texture_Filepath))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	if (!_enemy3texture.loadFromFile(Enemy_3_Sprite_Texture_Filepath))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	if (!_enemy4texture.loadFromFile(Enemy_4_Sprite_Texture_Filepath))
	{
		std::cout << "Failed to Open File" << std::endl;
	}
	int temp = rand() % 5 + 5;
	for (int i = 0; i < temp; i++)
	{
		_enemy.push_back(Enemy());
		switch (_enemy[i].GetType())
		{
		case 1:
			_enemy[i].Initialize(&_enemy1texture, sf::Vector2u(6, 1), 0.2f, 100.0f, _window);
			break;
		case 2:
			_enemy[i].Initialize(&_enemy2texture, sf::Vector2u(5, 1), 0.2f, 100.0f, _window);
			break;
		case 3:
			_enemy[i].Initialize(&_enemy3texture, sf::Vector2u(4, 1), 0.2f, 100.0f, _window);
			break;
		case 4:
			_enemy[i].Initialize(&_enemy4texture, sf::Vector2u(4, 1), 0.2f, 100.0f, _window);
			break;
		}
	}
	isfoodexist = false;
	isgameover = false;
	_foodclock.restart();
	_spawntime = rand() % 5 + 3;
	_spawn.restart();
}

void GameState::Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state)
{
	while (_window.pollEvent(_event))
	{
		if (_event.type == _event.Closed)
		{
			_window.close();
		}		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && start == true && _tempclock.getElapsedTime().asSeconds() >= 0.1f)
		{
			_window.setMouseCursorVisible(true);
			start = false;
			_tempclock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && start == false && _tempclock.getElapsedTime().asSeconds() >= 0.1f)
		{
			_window.setMouseCursorVisible(false);
			start = true;
			_tempclock.restart();
			_clock.restart();
		}
		if (start == false)
		{
			if (IsTextHovered(_continue, _window))
			{
				_continue.setFillColor(sf::Color(255, 255, 255, 150));
			}
			else
			{
				_continue.setFillColor(sf::Color(255, 255, 255, 255));
			}
			if (IsTextClicked(_continue, sf::Mouse::Left, _window))
			{
				_window.setMouseCursorVisible(false);
				start = true;
				_tempclock.restart();
				_clock.restart();
			}
			if (IsTextHovered(_mainmenu, _window))
			{
				_mainmenu.setFillColor(sf::Color(255, 255, 255, 150));
			}
			else
			{
				_mainmenu.setFillColor(sf::Color(255, 255, 255, 255));
			}
			if (IsTextClicked(_mainmenu, sf::Mouse::Left, _window))
			{
				_music.stop();
				_state.push_back(new MainMenuState);
				_state.back()->Init(_window);
			}
			if (IsTextHovered(_exit, _window))
			{
				_exit.setFillColor(sf::Color(255, 255, 255, 150));
			}
			else
			{
				_exit.setFillColor(sf::Color(255, 255, 255, 255));
			}
			if (IsTextClicked(_exit, sf::Mouse::Left, _window))
			{
				_window.close();
			}
		}
	}
}

void GameState::Update(sf::RenderWindow& _window, std::vector<State*>& _state)
{
	if (start)
	{				
		//spawn extra enemy
		if (_spawn.getElapsedTime().asSeconds() >= _spawntime)
		{
			_spawntime = rand() % 3 + 1;
			int amount = rand() % 3 + 1;
			for (int i = 0; i < amount; i++)
			{
				switch (_player.GetSize())
				{
				case 1:

					_enemy.push_back(Enemy(4, 3, 2, 1));
					break;
				case 2:
					_enemy.push_back(Enemy(2, 3, 3, 2));
					break;
				case 3:
					_enemy.push_back(Enemy(2, 2, 3, 3));
					break;
				}
				switch (_enemy[_enemy.size() - 1].GetType())
				{
				case 1:
					_enemy[_enemy.size() - 1].Initialize(&_enemy1texture, sf::Vector2u(6, 1), 0.2f, 100.0f, _window);
					break;
				case 2:
					_enemy[_enemy.size() - 1].Initialize(&_enemy2texture, sf::Vector2u(5, 1), 0.2f, 100.0f, _window);
					break;
				case 3:
					_enemy[_enemy.size() - 1].Initialize(&_enemy3texture, sf::Vector2u(4, 1), 0.2f, 100.0f, _window);
					break;
				case 4:
					_enemy[_enemy.size() - 1].Initialize(&_enemy4texture, sf::Vector2u(4, 1), 0.2f, 100.0f, _window);
					break;
				}
			}
			_spawn.restart();
		}
		if (_foodclock.getElapsedTime().asSeconds() >= Food_Interval && isfoodexist == false)
		{
			_food = new Food;
			_food->Initialize(&_foodtetxture, sf::Vector2u(3, 1), 0.2f, 100.0f, _window);
			isfoodexist = true;
			_foodclock.restart();
		}
		//remove enemy
		for (int i = 0; i < _enemy.size(); i++)
		{
			if (_enemy[i].getIsRemove())
			{
				_enemy.erase(_enemy.begin() + i);
				break;
			}
		}
		if (isfoodexist)
		{
			if (_food->getIsRemove())
			{
				delete _food;
				isfoodexist = false;
			}
		}
		//move entity
		_deltatime = _clock.restart().asSeconds();
		_player.Update(_deltatime, _window);
		for (int i = 0; i < _enemy.size(); i++)
		{
			_enemy[i].Update(_deltatime, _window);
			//check player colliding
			if (_player.IsColliding(_enemy[i]))
			{
				//eat
				if (_player.GetSize() >= _enemy[i].GetType())
				{
					if(!isgameover)
						_bite.play();
					switch (_enemy[i].GetType())
					{
					case 1:
						_player.AddScore(5);
						break;
					case 2:
						_player.AddScore(10);
						break;
					case 3:
						_player.AddScore(15);
						break;
					}
					_enemy.erase(_enemy.begin() + i);
					if ((_player.GetSize() == 1 && _player.getScore() >= 50) || (_player.GetSize() == 2 && _player.getScore() >= 125))
						_player.AddSize(_window);
					_score.setString(std::to_string(_player.getScore()));
					break;
				}
				//gameover
				else
				{
					if(!isgameover)
						_bite.play();
					isgameover = true;
					_gameoverclock.restart();
					_window.setMouseCursorVisible(true);
				}
			}
		}
		if (isfoodexist)
		{
			_food->Update(_deltatime, _window);
			if (_player.IsColliding(_food))
			{
				_bite.play();
				_player.AddScore(10);
				isfoodexist = false;
				delete _food;
				if ((_player.GetSize() == 1 && _player.getScore() >= 50) || (_player.GetSize() == 2 && _player.getScore() >= 125))
					_player.AddSize(_window);
				_score.setString(std::to_string(_player.getScore()));
			}
		}
	}
	if (isgameover)
	{
		if (_gameoverclock.getElapsedTime().asSeconds() >= Game_Over_Time)
		{
			_music.stop();
			_state.push_back(new GameOverState(_player.getScore()));
			_state.back()->Init(_window);
		}
	}
}



void GameState::Draw(sf::RenderWindow& _window)
{
	_window.clear();
	_window.draw(_bg);
	if(!isgameover)
		_player.Draw(_window);
	for (int i = 0; i < _enemy.size(); i++)
	{
		_enemy[i].Draw(_window);
	}
	if (isfoodexist)
		_food->Draw(_window);
	_window.draw(_score);
	if (!start)
	{
		_window.draw(_pause);
		_window.draw(_pausetext);
		_window.draw(_continue);
		_window.draw(_mainmenu);
		_window.draw(_exit);
	}
	if (isgameover)
		_window.draw(_gameover);
	_window.display();	
}
