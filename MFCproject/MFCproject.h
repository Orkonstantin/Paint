// MFCproject.h : main header file for the PROJECT_NAME application
//
#pragma once
#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif
#include "resource.h"		// main symbols
// CMFCprojectApp:
// See MFCproject.cpp for the implementation of this class
//
class CMFCprojectApp : public CWinApp
{
public:
	CMFCprojectApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
};
extern CMFCprojectApp theApp;