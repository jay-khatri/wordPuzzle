/*Brockway, Khatiri, Tiner
Final Project
Last update: 11-21-16
Purpose: function and class definitons for end window--third window in a gui sequence*/

#include "end_window.h"

end_window::end_window(Point xy, int w, int h, const string& title): 
Window(xy, w, h, title),
//button initializations
play_again(Point(x_max()/2 - 60,y_max() -20), 120, 40, "Play again?"),
{
	
}