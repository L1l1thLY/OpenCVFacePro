#pragma once

#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/core/core.hpp>  
#include <vector>
#include <face.hpp>

// MyFaceRecognizer

class MyFaceRecognizer : public CWnd
{
	DECLARE_DYNAMIC(MyFaceRecognizer)

public:
	MyFaceRecognizer(CString picPath);
	void Hello(void);
	virtual ~MyFaceRecognizer();

protected:
	CList<CString> nameList;
	CString trainDataPath;
	CString nameListPath;
	cv::Ptr<cv::face::FaceRecognizer> trainModelFromDir(void);
	int RecognizeFaceByModel(cv::Ptr<cv::face::FaceRecognizer> model);
	void getFiles(std::string path, std::vector<std::string>& files);

	CString picPath;

	DECLARE_MESSAGE_MAP()
};


