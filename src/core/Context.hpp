#pragma once

#include <SFML/System.hpp>

#define WINDOW_WIDTH 1920
#define BEATS_PER_SCREEN 4
#define SLOW_SPEED 0.5
#define NORMAL_SPEED 1
#define FAST_SPEED 2
#define VERYFAST_SPEED 3

class Context
{
private:
  double audio_duration = 0;
  int bpm = 0;
  double time_per_beat = 0;
  double pixels_per_second = 0;
  sf::Clock clock;
  sf::Time timeline;
  double current_beat = 0;
  sf::Clock delta_clock;
  sf::Time delta_time;

public:
  Context() = default;
  Context(double duration, int bpm, short speed);
  ~Context() = default;
  Context& operator=(const Context& b) = default;
  void startTimers();
  void stopTimers();
  void updateDeltaTime();
  float getDeltaTime() const;
  void updateCurrentBeats();
  double getCurrentBeats();
  double getPixelsPerSecond();
};
