#pragma once


// CFirst 对话框

class CFirst : public CPropertyPage
{
	DECLARE_DYNAMIC(CFirst)

public:
	CFirst();
	virtual ~CFirst();

// 对话框数据
	enum { IDD = IDD_First };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
