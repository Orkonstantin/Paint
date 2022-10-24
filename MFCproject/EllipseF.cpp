#include "stdafx.h"
#include "EllipseF.h"
IMPLEMENT_SERIAL(EllipseF, CObject, 1)
EllipseF::EllipseF(){}
EllipseF::EllipseF(int PenWidth, int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint P1, CPoint P2) :
	Figure(PenWidth, p_lineType, p_borderColor, p_fillColor, P1, P2)
{}
void EllipseF::Draw(CDC* dc) const
{
	CPen pen;
	pen.CreatePen(lineType, PenWidth, borderColor);
	dc->SelectObject(&pen);
	CBrush brush;
	brush.CreateSolidBrush(fillColor);
	dc->SelectObject(&brush);

	dc->Ellipse(P1.x, P1.y, P2.x, P2.y);

	pen.DeleteObject();
	brush.DeleteObject();
}