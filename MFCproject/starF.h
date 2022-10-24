#pragma once
#include "TriangleF.h"
class starF :public TriangleF{
	DECLARE_SERIAL(starF)
public:
	starF();
	starF(int PenWidth, int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint P1, CPoint P2);
	void Draw(CDC* dc)const;
};
