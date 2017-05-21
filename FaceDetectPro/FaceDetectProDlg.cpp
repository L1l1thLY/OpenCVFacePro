
// FaceDetectProDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "resource.h"
#include "FaceDetectPro.h"
#include "FaceDetectProDlg.h"
#include "afxdialogex.h"
#include "FaceDetector.h"
#include "MyFaceRecognizer.h"
#include <iostream>
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/core/core.hpp> 


using namespace cv;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFaceDetectProDlg �Ի���



CFaceDetectProDlg::CFaceDetectProDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FACEDETECTPRO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFaceDetectProDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFaceDetectProDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CFaceDetectProDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CFaceDetectProDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE1, &CFaceDetectProDlg::OnEnChangeMfceditbrowse1)
	ON_EN_CHANGE(IDC_EDIT2, &CFaceDetectProDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CFaceDetectProDlg ��Ϣ�������

BOOL CFaceDetectProDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CFaceDetectProDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFaceDetectProDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CFaceDetectProDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFaceDetectProDlg::OnBnClickedOk() {
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString selectedPath;
	GetDlgItemText(IDC_MFCEDITBROWSE1, selectedPath);
	MyFaceRecognizer aFaceRcgnr(selectedPath);
	if (selectedPath.IsEmpty()) {
		MessageBox(TEXT("��������ȷ��·��������"), TEXT("ERROR"), MB_ICONINFORMATION);
		return;
	}
	else {
		aFaceRcgnr.Hello();
	}
	//CDialogEx::OnOK();
}



void CFaceDetectProDlg::OnBnClickedButton1() {

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString selectedPath;
	GetDlgItemText(IDC_MFCEDITBROWSE1, selectedPath);
	CString nameOfFace;
	GetDlgItemText(IDC_EDIT2, nameOfFace);
	CString targetPath("D:\\FacesData\\TrainData");
	CString nameListPath("D:\\FacesData\\NameLog.txt");
	//MessageBox((LPCTSTR)nameOfFace, (LPCTSTR)selectedPath, MB_ICONQUESTION);
	if (selectedPath.IsEmpty() || nameOfFace.IsEmpty()) {
		MessageBox(TEXT("��������ȷ��·��������"), TEXT("ERROR"), MB_ICONINFORMATION);
		return;
	}
	else {
		FaceDetector aFaced(nameListPath,nameOfFace,selectedPath);
		aFaced.Hello();
	}


}


void CFaceDetectProDlg::OnEnChangeMfceditbrowse1() {
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CFaceDetectProDlg::OnEnChangeEdit2() {
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
