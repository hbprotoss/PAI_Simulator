
// PAI_SimulatorDlg.h : 头文件
//

#include "MyDef.h"
#pragma once


// CPAI_SimulatorDlg 对话框
class CPAI_SimulatorDlg : public CDialogEx
{
// 构造
public:
	CPAI_SimulatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_PAI_SIMULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

public:
	static UINT __cdecl MyControllingFunction( LPVOID pParam );

private:
	ThreadData data;

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	int m_iAmount;
	afx_msg void OnClickedBtnSimulate();
};
