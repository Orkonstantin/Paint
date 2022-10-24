#include "stdafx.h"
#include "starF.h"

IMPLEMENT_SERIAL(starF, CObject, 1)
starF::starF() {}
starF::starF(int PenWidth, int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint P1, CPoint P2) :
	TriangleF(PenWidth, p_lineType, p_borderColor, p_fillColor, P1, P2)
{}
void starF::Draw(CDC* dc) const
{
	CPen pen;
	pen.CreatePen(lineType, PenWidth, borderColor);
	dc->SelectObject(&pen);
	CBrush brush;
	brush.CreateSolidBrush(fillColor);
	dc->SelectObject(&brush);

	int R = 25;
	int R2 = int(R / sqrt(2));
	POINT pt[8];
	int x = P1.x;
	int y = P1.y;
	R = (P2.x + P2.y)/10;
	pt[0].x = x; pt[0].y = y - R;
	pt[1].x = x + R2; pt[1].y = y - R2;
	pt[2].x = x + R; pt[2].y = y;
	pt[3].x = x + R2; pt[3].y = y + R2;
	pt[4].x = x; pt[4].y = y + R;
	pt[5].x = x - R2; pt[5].y = y + R2;
	pt[6].x = x - R; pt[6].y = y;
	pt[7].x = x - R2; pt[7].y = y - R2;
	dc->Polygon(pt, 8);

	pen.DeleteObject();
	brush.DeleteObject();
}