// MFCprojectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"
#include "afxdialogex.h"
#include "Figure.h"
#include "resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CMFCprojectDlg dialog
CMFCprojectDlg::CMFCprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
{
	type = RECTANGLE;
	m_PenWidth = 1;
	borderColor = RGB(0, 0, 0);
	fillColor = RGB(255, 255, 255);
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
void CMFCprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, CMFCColorButtonBorder);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, CMFCColorButtonBackground);
	DDX_Control(pDX, IDC_COMBO1, m_ComboPenWidth);
	DDX_Control(pDX, IDC_COMBO2, m_ComboLineType);

}
BEGIN_MESSAGE_MAP(CMFCprojectDlg, CDialogEx)
	ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTW, 0, 0xFFFF, OnToolTipText)
	ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTA, 0, 0xFFFF, OnToolTipText)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CMFCprojectDlg::OnBnClickedMfccolorbutton1)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON2, &CMFCprojectDlg::OnBnClickedMfccolorbutton2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCprojectDlg::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMFCprojectDlg::OnCbnSelchangeCombo2)
	ON_COMMAND(ID_CHOOSE_RECTANGLE, &CMFCprojectDlg::OnChooseRectangle)
	ON_COMMAND(ID_CHOOSE_ELLIPSE, &CMFCprojectDlg::OnChooseEllipse)
	ON_COMMAND(ID_CHOOSE_SAVE, &CMFCprojectDlg::OnChooseSave)
	ON_COMMAND(ID_CHOOSE_LOAD, &CMFCprojectDlg::OnChooseLoad)
	ON_COMMAND(ID_CHOOSE_UNDO, &CMFCprojectDlg::OnChooseUndo)
	ON_COMMAND(ID_CHOOSE_REDO, &CMFCprojectDlg::OnChooseRedo)
	ON_COMMAND(ID_NEW_WINDOW, &CMFCprojectDlg::OnNewWindow)
	ON_COMMAND(ID_Choose_Random, &CMFCprojectDlg::OnChooseRandom)
	ON_COMMAND(ID_CHOOSE_TRIANGLE, &CMFCprojectDlg::OnChooseTriangle)
	ON_COMMAND(ID_CHOOSE_LINE, &CMFCprojectDlg::OnChooseLine)
	ON_COMMAND(ID_CHOOSE_MAGENDAVID, &CMFCprojectDlg::OnChooseMagenDavid)
	ON_COMMAND(ID_CHOOSE_HOURGLASS, &CMFCprojectDlg::OnChooseHourglass)
	ON_COMMAND(ID_CHOOSE_STAR, &CMFCprojectDlg::OnChooseStar)
	ON_COMMAND(ID_Choose_Move, &CMFCprojectDlg::OnChooseMove)
	//להוסיף עוד צורות לכאן TOOLBAR

