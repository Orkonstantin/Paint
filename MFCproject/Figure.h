#pragma once
#include "stdafx.h"
#include <vector>
class Figure: public CObject {
	DECLARE_SERIAL(Figure)
	int PenWidth;
	int lineType;
	COLORREF borderColor;
	COLORREF fillColor;
	CPoint P1, P2;
public:
	Figure() :PenWidth(1),lineType(PS_SOLID), borderColor(RGB(0, 0, 0)), fillColor(RGB(255, 255, 255)), P1(100, 100), P2(200, 200){}
	Figure(int p_PenWidth,int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint) :
		PenWidth(p_PenWidth),lineType(p_lineType), borderColor(p_borderColor), fillColor(p_fillColor), P1(p_startPoint), P2(p_endPoint)
	{}
	void Serialize(CArchive& ar);
	virtual void Draw(CDC* dc) const
	{
		CPen pen;
		pen.CreatePen(lineType, PenWidth, borderColor);
		dc->SelectObject(&pen);
		CBrush brush;
		brush.CreateSolidBrush(fillColor);
		dc->SelectObject(&brush);
		dc->Rectangle(P1.x, P1.y, P2.x, P2.y);
		pen.DeleteObject();
		brush.DeleteObject();
	}
	CPoint getP1() const { return P1; }
	CPoint getP2() const { return P2; }
	CPoint getx1() const { return P1.x; }
	CPoint getx2() const { return P2.x; }
	CPoint gety1() const { return P1.y; }
	CPoint gety2() const { return P2.y; }
	void setx1(CPoint p) { P1.x = p.x; }
	void setx2(CPoint p) { P2.x = p.x; }
	void sety1(CPoint p) { P1.y = p.y; }
	void sety2(CPoint p) { P2.y = p.y; }
	virtual void Redefine(CPoint p1, CPoint p2) { P1 = p1; P2 = p2; }
	virtual bool isInside(const CPoint &P) const;
	virtual void Shift(CPoint c1, CPoint c2);
};