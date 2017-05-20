// FaceDetector.cpp : 实现文件
//

#include "stdafx.h"
#include "FaceDetectPro.h"
#include "FaceDetector.h"


// FaceDetector

IMPLEMENT_DYNAMIC(FaceDetector, CWnd)

FaceDetector::FaceDetector(CString nameListPath, CString newName,CString picturePath)
{
	CStdioFile nameListFile;
	CString line;
	nameListFile.Open(nameListPath.GetBuffer(0), CFile::modeRead);
	//while (nameListFile.ReadString(line)) {
	//	Hello(line);
	//}
	while (nameListFile.ReadString(line)) {
		nameList.AddTail(line);
	}
	name = newName;
	picPath = picturePath;
}

FaceDetector::~FaceDetector()
{
}

int FaceDetector::Hello() {
	int count = nameList.GetCount();
	POSITION pos = nameList.GetHeadPosition();
	for (int i = 0; i < count; i++) {
		CString tempString = nameList.GetNext(pos);
		MessageBox(tempString.GetBuffer(0));
	}
	nameIsExist();
	MessageBox(picPath);

	return 0;
}

//Private
int FaceDetector::nameIsExist() {
	int count = nameList.GetCount();
	POSITION pos = nameList.GetHeadPosition();
	for (int i = 0; i < count; i++) {
		if (name == nameList.GetNext(pos)) {
			MessageBox(TEXT("存在！"));
			return 1;
		}
	}
	MessageBox(TEXT("不存在！"));
	return 0;
}
BEGIN_MESSAGE_MAP(FaceDetector, CWnd)
END_MESSAGE_MAP()



// FaceDetector 消息处理程序


