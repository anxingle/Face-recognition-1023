#pragma once
#include "afxwin.h"


// CThird �Ի���

class CThird : public CPropertyPage
{
	DECLARE_DYNAMIC(CThird)

public:
	CThird();
	virtual ~CThird();

// �Ի�������
	enum { IDD = IDD_Third };
//	CBrush m_brBk;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
//	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CStatic m_myPan;
	afx_msg void OnBnClickedReload();
};
