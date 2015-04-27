// Third.cpp : 实现文件
//

#include "stdafx.h"
#include "Recognition.h"
#include "Third.h"
#include "afxdialogex.h"
//#include <string>
#include "CvvImage.h"

CvCapture* capture_2;
CRect rect_2;
CDC *pDC_2;
HDC hDC_2;
CWnd *pwnd_2;


// CThird 对话框

IMPLEMENT_DYNAMIC(CThird, CPropertyPage)

CThird::CThird()
	: CPropertyPage(CThird::IDD)
{/*
	pan[0] = _T("IDB_BITMAP1");  // IDB_BITMAP1
	pan[1] = "IDB_BITMAP2";
	pan[2] = "IDB_BITMAP3";
	*/
	index = 0;
	instr_num = 0;
	m_font.CreatePointFont(200, _T("微软雅黑"));
	instr[0] =_T("请眨左眼");
	instr[1] = _T("请眨右眼");
	instr[2] = _T("请张嘴");
	instr[3] = _T("请闭眼");
	instr[4] = _T("请微笑");
	}

CThird::~CThird()
{
}

void CThird::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC3, m_myPan);
}


BEGIN_MESSAGE_MAP(CThird, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON1, &CThird::OnBnClickedButton1)
//	ON_BN_CLICKED(IDC_BUTTON3, &CThird::OnBnClickedButton3)
	ON_WM_TIMER()
	ON_STN_CLICKED(IDC_PIC3, &CThird::OnStnClickedPic3)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CThird 消息处理程序


BOOL CThird::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类
	CPropertySheet *psheet = (CPropertySheet*)GetParent();
	psheet->SetWizardButtons(PSWIZB_BACK|PSWIZB_FINISH);

	pwnd_2 = GetDlgItem(IDC_PIC2);
	//pwnd->MoveWindow(35,30,352,288);  
	pDC_2 = pwnd_2->GetDC();
	//pDC =GetDC();  
	hDC_2 = pDC_2->GetSafeHdc();
	pwnd_2->GetClientRect(&rect_2);
	// 这些程序用来显示摄像头
	if (!capture_2)
	{
		capture_2 = cvCaptureFromCAM(0);
		//AfxMessageBox("OK");  
	}

	if (!capture_2)
	{
		AfxMessageBox(_T("无法打开摄像头"));
		return 0;
	}

	// 测试  
	IplImage* m_Frame;
	m_Frame = cvQueryFrame(capture_2);
	CvvImage m_CvvImage;
	m_CvvImage.CopyOf(m_Frame, 1);
	if (true)
	{
		m_CvvImage.DrawToHDC(hDC_2, &rect_2);
		//cvWaitKey(10);  
	}

	// 设置计时器,每10ms触发一次事件  
	SetTimer(1, 10, NULL);


	return CPropertyPage::OnSetActive();
}


void CThird::OnBnClickedButton1()
{
	instr_num++;
	if (instr_num == 5)
		instr_num = 0;
	SetDlgItemText(IDC_third_first,instr[instr_num]);
	/*
	// TODO: Add your control notification handler code here
	CBitmap   bitmap;
	HBITMAP hBmp;
//	char* panpan=(LPSTR)(LPCTSTR)pan[0];
//	CBitmap panc = (CBitmap)panpan;
	index++;
	if (index == 7)
		index = 0;
	bitmap.LoadBitmapW(IDB_BITMAP1+index);

	hBmp = (HBITMAP)bitmap.GetSafeHandle();
	m_myPan.SetBitmap(hBmp);
	*/
}


//void CThird::OnBnClickedButton3()
//{
//	// TODO: Add your control notification handler code here
//	if (!capture_2)
//	{
//		capture_2 = cvCaptureFromCAM(0);
//		//AfxMessageBox("OK");  
//	}
//
//	if (!capture_2)
//	{
//		AfxMessageBox(_T("无法打开摄像头"));
//		return;
//	}
//
//	// 测试  
//	IplImage* m_Frame;
//	m_Frame = cvQueryFrame(capture_2);
//	CvvImage m_CvvImage;
//	m_CvvImage.CopyOf(m_Frame, 1);
//	if (true)
//	{
//		m_CvvImage.DrawToHDC(hDC_2, &rect_2);
//		//cvWaitKey(10);  
//	}
//
//	// 设置计时器,每10ms触发一次事件  
//	SetTimer(1, 10, NULL);
//}


void CThird::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	/* 显示摄像头                                                           */
	/************************************************************************/
	IplImage* m_Frame;
	m_Frame = cvQueryFrame(capture_2);
	CvvImage m_CvvImage;
	m_CvvImage.CopyOf(m_Frame, 1);
	if (true)
	{
		m_CvvImage.DrawToHDC(hDC_2, &rect_2);
		//cvWaitKey(10);  
	}
	CPropertyPage::OnTimer(nIDEvent);
}


void CThird::OnStnClickedPic3()
{
	// TODO: Add your control notification handler code here
}


HBRUSH CThird::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CPropertyPage::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	if (pWnd->GetDlgCtrlID() == IDC_third_first)
	{
		pDC->SelectObject(&m_font);
		//pDC->SetWindow
	}
		// TODO:  Return a different brush if the default is not desired
	return hbr;
}
