// MFCprojectDlg.h : header file
//
#pragma once
#include "Figure.h"
#include "RectangleF.h"
#include "EllipseF.h"
#include "TriangleF.h"
#include "LineF.h"
#include "MagenDavidF.h"
#include"HourglassF.h"
#include "starF.h"
// CMFCprojectDlg dialog
class CMFCprojectDlg : public CDialogEx
{
	// Construction
public:
	CMFCprojectDlg(CWnd* pParent = nullptr);	// standard constructor
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif
	CPoint start, end;
	COLORREF borderColor;
	COLORREF fillColor;
	int lineType;
	CComboBox m_ComboLineType;
	int m_PenWidth;
	CComboBox m_ComboPenWidth;
	bool isPressed = false;
	CTypedPtrArray< CObArray, Figure*> figs;
	CTypedPtrArray< CObArray, Figure*> temp; // for Undo & Redo
	enum shapeType { RECTANGLE, ELLIPSE, TRIANGLE, LINE, MAGENDAVID, HOURGLASS,STAR};
	shapeType type;
	//@@
	int MoveIndex = -1;
	RECT r;
	bool AllowMove = false;
	//@@
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void OnBnClickedMfccolorbutton2();
	CMFCColorButton CMFCColorButtonBorder;
	CMFCColorButton CMFCColorButtonBackground;
	afx_msg void OnCbnSelchangeCombo1();
	CToolBar m_ToolBar;
	afx_msg BOOL OnToolTipText(UINT nID, NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChooseRectangle();
	afx_msg void OnChooseEllipse();
	afx_msg void OnChooseSave();
	afx_msg void OnChooseLoad();
	afx_msg void OnChooseUndo();
	afx_msg void OnChooseRedo();
	afx_msg void OnNewWindow();
	afx_msg void OnChooseRandom();
	afx_msg void OnCbnSelchangeCombo2();
	//
	afx_msg void OnChooseTriangle();
	afx_msg void OnChooseLine();
	afx_msg void OnChooseMagenDavid();
	afx_msg void OnChooseHourglass();
	afx_msg void OnChooseStar();
	afx_msg void OnChooseMove();
};