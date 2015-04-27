// LogSecond.cpp : implementation file
//

#include "stdafx.h"
#include "Recognition.h"
#include "LogSecond.h"
#include "afxdialogex.h"
#include "CvvImage.h"

CvCapture* capture_3;
CRect rect_3;
CDC *pDC_3;
HDC hDC_3;
CWnd *pwnd_3;


// CLogSecond dialog

IMPLEMENT_DYNAMIC(CLogSecond, CPropertyPage)

CLogSecond::CLogSecond()
	: CPropertyPage(CLogSecond::IDD)
{
	index = 0;
	instr_num = 0;
	m_font.CreatePointFont(200, _T("微软雅黑"));
	instr[0] = _T("请眨左眼");
	instr[1] = _T("请眨右眼");
	instr[2] = _T("请张嘴");
	instr[3] = _T("请闭眼");
	instr[4] = _T("请微笑");
}

CLogSecond::~CLogSecond()
{
}

void CLogSecond::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLogSecond, CPropertyPage)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CLogSecond message handlers


BOOL CLogSecond::OnSetActive()
{
	// TODO: Add your specialized code here and/or call the base class
	// TODO: 在此添加专用代码和/或调用基类
	CPropertySheet *psheet = (CPropertySheet*)GetParent();
	psheet->SetWizardButtons(PSWIZB_BACK | PSWIZB_FINISH);

	pwnd_3 = GetDlgItem(IDC_logPIC);
	//pwnd->MoveWindow(35,30,352,288);  
	pDC_3 = pwnd_3->GetDC();
	//pDC =GetDC();  
	hDC_3 = pDC_3->GetSafeHdc();
	pwnd_3->GetClientRect(&rect_3);
	// 这些程序用来显示摄像头
	if (!capture_3)
	{
		capture_3 = cvCaptureFromCAM(0);
		//AfxMessageBox("OK");  
	}

	if (!capture_3)
	{
		AfxMessageBox(_T("无法打开摄像头"));
		return 0;
	}

	// 测试  
	IplImage* m_Frame;
	m_Frame = cvQueryFrame(capture_3);
	CvvImage m_CvvImage;
	m_CvvImage.CopyOf(m_Frame, 1);
	if (true)
	{
		m_CvvImage.DrawToHDC(hDC_3, &rect_3);
		//cvWaitKey(10);  
	}

	// 设置计时器,每10ms触发一次事件  
	SetTimer(1, 10, NULL);


	return CPropertyPage::OnSetActive();
	return CPropertyPage::OnSetActive();
}


void CLogSecond::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	/* 显示摄像头                                                           */
	/************************************************************************/
	IplImage* m_Frame;
	m_Frame = cvQueryFrame(capture_3);
	CvvImage m_CvvImage;
	m_CvvImage.CopyOf(m_Frame, 1);
	if (true)
	{
		m_CvvImage.DrawToHDC(hDC_3, &rect_3);
		//cvWaitKey(10);  
	}
	CPropertyPage::OnTimer(nIDEvent);
}


HBRUSH CLogSecond::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CPropertyPage::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	if (pWnd->GetDlgCtrlID() == IDC_logsecond_first)
	{
		pDC->SelectObject(&m_font);
		//pDC->SetWindow
	}
	// TODO:  Return a different brush if the default is not desired
	return hbr;
}
