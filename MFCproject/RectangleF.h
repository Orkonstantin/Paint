#pragma once
#include "Figure.h"
class RectangleF : public Figure {
	DECLARE_SERIAL(RectangleF)
public:
	RectangleF();
	RectangleF(int PenWidth,int p_lineType, COLORREF p_borderCOlor, COLORREF p_fillColor, CPoint P1, CPoint P2);
	void draw(CDC* dc)const;
};