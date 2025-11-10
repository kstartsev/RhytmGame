#include <cmath>

#include "Context.hpp"

Context::Context(double duration, int bpm, short speed)
    : audio_duration(duration), bpm(bpm)
{
  clock.stop();
  delta_clock.stop();
  time_per_beat = 60 / bpm;
  pixels_per_second = (WINDOW_WIDTH / (time_per_beat * BEATS_PER_SCREEN)) * speed;
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
