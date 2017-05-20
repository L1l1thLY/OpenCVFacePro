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
	CList<CString> nameList;
	CString name;
	CString picPath;
	int nameIsExist();
	DECLARE_MESSAGE_MAP()
};


