
// PAI_Simulator.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPAI_SimulatorApp:
// �йش����ʵ�֣������ PAI_Simulator.cpp
//

class CPAI_SimulatorApp : public CWinApp
{
public:
	CPAI_SimulatorApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPAI_SimulatorApp theApp;