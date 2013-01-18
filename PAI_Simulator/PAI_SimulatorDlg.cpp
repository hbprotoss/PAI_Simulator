
// PAI_SimulatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PAI_Simulator.h"
#include "PAI_SimulatorDlg.h"
#include "afxdialogex.h"

#include "MyDef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPAI_SimulatorDlg �Ի���




CPAI_SimulatorDlg::CPAI_SimulatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPAI_SimulatorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_iAmount = 0;
	data.bRunning = FALSE;
	data.pWnd = NULL;
}

void CPAI_SimulatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDE_AMOUNT, m_iAmount);
}

BEGIN_MESSAGE_MAP(CPAI_SimulatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CPAI_SimulatorDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CPAI_SimulatorDlg::OnBnClickedCancel)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDB_SIMULATE, &CPAI_SimulatorDlg::OnClickedBtnSimulate)
END_MESSAGE_MAP()


// CPAI_SimulatorDlg ��Ϣ�������

BOOL CPAI_SimulatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��



	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CPAI_SimulatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CPAI_SimulatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CWindowDC dc(this);
		dc.MoveTo(ORG_X, ORG_Y);

		dc.Rectangle(ORG_X, ORG_Y, ORG_X+EDGE, ORG_Y+EDGE);
		dc.Ellipse(ORG_X, ORG_Y, ORG_X+EDGE, ORG_Y+EDGE);

		CString str;
		str = L"�С�";
		AfxGetMainWnd()->GetDlgItem(IDT_TEXT)->SetWindowText(str);
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CPAI_SimulatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPAI_SimulatorDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


void CPAI_SimulatorDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnCancel();
}


void CPAI_SimulatorDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	DestroyWindow();
	CDialogEx::OnClose();
}


void CPAI_SimulatorDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	PostQuitMessage(0);
}


void CPAI_SimulatorDlg::OnClickedBtnSimulate()
{
	//��������
	UpdateData();
	data.iCount = m_iAmount;
	//�����ͼ�߳�δ�������½��߳�
	if(!data.bRunning)
	{
		//�ػ�ˢ�¿ͻ���
		AfxGetMainWnd()->PostMessage(WM_PAINT);
		//�����߳��������б��
		data.bRunning = TRUE;
		//��ʼ��ͼ�߳�
		AfxBeginThread(MyControllingFunction, (LPVOID)&data);
	}
	
}

UINT __cdecl CPAI_SimulatorDlg::MyControllingFunction( LPVOID pParam )
{
	CWindowDC dc(AfxGetMainWnd());
	
	srand(time(NULL));

	int iAmount = ((ThreadData*)pParam)->iCount;//�ܹ���Ҫ�ĵ���
	int iSum = 0;//԰�ڵ������
	int x, y;
	int i = 0;
	for(i=0; i < iAmount; i++)
	{
		//EDGE defined in MyDef.h
		x = rand()%EDGE;
		y = rand()%EDGE;
		dc.SetPixel(ORG_X+x, ORG_Y+y, RGB(0,0,0));

		//����ת������Բ��Ϊԭ��
		x -= EDGE/2;
		y -= EDGE/2;

		//��԰���������1
		if(x*x + y*y <= EDGE*EDGE/4)
			iSum++;

		Sleep(1);
	}
	CString str;
	double dSum = 1.0 * iSum / iAmount * 4;
	str.Format(L"�С�%.15lf", dSum);
	AfxGetMainWnd()->GetDlgItem(IDT_TEXT)->SetWindowText(str);	//�����ı���

	((ThreadData*)pParam)->bRunning = FALSE;
	return 0;
}