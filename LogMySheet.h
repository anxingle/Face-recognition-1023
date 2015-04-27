#pragma once
#include "LogFirst.h"
#include "LogSecond.h"


// CLogMySheet

class CLogMySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CLogMySheet)

public:
	CLogMySheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CLogMySheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CLogMySheet();

private:
	CLogFirst m_first;
	CLogSecond m_second;
	//CThird m_third;
protected:
	DECLARE_MESSAGE_MAP()

};


