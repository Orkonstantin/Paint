#include "stdafx.h"
#include "HourglassF.h"

IMPLEMENT_SERIAL(HourglassF, CObject, 1)
HourglassF::HourglassF() {}
HourglassF::HourglassF(int PenWidth, int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint P1, CPoint P2) :
	TriangleF(PenWidth, p_lineType, p_borderColor, p_fillColor, P1, P2)
{}
void HourglassF::Draw(CDC* dc) const
{
	CPen pen;
	pen.CreatePen(lineType, PenWidth, borderColor);
	dc->SelectObject(&pen);
	CBrush brush;
	brush.CreateSolidBrush(fillColor);
	dc->SelectObject(&brush);

	CPoint Pt[4];
	Pt[0] = CPoint(P1.x, P1.y);
	Pt[1] = CPoint(P2.x,P1.y);
	Pt[2] = CPoint(P1.x, P2.y);
	Pt[3] = CPoint(P2.x, P2.y);
	dc->Polygon(Pt, 4);

	pen.DeleteObject();
	brush.DeleteObject();
}