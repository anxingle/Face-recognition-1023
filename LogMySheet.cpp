// LogMySheet.cpp : implementation file
//

#include "stdafx.h"
#include "Recognition.h"
#include "LogMySheet.h"


// CLogMySheet

IMPLEMENT_DYNAMIC(CLogMySheet, CPropertySheet)

CLogMySheet::CLogMySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_first);
	AddPage(&m_second);
	//AddPage(&m_third);
}

CLogMySheet::CLogMySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_first);
	AddPage(&m_second);
	//AddPage(&m_third);
}

CLogMySheet::~CLogMySheet()
{
}


BEGIN_MESSAGE_MAP(CLogMySheet, CPropertySheet)
END_MESSAGE_MAP()


// CLogMySheet message handlers
