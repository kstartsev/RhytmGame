#include <cmath>

#include "Context.hpp"

using namespace DefaultParameters;

Context::Context(double duration, int bpm, short speed)
    : audio_duration(duration), bpm(bpm), speed(speed)
{
  clock.stop();
  delta_clock.stop();
  time_per_beat = 60 / bpm;
  pixels_per_second = (WINDOW_WIDTH / (time_per_beat * BEATS_PER_SCREEN)) * speed;
}

void Context::clear()
{
  *this = Context();
}

void Context::reset()
{
  clock.reset();
  delta_clock.reset();
  delta_time = sf::seconds(0.f);
  timeline = sf::seconds(0.f);
  current_beat = 0;
}

void Context::startTimers()
{
  clock.start();
  delta_clock.start();
}

void Context::stopTimers()
{
  clock.stop();
  delta_clock.stop();
}

void Context::updateDeltaTime()
{
  delta_time = delta_clock.restart();
}

float Context::getDeltaTime() const
{
  return delta_time.asSeconds();
}

void Context::updateCurrentBeats()
{
  updateCurrentTime();
  current_beat = std::floor(timeline.asSeconds() / time_per_beat);
}

double Context::getCurrentBeats()
{
  updateCurrentBeats();
  return current_beat;
}

double Context::getPixelsPerSecond() const
{
  return pixels_per_second;
}

double Context::getAudioDuration() const
{
  return audio_duration;
}

void Context::updateCurrentTime()
{
  timeline = clock.getElapsedTime();
}

bool Context::isFinish()
{
  updateCurrentTime();
  return timeline.asSeconds() > audio_duration;
}
