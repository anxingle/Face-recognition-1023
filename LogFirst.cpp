// LogFirst.cpp : implementation file
//

#include "stdafx.h"
#include "Recognition.h"
#include "LogFirst.h"
#include "afxdialogex.h"


// CLogFirst dialog

IMPLEMENT_DYNAMIC(CLogFirst, CPropertyPage)

CLogFirst::CLogFirst()
	: CPropertyPage(CLogFirst::IDD)
{
	m_font.CreatePointFont(200, _T("Î¢ÈíÑÅºÚ"));
}

CLogFirst::~CLogFirst()
{
}

void CLogFirst::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLogFirst, CPropertyPage)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CLogFirst message handlers


BOOL CLogFirst::OnSetActive()
{
	// TODO: Add your specialized code here and/or call the base class
	CPropertySheet * psheet = (CPropertySheet*)GetParent();
	psheet->SetWizardButtons(PSWIZB_NEXT);
	return CPropertyPage::OnSetActive();
}


HBRUSH CLogFirst::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CPropertyPage::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	if (pWnd->GetDlgCtrlID() == IDC_logfirst_two || pWnd->GetDlgCtrlID() == IDC_logfirst_one)
	{
		pDC->SelectObject(&m_font);
		//pDC->SetWindow
	}
	// TODO:  Return a different brush if the default is not desired
	return hbr;
}
