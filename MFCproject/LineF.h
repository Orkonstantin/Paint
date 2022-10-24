#pragma once
#include "Figure.h"
class LineF :public Figure{
	DECLARE_SERIAL(LineF)
public:
	LineF();
	LineF(int PenWidth, int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint P1, CPoint P2);
	void Draw(CDC* dc) const;
};