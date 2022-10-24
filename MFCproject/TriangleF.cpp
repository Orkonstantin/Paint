#include "stdafx.h"
#include "TriangleF.h"

IMPLEMENT_SERIAL(TriangleF, CObject, 1)
TriangleF::TriangleF() {}
TriangleF::TriangleF(int PenWidth, int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint P1, CPoint P2) :
	Figure(PenWidth, p_lineType, p_borderColor, p_fillColor, P1, P2)
{}
void TriangleF::Draw(CDC* dc) const
{
	CPen pen;
	pen.CreatePen(lineType, PenWidth, borderColor);
	dc->SelectObject(&pen);
	CBrush brush;
	brush.CreateSolidBrush(fillColor);
	dc->SelectObject(&brush);

	CPoint Pt[3];
	Pt[0] = CPoint(P1.x, P2.y);
	Pt[1] = CPoint((P1.x + P2.x) / 2, P1.y);
	Pt[2] = CPoint(P2.x, P2.y);
	dc->Polygon(Pt, 3);

	pen.DeleteObject();
	brush.DeleteObject();
}