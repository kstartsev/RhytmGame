#pragma once

#define SCREEN_WIDTH 1920
#define BITS_PER_SCREEN 4

class Utils
{
public:
  static float beatsToPixels(double beats)
  {
    return (beats / BITS_PER_SCREEN) * SCREEN_WIDTH;
  }
};
