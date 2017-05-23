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
	CString trainDataPath;                  //人脸数据库
	CString nameListPath;					//名字数据库

	cv::Ptr<cv::face::FaceRecognizer> trainModelFromDir(void);          //训练并返回一个指向人脸识别模型的指针

	int RecognizeFaceByModel(cv::Ptr<cv::face::FaceRecognizer> model);  //使用模型进行人脸识别

	void getFiles(std::string path, std::vector<std::string>& files);

	CString picPath;

	DECLARE_MESSAGE_MAP()
};


