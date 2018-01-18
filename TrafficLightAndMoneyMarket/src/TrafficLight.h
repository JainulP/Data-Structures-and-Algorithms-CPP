#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <string>

using namespace std;

/**
   A simulated traffic light.
*/
class TrafficLight
{
private:
   int state;
   int reds;
public:
   /**
      Constructs a green traffic light.
   */
   TrafficLight();
   /**
      Constructs a traffic light.
      @param initial_color the initial color "green", "yellow", or "red"
   */
   TrafficLight(string initial_color);

   /**
      Moves this traffic light to the next color (red, green, yellow,
      red, and so on.)
   */
   void next();

   /**
      Returns the current color of this traffic light.
      @return the current color
   */
   string get_color() const;

   /**
      Counts how often this traffic light has been red.
      @return the number of times this traffic light has been red
   */
   int get_reds() const;
};

#endif
