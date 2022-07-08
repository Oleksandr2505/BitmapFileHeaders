
#include "ZoomList.h"
#include"Zoom.h"


ZoomList::ZoomList(int width, int height) : width(width), height(height) {
}
//calculate new center of fractal
void ZoomList::add(const Zoom& zoom) {

	zooms.push_back(zoom);
	//calculate how far the point we are clicking is from the center
	m_xCenter += (zoom.x - width / 2) * m_scale; 
	m_yCenter += -(zoom.y - height / 2) * m_scale; 
	m_scale *= zoom.scale;

	
}
std::pair<double, double>ZoomList::doZoom(int x, int y) {
	double xFractal = (x - width / 2)*m_scale  + m_xCenter;
	double yFractal = (y - height / 2) *m_scale + m_yCenter;
	return std::pair<double, double>(xFractal, yFractal);
}