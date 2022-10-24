#include "stdafx.h"
#include "LineF.h"
IMPLEMENT_SERIAL(LineF, CObject, 1)
LineF::LineF(){}
LineF::LineF(int PenWidth, int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint P1, CPoint P2) :
	Figure(PenWidth, p_lineType, p_borderColor, p_fillColor, P1, P2)
{}
void LineF::Draw(CDC* dc) const
{
	CPen pen;
	pen.CreatePen(lineType, PenWidth, borderColor);
	dc->SelectObject(&pen);
	CBrush brush;
	brush.CreateSolidBrush(fillColor);
	dc->SelectObject(&brush);

	dc->MoveTo(P1);
	dc->LineTo(P2);

	pen.DeleteObject();
	brush.DeleteObject();
}