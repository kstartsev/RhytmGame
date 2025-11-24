#include "AudioManager.hpp"

AudioManager::AudioManager() {}

void AudioManager::setMusic(std::shared_ptr<sf::Music> music)
{
  level_music = music;
}

void AudioManager::playMusic()
{
  level_music->play();
}

void AudioManager::pauseMusic()
{
  level_music->pause();
}

void AudioManager::resetMusic()
{
  level_music->stop();
  level_music->play();
}
