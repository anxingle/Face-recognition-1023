#pragma once


// CSecond �Ի���

class CSecond : public CPropertyPage
{
	DECLARE_DYNAMIC(CSecond)

public:
	CSecond();
	virtual ~CSecond();

// �Ի�������
	enum { IDD = IDD_Second };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
