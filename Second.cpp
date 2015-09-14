// Second.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Recognition.h"
#include "Second.h"
#include "afxdialogex.h"
#include "CvvImage.h"
#include "FaceRetrieve_Video.h"

CvCapture* capture;
CRect rect;
CDC *pDC;
HDC hDC;
CWnd *pwnd;

CRect rect2;
CDC *pDC2;
HDC hDC2;
CWnd *pwnd2;

// CSecond �Ի���

IMPLEMENT_DYNAMIC(CSecond, CPropertyPage)

CSecond::CSecond()
	: CPropertyPage(CSecond::IDD)
{
	m_font.CreatePointFont(200, _T("΢���ź�"));
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
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CSecond ��Ϣ�������


BOOL CSecond::OnSetActive()
{
	// TODO: �ڴ����ר�ô����/����û���
	CPropertySheet * psheet=(CPropertySheet*)GetParent();
	psheet->SetWizardButtons(PSWIZB_NEXT|PSWIZB_BACK);

	SetDlgItemText(IDC_STATIC,_T("�뽫�沿��������ͷ"));

	pwnd = GetDlgItem(IDC_PIC);
	pDC = pwnd->GetDC();
	hDC = pDC->GetSafeHdc();
	pwnd->GetClientRect(&rect);

	pwnd2 = GetDlgItem(IDC_PIC2);
	pDC2 = pwnd2->GetDC();
	hDC2 = pDC2->GetSafeHdc();
	pwnd2->GetClientRect(&rect2);
	//capture = cvCaptureFromFile("1.AVI");
	capture = cvCaptureFromCAM(0);
	// TODO: Add your control notification handler code here
	/*8if (!capture)
	{
	capture = cvCaptureFromCAM(0);
	//AfxMessageBox("OK");
	}
	if (!capture)
	{
	AfxMessageBox(_T("�޷�������ͷ"));
	return 0;
	}
	*/
	// ����

	//��ʼ��ϵͳ
	int ccccfdkj = 0;
	if(InitializeRecognizer()==false);
//		AfxMessageBox("��ʼ��ʧ��",MB_OK);

	// ���ü�ʱ��,ÿ10ms����һ���¼�
	SetTimer(1, 100, NULL);
	//SetTimer(2,100,NULL);
	return CPropertyPage::OnSetActive();
}


void CSecond::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	
	/* ��ʾ����ͷ                                                           */
	/************************************************************************/
	//IplImage* m_Frame;
	//m_Frame = cvQueryFrame(capture);

	/*	
	char* imagePath="1_big.jpg";
	IplImage* m_Frame=cvLoadImage(imagePath,0);

	CvvImage m_CvvImage;
	m_CvvImage.CopyOf(m_Frame, 1);
	if (true)
	{
		m_CvvImage.DrawToHDC(hDC, &rect);
	}
	*/
		IplImage* m_Frame;
		m_Frame = cvQueryFrame(capture);
		CvvImage m_CvvImage;
		m_CvvImage.CopyOf(m_Frame, 1);
	//if(nIDEvent == 1){
		//�˴���ע TrueӦ���ݺ��ڼ�������¶�
		if(true)
		{
			m_CvvImage.DrawToHDC(hDC, &rect);
			//cvWaitKey(10);  
		}
	
	//}
	//else{  //
	float detect_ratio=0.2;
	IplImage *cropface=cvCreateImage(cvSize(120,170),m_Frame->depth,m_Frame->nChannels);
		  Coord *face_coord=new Coord[1];
	      face_coord[0].top=0;
          face_coord[0].bottom=0;
          face_coord[0].left=0;
	      face_coord[0].right=0;
		  
          bool det_flag=Face_detection(m_Frame, detect_ratio, face_coord, cropface);
	      if(det_flag==false)
	      {	
		    cvReleaseImage(&cropface);
		    delete []face_coord;
		   // continue;
	      }
		 else
		  {   //�����⵽����
			  CvvImage m_CvvImage2;
	          m_CvvImage2.CopyOf(cropface, 1);
		      m_CvvImage2.DrawToHDC(hDC2, &rect2);	         
			  //��cropfaceͼ����ʾ������;  ͬʱ����ͷ���治���£� ����m_Frameͼ���ϻ�������Ϊface_coord�ľ��ο�
		  }
	//}
		  CPropertyPage::OnTimer(nIDEvent);
}


HBRUSH CSecond::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CPropertyPage::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	if (pWnd->GetDlgCtrlID() == IDC_second_first)
		pDC->SelectObject(&m_font);
	// TODO:  Return a different brush if the default is not desired
	return hbr;
}
