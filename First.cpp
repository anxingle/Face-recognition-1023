// First.cpp : 实现文件
//

#include "stdafx.h"
#include "Recognition.h"
#include "First.h"
#include "afxdialogex.h"


// CFirst 对话框

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


// CFirst 消息处理程序


BOOL CFirst::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类
	// 获得父窗口 CProperty类  
	CPropertySheet * psheet=(CPropertySheet*)GetParent();
	psheet->SetWizardButtons(PSWIZB_NEXT);

	return CPropertyPage::OnSetActive();
}
