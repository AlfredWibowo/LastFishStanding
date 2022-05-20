#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<vector>
#include "Definition.h"
#include "Additional.h"
#include"Player.h"
#include "State.h"
#include "Enemy.h"
#include "GameOverState.h"
#include "Food.h"
class GameState : public State
{
public:
	GameState();
	~GameState();

	void Init(sf::RenderWindow& _window);
	void Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state);
	void Update(sf::RenderWindow& _window, std::vector<State*>& _state);
	void Draw(sf::RenderWindow& _window);
private:
	sf::Texture _texture;
	sf::Sprite _bg, _pause;
	sf::Texture _playertexture, _enemy1texture, _enemy2texture, _enemy3texture, _enemy4texture, _pausetexture, _foodtetxture;
	sf::Clock _clock, _spawn, _tempclock, _foodclock, _gameoverclock;
	sf::Font _font;
	sf::Text _pausetext, _exit, _mainmenu, _continue, _score, _gameover;
	Food* _food;
	int _spawntime;
	float _deltatime;
	Player _player;
	std::vector<Enemy> _enemy;
	bool start = false, isfoodexist, isgameover;
	sf::SoundBuffer _bitebuffer;
	sf::Sound _bite;
	sf::Music _music;
};