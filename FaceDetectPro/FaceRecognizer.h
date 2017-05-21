#pragma once
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/core/core.hpp>  
#include <vector>
#include <face.hpp>


// FaceRecognizer

class FaceRecognizer : public CWnd
{
	DECLARE_DYNAMIC(FaceRecognizer)

public:
	FaceRecognizer(CString nameListPath, CString picturePath);
	virtual ~FaceRecognizer();
protected:
	cv::Ptr<FaceRecognizer> trainModel(void);
	int detectTheFace(void);

	CList<CString> nameList;
	CString picPath;
	CString nameLstPath;

	DECLARE_MESSAGE_MAP()
};


