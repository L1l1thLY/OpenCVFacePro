// FaceRecognizer.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FaceDetectPro.h"
#include "FaceRecognizer.h"


// FaceRecognizer

IMPLEMENT_DYNAMIC(FaceRecognizer, CWnd)

FaceRecognizer::FaceRecognizer(CString nameListPath, CString picturePath)
{
	CStdioFile nameListFile;
	CString line;
	nameListFile.Open(nameListPath.GetBuffer(0), CFile::modeRead);

	while (nameListFile.ReadString(line)) {
		nameList.AddTail(line);
	}
	picPath = picturePath;
	nameLstPath = nameListPath;
}

FaceRecognizer::~FaceRecognizer()
{
}

cv::Ptr<FaceRecognizer> trainModel(void);


BEGIN_MESSAGE_MAP(FaceRecognizer, CWnd)
END_MESSAGE_MAP()



// FaceRecognizer ��Ϣ�������


