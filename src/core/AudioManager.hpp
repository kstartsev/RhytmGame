#pragma once

#include <SFML/Audio.hpp>
#include <memory>

class AudioManager
{
private:
  std::shared_ptr<sf::Music> level_music;
public:
  AudioManager();
  void setMusic(std::shared_ptr<sf::Music> music);
  void playMusic();
  void pauseMusic();
  void resetMusic();
};
