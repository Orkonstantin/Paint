#pragma once
#include "Figure.h"
class EllipseF :public Figure {
	DECLARE_SERIAL(EllipseF)
public:
	EllipseF();
	EllipseF(int PenWidth,int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint P1, CPoint P2);
	void Draw(CDC* dc) const;
};