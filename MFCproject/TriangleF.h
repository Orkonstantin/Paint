#pragma once
#include "Figure.h"
class TriangleF :public Figure{
	DECLARE_SERIAL(TriangleF)
public:
	TriangleF();
	TriangleF(int PenWidth, int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint P1, CPoint P2);
	void Draw(CDC* dc)const;
};