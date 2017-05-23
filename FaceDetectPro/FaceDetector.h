#pragma once


// FaceDetector

class FaceDetector : public CWnd
{
	DECLARE_DYNAMIC(FaceDetector)

public:
	FaceDetector(CString nameListPath,CString newName,CString picturePath);
	virtual ~FaceDetector();
	int Hello();

protected:
	CList<CString> nameList;        //名字链表，读取名字库将会存在这里
	CString name;					//从View层传来的名字将会存在这里
	CString picPath;				//从View层传来的路径存在这里
	CString nameLstPath;			//RT
	int nameIsExist();				//判断名字是否存在
	int processAndCopy();			//处理图片并存入数据库
	CString getFileFullName(CString csFilePath);	//通过路径得到文件全名
	DECLARE_MESSAGE_MAP()
};


