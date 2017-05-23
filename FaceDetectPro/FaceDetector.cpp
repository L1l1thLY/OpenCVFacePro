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
	nameLstPath = nameListPath;
}

FaceDetector::~FaceDetector()
{
}

int FaceDetector::Hello() {
	//测试代码 打印名字库所有名字
	//int count = nameList.GetCount();
	//POSITION pos = nameList.GetHeadPosition();
	//for (int i = 0; i < count; i++) {
	//	CString tempString = nameList.GetNext(pos);
	//	MessageBox(tempString.GetBuffer(0));
	//}
	//测试代码 显示名字是否存在；
	//nameIsExist();
	//测试代码 显示选择路径
	//MessageBox(picPath);

	processAndCopy();
	return 0;
}

//Private
//工具方法：得到文件名
CString FaceDetector::getFileFullName(CString csFilePath) {
	int nPos = csFilePath.ReverseFind('\\'); // 文件路径，以'\'斜杠分隔的路径  
	CString csFileFullName;
	csFileFullName = csFilePath.Right(csFilePath.GetLength() - nPos - 1); // 获取文件全名，包括文件名和扩展名  
	return csFileFullName;
}

//
int FaceDetector::processAndCopy() {
	int peopleIndex;                    //序号

	CString fileName = getFileFullName(picPath);  

	CString trainDirPath = CString("D:\\FacesData\\TrainData\\P");

	if (peopleIndex = nameIsExist()) {
		CString peopleIndexString;
		peopleIndexString.Format(_T("%d"), peopleIndex);

		CString targetPath = trainDirPath + peopleIndexString + CString("\\")+ fileName;
		//复制文件
		if (CopyFile(picPath.GetBuffer(0),targetPath.GetBuffer(0),TRUE)) {
			MessageBox(TEXT("导入成功"));
			return 1;
		}else{
			MessageBox(TEXT("文件已存在，导入失败！"));
			return 0;
		}

	}
	else {
		int newPeopleIndex = nameList.GetCount() + 1;
		CString peopleIndexString;
		peopleIndexString.Format(_T("%d"), newPeopleIndex);

		//应为新人创造一个新的人脸数据文件夹
		CString newDirString = trainDirPath + peopleIndexString;
		CreateDirectory(newDirString.GetBuffer(0), NULL);

		CString targetPath = trainDirPath + peopleIndexString + CString("\\") +fileName;
		if (CopyFile(picPath.GetBuffer(0), targetPath.GetBuffer(0), TRUE)) {
			MessageBox(TEXT("导入成功"));

			//将新人名写入列表
			CStdioFile nameListFile;
			nameListFile.Open(nameLstPath.GetBuffer(0), CFile::modeWrite);
			nameListFile.SeekToEnd();
			nameListFile.WriteString(CString("\n")+name);
			return 1;
		}
		else {
			MessageBox(TEXT("文件已存在，导入失败！"));
			return 0;
		}
	}
	return 0;
}

int FaceDetector::nameIsExist() {
	int count = nameList.GetCount();
	//检查整个名单列表判断名字是否已经存在
	POSITION pos = nameList.GetHeadPosition();
	for (int i = 1; i < count + 1; i++) {
		if (name == nameList.GetNext(pos)) {
			MessageBox(TEXT("存在！"));
			return i; //如果存在，返回此名字在名单中的序号
		}
	}
	MessageBox(TEXT("不存在！"));
	return 0;
}

BEGIN_MESSAGE_MAP(FaceDetector, CWnd)
END_MESSAGE_MAP()



// FaceDetector 消息处理程序


