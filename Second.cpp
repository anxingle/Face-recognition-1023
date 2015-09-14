// Second.cpp : 实现文件
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

// CSecond 对话框

IMPLEMENT_DYNAMIC(CSecond, CPropertyPage)

CSecond::CSecond()
	: CPropertyPage(CSecond::IDD)
{
	m_font.CreatePointFont(200, _T("微软雅黑"));
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


// CSecond 消息处理程序


BOOL CSecond::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类
	CPropertySheet * psheet=(CPropertySheet*)GetParent();
	psheet->SetWizardButtons(PSWIZB_NEXT|PSWIZB_BACK);

	SetDlgItemText(IDC_STATIC,_T("请将面部朝向摄像头"));

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
	AfxMessageBox(_T("无法打开摄像头"));
	return 0;
	}
	*/
	// 测试

	//初始化系统
	int ccccfdkj = 0;
	if(InitializeRecognizer()==false);
//		AfxMessageBox("初始化失败",MB_OK);

	// 设置计时器,每10ms触发一次事件
	SetTimer(1, 100, NULL);
	//SetTimer(2,100,NULL);
	return CPropertyPage::OnSetActive();
}


void CSecond::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	
	/* 显示摄像头                                                           */
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
		//此处标注 True应根据后期检测来重新定
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
		  {   //如果检测到人脸
			  CvvImage m_CvvImage2;
	          m_CvvImage2.CopyOf(cropface, 1);
		      m_CvvImage2.DrawToHDC(hDC2, &rect2);	         
			  //将cropface图像显示到界面;  同时摄像头画面不更新， 并在m_Frame图像上画出坐标为face_coord的矩形框
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
