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
	DDX_Control(pDX, IDC_SHOW3, m_myPan);
}


BEGIN_MESSAGE_MAP(CThird, CPropertyPage)
//	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_ReLoad, &CThird::OnBnClickedReload)
END_MESSAGE_MAP()


// CThird ��Ϣ�������


BOOL CThird::OnSetActive()
{
	// TODO: �ڴ����ר�ô����/����û���
	CPropertySheet *psheet = (CPropertySheet*)GetParent();
	psheet->SetWizardButtons(PSWIZB_BACK|PSWIZB_FINISH);


	// �൱�� XXXDlg.cpp �е�OnInitDialog()
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
	CBitmap bitmap;  // CBitmap�������ڼ���λͼ   
	HBITMAP hBmp;    // ����CBitmap���ص�λͼ�ľ��   

	bitmap.LoadBitmap(IDB_BITMAP1);  // ��λͼIDB_BITMAP1���ص�bitmap   
	hBmp = (HBITMAP)bitmap.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
	m_myPan.SetBitmap(hBmp);    // ����ͼƬ�ؼ�m_jzmPicture��λͼͼƬΪIDB_BITMAP1   
}
