
// PAI_SimulatorDlg.h : ͷ�ļ�
//

#include "MyDef.h"
#pragma once


// CPAI_SimulatorDlg �Ի���
class CPAI_SimulatorDlg : public CDialogEx
{
// ����
public:
	CPAI_SimulatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PAI_SIMULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

public:
	static UINT __cdecl MyControllingFunction( LPVOID pParam );

private:
	ThreadData data;

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
