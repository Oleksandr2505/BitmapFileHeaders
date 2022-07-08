#include"FractalCreater.h"
#include"RGB.h"
#include"Zoom.h"
#include<iostream>

int main() {

	FractalCreator fractalCreator(800, 600);
	fractalCreator.addRange(0.0, RGB(0, 0, 0));
	fractalCreator.addRange(0.3, RGB(255, 0, 0));
	fractalCreator.addRange(0.5, RGB(255, 255, 0));
	fractalCreator.addRange(1.0, RGB(255, 255, 255));

	std::cout << fractalCreator.getRange(999) << std::endl;

	fractalCreator.addZoom(Zoom(295, 202, 0.1));
	fractalCreator.addZoom(Zoom(312, 304, 0.1));
	fractalCreator.run("test.bmp");

	std::cout << "Finished." << std::endl;
	return 0;
}