END_MESSAGE_MAP()
// CMFCprojectDlg message handlers
BOOL CMFCprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	// TODO: Add extra initialization here


	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);
	if (!m_ToolBar.CreateEx(this, TBSTYLE_FLAT,
		WS_VISIBLE | CBRS_TOP | CBRS_TOOLTIPS |
		CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_ToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		EndDialog(IDCANCEL);
	}
	m_ToolBar.EnableToolTips(true);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);
	m_ComboPenWidth.SetItemData(m_ComboPenWidth.AddString(L"0.1 mm"), 1);
	m_ComboPenWidth.SetItemData(m_ComboPenWidth.AddString(L"0.2 mm"), 2);
	m_ComboPenWidth.SetItemData(m_ComboPenWidth.AddString(L"0.4 mm"), 4);
	m_ComboPenWidth.SetItemData(m_ComboPenWidth.AddString(L"0.8 mm"), 8);
	m_ComboPenWidth.SetItemData(m_ComboPenWidth.AddString(L"1 mm"), 10);
	m_ComboPenWidth.SetCurSel(0);
	//
	m_ComboLineType.SetItemData(m_ComboLineType.AddString(L"1.Solid"), PS_SOLID);
	m_ComboLineType.SetItemData(m_ComboLineType.AddString(L"2.Dash"), PS_DASH);
	m_ComboLineType.SetItemData(m_ComboLineType.AddString(L"3.Dot"), PS_DOT);
	m_ComboLineType.SetItemData(m_ComboLineType.AddString(L"4.DashDot"), PS_DASHDOT);
	m_ComboLineType.SetItemData(m_ComboLineType.AddString(L"5.DashDotDot"), PS_DASHDOTDOT);
	m_ComboLineType.SetItemData(m_ComboLineType.AddString(L"6.Null"), PS_NULL);
	m_ComboLineType.SetCurSel(0);
	//

	return TRUE;  // return TRUE  unless you set the focus to a control
}
// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
void CMFCprojectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // device context for painting
		for (int i = 0; i < figs.GetSize(); i++)
			figs[i]->Draw(&dc);
		CDialogEx::OnPaint();
	}
}
// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CMFCprojectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (AllowMove == true)
	{
		start = point;
		isPressed = true;
		MoveIndex = -1;
		for (int i = (figs.GetSize() - 1); i >= 0; i--)
		{
			if (figs[i]->isInside(point))
			{
				MoveIndex = i;
				break;
			}
		}
		if (MoveIndex == -1)
		{
			//figs.Add(new Figure(m_PenWidth, lineType, borderColor, fillColor,start, start));
			switch (type)
			{
			case RECTANGLE:
				figs.Add(new RectangleF(m_PenWidth, lineType, borderColor, fillColor, start, start));
				break;
			case ELLIPSE:
				figs.Add(new EllipseF(m_PenWidth, lineType, borderColor, fillColor, start, start));
				break;
			case TRIANGLE:
				figs.Add(new TriangleF(m_PenWidth, lineType, borderColor, fillColor, start, start));
				break;
			case LINE:
				figs.Add(new LineF(m_PenWidth, lineType, borderColor, fillColor, start, start));
				break;
			case MAGENDAVID:
				figs.Add(new MagenDavidF(m_PenWidth, lineType, borderColor, fillColor, start, start));
				break;
			case HOURGLASS:
				figs.Add(new HourglassF(m_PenWidth, lineType, borderColor, fillColor, start, start));
				break;
			case STAR:
				figs.Add(new starF(m_PenWidth, lineType, borderColor, fillColor, start, start));
				break;
			}
		}
		InvalidateRect(&r);
	}
	else
	{
		start = point;
		isPressed = true;
		//figs.Add(new Figure(m_PenWidth, lineType, borderColor, fillColor,start, start));
		switch (type)
		{
		case RECTANGLE:
			figs.Add(new RectangleF(m_PenWidth, lineType, borderColor, fillColor, start, start));
			break;
		case ELLIPSE:
			figs.Add(new EllipseF(m_PenWidth, lineType, borderColor, fillColor, start, start));
			break;
		case TRIANGLE:
			figs.Add(new TriangleF(m_PenWidth, lineType, borderColor, fillColor, start, start));
			break;
		case LINE:
			figs.Add(new LineF(m_PenWidth, lineType, borderColor, fillColor, start, start));
			break;
		case MAGENDAVID:
			figs.Add(new MagenDavidF(m_PenWidth, lineType, borderColor, fillColor, start, start));
			break;
		case HOURGLASS:
			figs.Add(new HourglassF(m_PenWidth, lineType, borderColor, fillColor, start, start));
			break;
		case STAR:
			figs.Add(new starF(m_PenWidth, lineType, borderColor, fillColor, start, start));
			break;
		}
		InvalidateRect(&r);
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}
void CMFCprojectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (isPressed)
	{
		end = point;
		isPressed = false;
		if (MoveIndex == -1 && AllowMove == true)
			figs[figs.GetSize() - 1]->Redefine(start, end);
	}
	//Invalidate(); //simulates the WM_PAINT message to redraw window
	MoveIndex = -1;
	InvalidateRect(&r);
	CDialogEx::OnLButtonUp(nFlags, point);
}
void CMFCprojectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (isPressed)
	{
		end = point;
		if (MoveIndex == -1)
			figs[figs.GetSize() - 1]->Redefine(start, end);
		if (MoveIndex != -1 && AllowMove == true)
		{
			CPoint c = figs[MoveIndex]->getP1();
			figs[MoveIndex]->Shift(point, c);
		}
		Invalidate(); //simulates the WM_PAINT message to redraw window
		InvalidateRect(&r);
	}
	CDialogEx::OnMouseMove(nFlags, point);
}
void CMFCprojectDlg::OnBnClickedMfccolorbutton1()
{
		borderColor = CMFCColorButtonBorder.GetColor();
}
void CMFCprojectDlg::OnBnClickedMfccolorbutton2()
{
	fillColor = CMFCColorButtonBackground.GetColor();
}
void CMFCprojectDlg::OnCbnSelchangeCombo1()
{
	m_PenWidth = m_ComboPenWidth.GetItemData(m_ComboPenWidth.GetCurSel());
}
BOOL CMFCprojectDlg::OnToolTipText(UINT, NMHDR* pNMHDR, LRESULT* pResult)
{
	ASSERT(pNMHDR->code == TTN_NEEDTEXTA || pNMHDR->code == TTN_NEEDTEXTW);

	// if there is a top level routing frame then let it handle the message
	if (GetRoutingFrame() != NULL) return FALSE;

	// to be thorough we will need to handle UNICODE versions of the message also !!
	TOOLTIPTEXTA* pTTTA = (TOOLTIPTEXTA*)pNMHDR;
	TOOLTIPTEXTW* pTTTW = (TOOLTIPTEXTW*)pNMHDR;
	TCHAR szFullText[512];
	CString strTipText;
	UINT nID = pNMHDR->idFrom;

	if (pNMHDR->code == TTN_NEEDTEXTA && (pTTTA->uFlags & TTF_IDISHWND) ||
		pNMHDR->code == TTN_NEEDTEXTW && (pTTTW->uFlags & TTF_IDISHWND))
	{
		// idFrom is actually the HWND of the tool 
		nID = ::GetDlgCtrlID((HWND)nID);
	}

	if (nID != 0) // will be zero on a separator
	{
		AfxLoadString(nID, szFullText);
		strTipText = szFullText;

#ifndef _UNICODE
		if (pNMHDR->code == TTN_NEEDTEXTA)
		{
			lstrcpyn(pTTTA->szText, strTipText, sizeof(pTTTA->szText));
		}
		else
		{
			_mbstowcsz(pTTTW->szText, strTipText, sizeof(pTTTW->szText));
		}
#else
		if (pNMHDR->code == TTN_NEEDTEXTA)
		{
			_wcstombsz(pTTTA->szText, strTipText, sizeof(pTTTA->szText));
		}
		else
		{
			lstrcpyn(pTTTW->szText, strTipText, sizeof(pTTTW->szText));
		}
#endif

		* pResult = 0;

		// bring the tooltip window above other popup windows
		::SetWindowPos(pNMHDR->hwndFrom, HWND_TOP, 0, 0, 0, 0,
			SWP_NOACTIVATE | SWP_NOSIZE | SWP_NOMOVE | SWP_NOOWNERZORDER);

		return TRUE;
	}

	return FALSE;
}
void CMFCprojectDlg::OnCbnSelchangeCombo2()
{
	lineType = m_ComboLineType.GetItemData(m_ComboLineType.GetCurSel());
}
void CMFCprojectDlg::OnChooseRectangle()
{
	type = RECTANGLE;
}
void CMFCprojectDlg::OnChooseEllipse()
{
	type = ELLIPSE;
}
void CMFCprojectDlg::OnChooseTriangle()
{
	type = TRIANGLE;
}
void CMFCprojectDlg::OnChooseLine()
{
	type = LINE;
}
void CMFCprojectDlg::OnChooseMagenDavid()
{
	type = MAGENDAVID;
}
void CMFCprojectDlg::OnChooseHourglass()
{
	type = HOURGLASS;
}
void CMFCprojectDlg::OnChooseStar()
{
	type = STAR;
}
void CMFCprojectDlg::OnChooseSave()
{
	// TODO: Add your control notification handler code here
				 // FALSE to SAVE
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}
}
void CMFCprojectDlg::OnChooseLoad()
{
	// TODO: Add your control notification handler code here
				 // TRUE to LOAD
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
		InvalidateRect(&r);

	}
}
void CMFCprojectDlg::OnChooseUndo()
{
	// TODO: Add your command handler code here
	if (figs.GetSize() != 0)
	{
		temp.Add(figs[figs.GetSize() - 1]);
		figs.RemoveAt(figs.GetSize() - 1);
		Invalidate();
		InvalidateRect(&r);

	}
}
void CMFCprojectDlg::OnChooseRedo()
{
	// TODO: Add your command handler code here
	if (temp.GetSize() != 0)
	{
		figs.InsertAt(figs.GetSize(), temp.GetAt(temp.GetSize() - 1));
		temp.RemoveAt(temp.GetSize() - 1);
		Invalidate();
		InvalidateRect(&r);

	}
}
void CMFCprojectDlg::OnNewWindow()
{
	figs.RemoveAll();
	temp.RemoveAll();
	isPressed = false;
	AllowMove = false;
	Invalidate();
}
void CMFCprojectDlg::OnChooseMove()
{
	if (AllowMove == false)
		AllowMove = true;
	else
		AllowMove = false;
}
void CMFCprojectDlg::OnChooseRandom()
{
	srand(time(NULL));
	CPoint p1, p2;
	int i = 0;
	int width, LineStyle, green, blue, red;
	p1.x = rand() % 875 + 1;
	p1.y = rand() % 520 + 1;
	p2.x = rand() % 700 + 1;
	p2.y = rand() % 500 + 36;
	LineStyle= rand() % 5 + 1;
	width = rand() % 10 + 1;
	red = rand() % 254 + 1;
	green = rand() % 254 + 1;
	blue = rand() % 254 + 1;
	figs.Add(new RectangleF(width, LineStyle, RGB(red, green, blue), RGB(red, green, blue), p1, p2));
	LineStyle = rand() % 4 + 1;
	width = rand() % 10 + 1;
	red = rand() % 254 + 1;
	green = rand() % 254 + 1;
	blue = rand() % 254 + 1;
	p1.x = rand() % 875 + 1;
	p1.y = rand() % 520 + 1;
	p2.x = rand() % 700 + 1;
	p2.y = rand() % 500 + 36;
	figs.Add(new EllipseF(width, LineStyle, RGB(red, green, blue), RGB(red, green, blue), p1, p2));
	LineStyle = rand() % 4 + 1;
	width = rand() % 10 + 1;
	red = rand() % 254 + 1;
	green = rand() % 254 + 1;
	blue = rand() % 254 + 1;
	p1.x = rand() % 875 + 1;
	p1.y = rand() % 520 + 1;
	p2.x = rand() % 700 + 1;
	p2.y = rand() % 500 + 36;
	figs.Add(new TriangleF(width, LineStyle, RGB(red, green, blue), RGB(red, green, blue), p1, p2));
	LineStyle = rand() % 4 + 1;
	width = rand() % 10 + 1;
	red = rand() % 254 + 1;
	green = rand() % 254 + 1;
	blue = rand() % 254 + 1;
	p1.x = rand() % 875 + 1;
	p1.y = rand() % 520 + 1;
	p2.x = rand() % 700 + 1;
	p2.y = rand() % 500 + 36;
	figs.Add(new LineF(width, LineStyle, RGB(red, green, blue), RGB(red, green, blue), p1, p2));
	LineStyle = rand() % 4 + 1;
	width = rand() % 10 + 1;
	red = rand() % 254 + 1;
	green = rand() % 254 + 1;
	blue = rand() % 254 + 1;
	p1.x = rand() % 875 + 1;
	p1.y = rand() % 520 + 1;
	p2.x = rand() % 700 + 1;
	p2.y = rand() % 500 + 36;
	figs.Add(new MagenDavidF(width, LineStyle, RGB(red, green, blue), RGB(red, green, blue), p1, p2));
	Invalidate();
	InvalidateRect(&r);
}