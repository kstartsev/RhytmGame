#pragma once

#include <SFML/System.hpp>

#define WINDOW_WIDTH 1920
#define BEATS_PER_SCREEN 4
#define NORMAL_SPEED 1

class Context
{
private:
  double audio_duration = 0;
  int bpm = 0;
  short speed = NORMAL_SPEED;
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
  Context(const Context &) = default;
  ~Context() = default;
  Context &operator=(const Context &b) = default;
  void clear();
  void reset();

  void startTimers();
  void stopTimers();
  void updateDeltaTime();
  float getDeltaTime() const;
  void updateCurrentBeats();
  double getCurrentBeats();
  double getAudioDuration() const;
  double getPixelsPerSecond() const;
  void updateCurrentTime();
  bool isFinish();
};
