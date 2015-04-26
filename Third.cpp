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
	ON_BN_CLICKED(IDC_BUTTON3, &CThird::OnBnClickedButton3)
	ON_WM_TIMER()
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



	return CPropertyPage::OnSetActive();
}


void CThird::OnBnClickedButton1()
{
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
}


void CThird::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	if (!capture_2)
	{
		capture_2 = cvCaptureFromCAM(0);
		//AfxMessageBox("OK");  
	}

	if (!capture_2)
	{
		AfxMessageBox(_T("无法打开摄像头"));
		return;
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
}


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
