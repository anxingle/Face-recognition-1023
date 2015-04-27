// First.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Recognition.h"
#include "First.h"
#include "afxdialogex.h"


// CFirst �Ի���

IMPLEMENT_DYNAMIC(CFirst, CPropertyPage)

CFirst::CFirst()
	: CPropertyPage(CFirst::IDD)
{
	m_font.CreatePointFont(200,_T("΢���ź�"));
}

CFirst::~CFirst()
{
}

void CFirst::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFirst, CPropertyPage)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CFirst ��Ϣ�������


BOOL CFirst::OnSetActive()
{
	// TODO: �ڴ����ר�ô����/����û���
	// ��ø����� CProperty��  
	CPropertySheet * psheet=(CPropertySheet*)GetParent();
	psheet->SetWizardButtons(PSWIZB_NEXT);

	return CPropertyPage::OnSetActive();
}


HBRUSH CFirst::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CPropertyPage::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	if (pWnd->GetDlgCtrlID() == IDC_first_one || pWnd->GetDlgCtrlID() == IDC_first_two)
		pDC->SelectObject(&m_font);
	// TODO:  Return a different brush if the default is not desired
	return hbr;
}
