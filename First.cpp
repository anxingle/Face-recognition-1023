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

}

CFirst::~CFirst()
{
}

void CFirst::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFirst, CPropertyPage)
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
