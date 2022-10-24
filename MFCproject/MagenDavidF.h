#pragma once
#include "Figure.h"
class MagenDavidF :public Figure {
	DECLARE_SERIAL(MagenDavidF)
public:
	MagenDavidF();
	MagenDavidF(int PenWidth, int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint P1, CPoint P2);
	void Draw(CDC* dc) const;
};