#pragma once


// CSecond 对话框

class CSecond : public CPropertyPage
{
	DECLARE_DYNAMIC(CSecond)

public:
	CSecond();
	virtual ~CSecond();

// 对话框数据
	enum { IDD = IDD_Second };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CFont m_font;
public:
	virtual BOOL OnSetActive();
//	afx_msg void OnBnClickedOpen();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
