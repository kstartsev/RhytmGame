#include <cmath>

#include "Context.hpp"

Context::Context(double duration, int bpm, short speed)
    : audio_duration(duration), bpm(bpm), speed_level(speed)
{
  clock.stop();
  delta_clock.stop();
  time_per_beat = 60 / bpm;
  pixels_per_second = WINDOW_WIDTH / (time_per_beat * BEATS_PER_SCREEN);
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

float Context::getDeltaTime()
{
  delta_time = delta_clock.restart();
  // return -(pixels_per_second * speed_level * delta_time.asSeconds());
  return delta_time.asSeconds();
}

void Context::setSpeed(short speed) { speed_level = speed; }

void Context::updateCurrentBeats()
{
  timeline = clock.getElapsedTime();
  current_beat = std::floor(timeline.asSeconds() / time_per_beat);
}

double Context::getCurrentBeats()
{
  updateCurrentBeats();
  return current_beat;
}

double Context::getPixelsPerSecond()
{
  return pixels_per_second;
}
