#include "Game.h"

#include "States/StatePlaying.h"
#include "States/StateMenu.h"

Game::Game()
:   m_window    ({1500, 900}, "Limpia Playas")
{
    m_window.setFramerateLimit(100);

	pushState<StateMenu>(*this); 
}

void Game::run()
{
    constexpr unsigned TPS = 60;                   
    const sf::Time     timePerUpdate = sf::seconds(1.0f / float(TPS));
    unsigned ticks = 0;

    sf::Clock timer;
    auto lastTime = sf::Time::Zero;
    auto lag      = sf::Time::Zero;

    while (m_window.isOpen() && !m_states.empty())
    {
        auto& state = getCurrentState();


        auto time = timer.getElapsedTime();
        auto elapsed = time - lastTime;

        lastTime = time;
        lag += elapsed;


        state.handleInput();
        state.update(elapsed);
        counter.update();


        while (lag >= timePerUpdate)
        {
            ticks++;
            lag -= timePerUpdate;
            state.fixedUpdate(elapsed);
        }


        m_window.clear(sf::Color(70,85,57));
        state.render(m_window);
        counter.draw(m_window);
        m_window.display();


        handleEvent();

	
		state.pushState(m_shouldPush);
		state.popState(m_shouldPop);


		if (m_shouldPush[0])
		{
			pushState<StatePlaying>(*this);
			m_shouldPush[0] = false;
		}

		
        tryPop();
    }
}
void Game::tryPop()
{
    if (m_shouldPop)
    {
        m_states.pop();
		m_shouldPop = false;
    }
}

void Game::handleEvent()
{
    sf::Event e;

    while (m_window.pollEvent(e))
    {
        getCurrentState().handleEvent(e);
		switch (e.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		}
	}
}

StateBase& Game::getCurrentState()
{
    return *m_states.top();
}

void Game::popState()
{
    m_shouldPop = true;
}

const sf::RenderWindow& Game::getWindow() const
{
    return m_window;
}
 
