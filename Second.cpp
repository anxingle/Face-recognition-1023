// Second.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Recognition.h"
#include "Second.h"
#include "afxdialogex.h"


// CSecond �Ի���

IMPLEMENT_DYNAMIC(CSecond, CPropertyPage)

CSecond::CSecond()
	: CPropertyPage(CSecond::IDD)
{

}

CSecond::~CSecond()
{
}

void CSecond::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSecond, CPropertyPage)
END_MESSAGE_MAP()


// CSecond ��Ϣ�������


BOOL CSecond::OnSetActive()
{
	// TODO: �ڴ����ר�ô����/����û���
	CPropertySheet * psheet=(CPropertySheet*)GetParent();
	psheet->SetWizardButtons(PSWIZB_NEXT|PSWIZB_BACK);

	SetDlgItemText(IDC_STATIC,_T("Who Are U?"));
	return CPropertyPage::OnSetActive();
}
