
// PAI_SimulatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PAI_Simulator.h"
#include "PAI_SimulatorDlg.h"
#include "afxdialogex.h"

#include "MyDef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CPAI_SimulatorDlg 对话框




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


// CPAI_SimulatorDlg 消息处理程序

BOOL CPAI_SimulatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标



	// TODO: 在此添加额外的初始化代码
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CPAI_SimulatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CWindowDC dc(this);
		dc.MoveTo(ORG_X, ORG_Y);

		dc.Rectangle(ORG_X, ORG_Y, ORG_X+EDGE, ORG_Y+EDGE);
		dc.Ellipse(ORG_X, ORG_Y, ORG_X+EDGE, ORG_Y+EDGE);

		CString str;
		str = L"π≈";
		AfxGetMainWnd()->GetDlgItem(IDT_TEXT)->SetWindowText(str);
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CPAI_SimulatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPAI_SimulatorDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void CPAI_SimulatorDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnCancel();
}


void CPAI_SimulatorDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	DestroyWindow();
	CDialogEx::OnClose();
}


void CPAI_SimulatorDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	PostQuitMessage(0);
}


void CPAI_SimulatorDlg::OnClickedBtnSimulate()
{
	//接收数据
	UpdateData();
	data.iCount = m_iAmount;
	//如果绘图线程未运行则新建线程
	if(!data.bRunning)
	{
		//重绘刷新客户区
		AfxGetMainWnd()->PostMessage(WM_PAINT);
		//设置线程正在运行标记
		data.bRunning = TRUE;
		//开始绘图线程
		AfxBeginThread(MyControllingFunction, (LPVOID)&data);
	}
	
}

UINT __cdecl CPAI_SimulatorDlg::MyControllingFunction( LPVOID pParam )
{
	CWindowDC dc(AfxGetMainWnd());
	
	srand(time(NULL));

	int iAmount = ((ThreadData*)pParam)->iCount;//总共需要的点数
	int iSum = 0;//园内点的总数
	int x, y;
	int i = 0;
	for(i=0; i < iAmount; i++)
	{
		//EDGE defined in MyDef.h
		x = rand()%EDGE;
		y = rand()%EDGE;
		dc.SetPixel(ORG_X+x, ORG_Y+y, RGB(0,0,0));

		//坐标转换成以圆心为原点
		x -= EDGE/2;
		y -= EDGE/2;

		//在园内则计数加1
		if(x*x + y*y <= EDGE*EDGE/4)
			iSum++;

		Sleep(1);
	}
	CString str;
	double dSum = 1.0 * iSum / iAmount * 4;
	str.Format(L"π≈%.15lf", dSum);
	AfxGetMainWnd()->GetDlgItem(IDT_TEXT)->SetWindowText(str);	//设置文本框

	((ThreadData*)pParam)->bRunning = FALSE;
	return 0;
}