// Second.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Recognition.h"
#include "Second.h"
#include "afxdialogex.h"
#include "CvvImage.h"

CvCapture* capture;
CRect rect;
CDC *pDC;
HDC hDC;
CWnd *pwnd;

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
//	ON_BN_CLICKED(IDC_OPEN, &CSecond::OnBnClickedOpen)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CSecond ��Ϣ�������


BOOL CSecond::OnSetActive()
{
	// TODO: �ڴ����ר�ô����/����û���
	CPropertySheet * psheet=(CPropertySheet*)GetParent();
	psheet->SetWizardButtons(PSWIZB_NEXT|PSWIZB_BACK);

	SetDlgItemText(IDC_STATIC,_T("�뽫�沿��������ͷ"));


	pwnd = GetDlgItem(IDC_PIC);
	//pwnd->MoveWindow(35,30,352,288);  
	pDC = pwnd->GetDC();
	//pDC =GetDC();  
	hDC = pDC->GetSafeHdc();
	pwnd->GetClientRect(&rect);
	
	// TODO: Add your control notification handler code here
	if (!capture)
	{
	capture = cvCaptureFromCAM(0);
	//AfxMessageBox("OK");
	}

	if (!capture)
	{
	AfxMessageBox(_T("�޷�������ͷ"));
	return 0;
	}

	// ����
	IplImage* m_Frame;
	m_Frame = cvQueryFrame(capture);
	CvvImage m_CvvImage;
	m_CvvImage.CopyOf(m_Frame, 1);
	if (true)
	{
	m_CvvImage.DrawToHDC(hDC, &rect);
	//cvWaitKey(10);
	}

	// ���ü�ʱ��,ÿ10ms����һ���¼�
	SetTimer(1, 10, NULL);
	
	return CPropertyPage::OnSetActive();
}


//void CSecond::OnBnClickedOpen()
//{
//	// TODO: Add your control notification handler code here
//	if (!capture)
//	{
//		capture = cvCaptureFromCAM(0);
//		//AfxMessageBox("OK");  
//	}
//
//	if (!capture)
//	{
//		AfxMessageBox(_T("�޷�������ͷ"));
//		return;
//	}
//
//	// ����  
//	IplImage* m_Frame;
//	m_Frame = cvQueryFrame(capture);
//	CvvImage m_CvvImage;
//	m_CvvImage.CopyOf(m_Frame, 1);
//	if (true)
//	{
//		m_CvvImage.DrawToHDC(hDC, &rect);
//		//cvWaitKey(10);  
//	}
//
//	// ���ü�ʱ��,ÿ10ms����һ���¼�  
//	SetTimer(1, 10, NULL);
//}



void CSecond::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	
	/* ��ʾ����ͷ                                                           */
	/************************************************************************/
	IplImage* m_Frame;
	m_Frame = cvQueryFrame(capture);
	CvvImage m_CvvImage;
	m_CvvImage.CopyOf(m_Frame, 1);
	if (true)
	{
		m_CvvImage.DrawToHDC(hDC, &rect);
		//cvWaitKey(10);  
	}
	CPropertyPage::OnTimer(nIDEvent);
}
