#include "TrafficLight.h"

TrafficLight::TrafficLight()
{
   state =0;
   reds =0;
}

TrafficLight::TrafficLight(string initial_color)
{
	 reds =0;
   if (initial_color == "green") {
      state = 0;
   }
   else if (initial_color == "yellow") {
      state = 1;
   }
   else if (initial_color == "red") {
      state = 2;
      reds++;
   }
}

void TrafficLight::next()
{
	 if(state == 0)
	 {
		 state =1;
	 }
	 else if(state == 1)
	 {
		 reds++;
		 state =2;
	 }
	 else if(state == 2)
	 	 {
	 		 state =0;
	 	 }
}

string TrafficLight::get_color() const
{
   if (state == 2) return "red";
   else if (state == 1) return "yellow";
   else return "green";
}

int TrafficLight::get_reds() const
{
	return reds;
}
