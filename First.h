#pragma once


// CFirst �Ի���

class CFirst : public CPropertyPage
{
	DECLARE_DYNAMIC(CFirst)

public:
	CFirst();
	virtual ~CFirst();

// �Ի�������
	enum { IDD = IDD_First };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
