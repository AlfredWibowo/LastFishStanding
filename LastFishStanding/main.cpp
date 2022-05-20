#include<SFML/Graphics.hpp>
#include<time.h>
#include "SplashState.h"
#include "Additional.h"
#include "GameState.h"
#include "MainMenuState.h"
#include<vector>

int main()
{
	srand(time(NULL));
	sf::RenderWindow _window(sf::VideoMode(1366, 768), "Last Fish Standing", sf::Style::Fullscreen);
	std::vector<State*> _state;
	_state.push_back(new SplashState);
	_state.back()->Init(_window);
	_window.setFramerateLimit(120);
	while (_window.isOpen())
	{		
		sf::Event _event;		

		_state.back()->Input(_window, _event, _state);
		_state.back()->Update(_window, _state);
		_state.back()->Draw(_window);

		if (_state.size() >= 4)
		{
			delete _state[0];
			_state.erase(_state.begin());
		}
	}
	for (int i = 0; i < _state.size(); i++)
		delete _state[i];
	return 0;
}