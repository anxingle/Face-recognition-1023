// Third.cpp : 实现文件
//

#include "stdafx.h"
#include "Recognition.h"
#include "Third.h"
#include "afxdialogex.h"


// CThird 对话框

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
	DDX_Control(pDX, IDC_SHOW3, m_myPan);
}


BEGIN_MESSAGE_MAP(CThird, CPropertyPage)
//	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_ReLoad, &CThird::OnBnClickedReload)
END_MESSAGE_MAP()


// CThird 消息处理程序


BOOL CThird::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类
	CPropertySheet *psheet = (CPropertySheet*)GetParent();
	psheet->SetWizardButtons(PSWIZB_BACK|PSWIZB_FINISH);


	// 相当于 XXXDlg.cpp 中的OnInitDialog()
	/*
	CBitmap bmp;
	bmp.LoadBitmapW(IDB_BITMAP22);
	m_brBk.CreatePatternBrush(&bmp);
	bmp.DeleteObject();
	*/
	return CPropertyPage::OnSetActive();
}


//HBRUSH CThird::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
//{
//	HBRUSH hbr = CPropertyPage::OnCtlColor(pDC, pWnd, nCtlColor);
//
//	// TODO:  Change any attributes of the DC here
//	if (pWnd == this)
//	{
//		return m_brBk;
//	}
//
//	// TODO:  Return a different brush if the default is not desired
//	return hbr;
//}


void CThird::OnBnClickedReload()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here   
	CBitmap bitmap;  // CBitmap对象，用于加载位图   
	HBITMAP hBmp;    // 保存CBitmap加载的位图的句柄   

	bitmap.LoadBitmap(IDB_BITMAP1);  // 将位图IDB_BITMAP1加载到bitmap   
	hBmp = (HBITMAP)bitmap.GetSafeHandle();  // 获取bitmap加载位图的句柄   
	m_myPan.SetBitmap(hBmp);    // 设置图片控件m_jzmPicture的位图图片为IDB_BITMAP1   
}
