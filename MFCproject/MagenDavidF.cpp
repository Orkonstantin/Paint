#include "stdafx.h"
#include "MagenDavidF.h"

IMPLEMENT_SERIAL(MagenDavidF, CObject, 1)
MagenDavidF::MagenDavidF() {}
MagenDavidF::MagenDavidF(int PenWidth, int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint P1, CPoint P2) :
	Figure(PenWidth, p_lineType, p_borderColor, p_fillColor, P1, P2)
{}
void MagenDavidF::Draw(CDC* dc) const
{
	CPen pen;
	pen.CreatePen(lineType, PenWidth, borderColor);
	dc->SelectObject(&pen);
	CBrush brush;
	brush.CreateSolidBrush(fillColor);
	dc->SelectObject(&brush);

	CPoint center = P1 + P2;
	center.x /= 2.0; center.y /= 2.0;
	double radius = abs(P1.x - P2.x) < abs(P1.y - P2.y) ? abs(P1.x - P2.x) / 2.0 : abs(P1.y - P2.y) / 2.0;
	CPoint vertices[12];
	double two_pi = atan(1) * 8;
	for (int i = 0; i < 12; i++)
	{
		if (i % 2 == 0)
		{
			vertices[i].x = center.x + radius / sqrt(3) * cos(two_pi / 12 * i);
			vertices[i].y = center.y + radius / sqrt(3) * sin(two_pi / 12 * i);
		}
		else
		{
			vertices[i].x = center.x + radius * cos(two_pi / 12 * i);
			vertices[i].y = center.y + radius * sin(two_pi / 12 * i);
		}
	}
	dc->Polygon(vertices, 12);

	pen.DeleteObject();
	brush.DeleteObject();
}