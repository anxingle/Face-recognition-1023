#pragma once
#include "afxwin.h"


// CThird 对话框

class CThird : public CPropertyPage
{
	DECLARE_DYNAMIC(CThird)

public:
	CThird();
	virtual ~CThird();

// 对话框数据
	enum { IDD = IDD_Third };
//	CBrush m_brBk;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
//	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CStatic m_myPan;
	afx_msg void OnBnClickedReload();
};
