#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "Definition.h"
#include "Additional.h"
#include "GameState.h"
#include "State.h"
class TutorialState : public State
{
public:
	TutorialState();
	~TutorialState();

	void Init(sf::RenderWindow& _window);
	void Input(sf::RenderWindow& _window, sf::Event& _event, std::vector<State*>& _state);
	void Update(sf::RenderWindow& _window, std::vector<State*>& _state);
	void Draw(sf::RenderWindow& _window);
private:
	sf::Texture _texture1, _texture2;
	sf::Sprite _page1, _page2;
	sf::Font _font;
	sf::Text _back, _next, _prev;
	sf::Music _music;
	sf::Clock _clock;
	int page;
};