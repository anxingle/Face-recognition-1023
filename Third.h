#pragma once


// CThird �Ի���

class CThird : public CPropertyPage
{
	DECLARE_DYNAMIC(CThird)

public:
	CThird();
	virtual ~CThird();

// �Ի�������
	enum { IDD = IDD_Third };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
