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
	CString trainDataPath;                  //�������ݿ�
	CString nameListPath;					//�������ݿ�

	cv::Ptr<cv::face::FaceRecognizer> trainModelFromDir(void);          //ѵ��������һ��ָ������ʶ��ģ�͵�ָ��

	int RecognizeFaceByModel(cv::Ptr<cv::face::FaceRecognizer> model);  //ʹ��ģ�ͽ�������ʶ��

	void getFiles(std::string path, std::vector<std::string>& files);

	CString picPath;

	DECLARE_MESSAGE_MAP()
};


