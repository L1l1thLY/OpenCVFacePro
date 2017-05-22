// MyFaceRecognizer.cpp : 实现文件
//

#include "stdafx.h"
#include "FaceDetectPro.h"
#include "MyFaceRecognizer.h"

//#include <stdlib.h>
#include <io.h>

// MyFaceRecognizer

IMPLEMENT_DYNAMIC(MyFaceRecognizer, CWnd)

MyFaceRecognizer::MyFaceRecognizer(CString picturePath)
{
	nameListPath = CString("D:\\FacesData\\NameLog.txt");
	trainDataPath = CString("D:\\FacesData\\TrainData");
	CStdioFile nameListFile;
	CString line;

	//读取名字列表到链表
	nameListFile.Open(nameListPath.GetBuffer(0), CFile::modeRead);

	while (nameListFile.ReadString(line)) {
		nameList.AddTail(line);
	}

	picPath = picturePath;
}

MyFaceRecognizer::~MyFaceRecognizer()
{
}
void MyFaceRecognizer::getFiles(std::string path, std::vector<std::string>& files) {
	intptr_t hFile = 0;
	struct _finddata_t fileinfo;
	std::string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) {
		do {
			if ((fileinfo.attrib &  _A_SUBDIR)) {
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else {
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}


cv::Ptr<cv::face::FaceRecognizer> MyFaceRecognizer::trainModelFromDir(void) {
	std::vector<cv::Mat> images;
	std::vector<int> labels;

	int countOfPeople = nameList.GetCount();

	for (int i = 1; i < countOfPeople + 1 ; i++) {
		CString peopleIndexString = CString();
		peopleIndexString.Format(_T("%d"), i);
		CString pathToSomePeople = trainDataPath + CString("\\P") + peopleIndexString;

		std::string pathToSomePeople_std =  CT2A(pathToSomePeople);
		std::vector<std::string> files;

		getFiles(pathToSomePeople_std, files);

		int size = files.size();

		for (int k = 0; k < size; k++) {
			cv::Mat tempImage = cv::imread(files[k].c_str(), CV_LOAD_IMAGE_GRAYSCALE);
			if (tempImage.empty()) {
				MessageBox(TEXT("出现了一点错误: 没能成功从某个目录获得训练图片"));
			}
			else {
				images.push_back(tempImage); labels.push_back(i);
			}
		}
	}

	cv::Ptr<cv::face::FaceRecognizer> model = cv::face::createFisherFaceRecognizer();

	model->train(images, labels);

	return model;
}

int MyFaceRecognizer::RecognizeFaceByModel(cv::Ptr<cv::face::FaceRecognizer> model) {
	std::string picPath_std = CT2A(picPath);
	cv::Mat picToRcg = cv::imread(picPath_std.c_str(), CV_LOAD_IMAGE_GRAYSCALE);
	if (picToRcg.empty()) {
		MessageBox(TEXT("出现了一点错误：识别图片没能载入"));
		return 0;
	}
	else {
		int predictIndex = model->predict(picToRcg);
		int count = nameList.GetCount();
		//检查整个名单列表判断名字是否已经存在
		POSITION pos = nameList.GetHeadPosition();
		CString name;
		for (int i = 1; i < count + 1; i++) {
			name = nameList.GetNext(pos);
			if (i == predictIndex) {
				MessageBox(TEXT("我的名字是：")+name);
				return i; //如果存在，返回此名字在名单中的序号
			}
		}
		
	}
}

void MyFaceRecognizer::Hello(void) {
	cv::Ptr<cv::face::FaceRecognizer> model = MyFaceRecognizer::trainModelFromDir();
	RecognizeFaceByModel(model);
}


BEGIN_MESSAGE_MAP(MyFaceRecognizer, CWnd)
END_MESSAGE_MAP()



// MyFaceRecognizer 消息处理程序


