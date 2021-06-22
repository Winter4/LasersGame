#include "../Headers/Timer.h"

void Timer::substractSecond()
{
	time--;
}

sf::Time Timer::getElapsedTime()
{
	return timer.getElapsedTime();
}

void Timer::restart()
{
	timer.restart();
}

short Timer::getTime()
{
	return time;
}

void Timer::draw()
{
	text.setString(std::to_string(time));
	window->draw(text);
}