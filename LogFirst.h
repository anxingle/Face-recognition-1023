#pragma once


// CLogFirst dialog

class CLogFirst : public CPropertyPage
{
	DECLARE_DYNAMIC(CLogFirst)

public:
	CLogFirst();
	virtual ~CLogFirst();

// Dialog Data
	enum { IDD = IDD_log_one };
private:
	CFont m_font;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
