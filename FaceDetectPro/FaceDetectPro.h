
// FaceDetectPro.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFaceDetectProApp: 
// �йش����ʵ�֣������ FaceDetectPro.cpp
//

class CFaceDetectProApp : public CWinApp
{
public:
	CFaceDetectProApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFaceDetectProApp theApp;
