#include<vector>
#include "Zoom.h"

class ZoomList
{


	double m_xCenter{ 0 };
	double m_yCenter{ 0 };
	double m_scale{ 1.0 };

	double width = 0;
	double height = 0;

	std::vector<Zoom>zooms;

public:
	ZoomList() = default;
	ZoomList(int width, int height);
	void add(const Zoom& zoom);
	std::pair<double, double> doZoom(int x, int y);
};