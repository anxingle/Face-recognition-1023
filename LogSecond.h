#pragma once


// CLogSecond dialog

class CLogSecond : public CPropertyPage
{
	DECLARE_DYNAMIC(CLogSecond)

public:
	CLogSecond();
	virtual ~CLogSecond();
private:
	CFont m_font;
	CString instr[5];
public:
	int index;
	int instr_num;
// Dialog Data
	enum { IDD = IDD_log_two };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
