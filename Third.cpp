// Third.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Recognition.h"
#include "Third.h"
#include "afxdialogex.h"


// CThird �Ի���

IMPLEMENT_DYNAMIC(CThird, CPropertyPage)

CThird::CThird()
	: CPropertyPage(CThird::IDD)
{

}

CThird::~CThird()
{
}

void CThird::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CThird, CPropertyPage)
END_MESSAGE_MAP()


// CThird ��Ϣ�������


BOOL CThird::OnSetActive()
{
	// TODO: �ڴ����ר�ô����/����û���
	CPropertySheet *psheet = (CPropertySheet*)GetParent();
	psheet->SetWizardButtons(PSWIZB_BACK|PSWIZB_FINISH);

	return CPropertyPage::OnSetActive();
}
