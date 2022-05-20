#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "Definition.h"
#include "Additional.h"
#include "GameState.h"
#include "TutorialState.h"
#include "State.h"
class MainMenuState : public State
{
public:
	MainMenuState();
	~MainMenuState();

	void Init(sf::RenderWindow& _window);
	void Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state);
	void Update(sf::RenderWindow& _window, std::vector<State*>& _state);
	void Draw(sf::RenderWindow& _window);
private:
	sf::Texture _texture;
	sf::Sprite _bg;
	sf::Font _font;
	sf::Text _title, _play, _exit, _tutorial;
	sf::Music _music;
};

