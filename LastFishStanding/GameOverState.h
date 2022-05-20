#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "Definition.h"
#include "Additional.h"
#include "MainMenuState.h"
#include "State.h"
#include<fstream>

class GameOverState : public State
{
public:
	GameOverState(int score);
	~GameOverState();

	void Init(sf::RenderWindow& _window);
	void Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state);
	void Update(sf::RenderWindow& _window, std::vector<State*>& _state);
	void Draw(sf::RenderWindow& _window);
private:
	sf::Texture _texture;
	sf::Sprite _bg;
	sf::Font _font;
	sf::Text _title, _back, _exit, _score, _highscore;
	sf::Music _music;
	int score, highscore;
	std::fstream highscore_file;
};

