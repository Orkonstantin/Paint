#pragma once
#include "TriangleF.h"
class HourglassF :public TriangleF{
	DECLARE_SERIAL(HourglassF)
public:
	HourglassF();
	HourglassF(int PenWidth, int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint P1, CPoint P2);
	void Draw(CDC* dc)const;
};