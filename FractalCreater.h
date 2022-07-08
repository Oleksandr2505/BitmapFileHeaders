#pragma once
#include<iostream>
#include <string>
#include <cstdint>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"
#include<vector>


	class FractalCreator {
	private:
		int m_width;
		int m_height;
		unique_ptr<int[]> m_histogram;
		unique_ptr<int[]> m_fractal;
		Bitmap m_bitmap;
		ZoomList m_zoomList;
		int m_total{ 0 };

		vector<int>m_ranges;
		vector<RGB>m_colors;

		vector<int>m_rangeTotal;
		bool m_bGotFirstRange{ false };
		

	private:
		void calculateIteration();
		void calculateTotalIterations();
		void calculateRangeTotals();
		void drawFractal();
		void writeBitmap(string name);
		

	public:
		FractalCreator(int width, int height);
		void addRange(double rangeEnd,const RGB&rgb);
		int getRange(int iterations)const;
		void addZoom(const Zoom& zoom);
		virtual ~FractalCreator();
		void run(string name);
	};

