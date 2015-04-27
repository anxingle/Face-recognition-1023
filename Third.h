#pragma once
#include "afxwin.h"
#include <string.h>

// CThird 对话框

class CThird : public CPropertyPage
{
	DECLARE_DYNAMIC(CThird)

public:
	CThird();
	virtual ~CThird();
private:
	CFont m_font;
// 对话框数据
	enum { IDD = IDD_Third };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	CStatic m_myPan;
	/*
    string idp[3];
	idp[0] = "IDB_BITMAP1";
	idp[1] = "IDB_BITMAP2";
	idp[2] = "IDB_BITMAP3";   
	char idpic[6][12] = {"IDB_BITMAP1","IDB_BITMAP2","IDB_BITMAP3","IDB_BITMAP4","IDB_BITMAP5","IDB_BITMAP"};
	*/
	afx_msg void OnBnClickedButton1();
	//CString pan[3];
	int index;
	//CStringArray asp;

	// char idp[3][12] = {"IDB_BITMAP1","IDB_BITMAP2","IDB_BITMAP3"};
//	afx_msg void OnBnClickedButton3();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnStnClickedPic3();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
