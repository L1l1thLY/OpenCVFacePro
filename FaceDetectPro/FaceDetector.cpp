// FaceDetector.cpp : ʵ���ļ�
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
	//���Դ��� ��ӡ���ֿ���������
	//int count = nameList.GetCount();
	//POSITION pos = nameList.GetHeadPosition();
	//for (int i = 0; i < count; i++) {
	//	CString tempString = nameList.GetNext(pos);
	//	MessageBox(tempString.GetBuffer(0));
	//}
	//���Դ��� ��ʾ�����Ƿ���ڣ�
	//nameIsExist();
	//���Դ��� ��ʾѡ��·��
	//MessageBox(picPath);

	processAndCopy();
	return 0;
}

//Private
//���߷������õ��ļ���
CString FaceDetector::getFileFullName(CString csFilePath) {
	int nPos = csFilePath.ReverseFind('\\'); // �ļ�·������'\'б�ָܷ���·��  
	CString csFileFullName;
	csFileFullName = csFilePath.Right(csFilePath.GetLength() - nPos - 1); // ��ȡ�ļ�ȫ���������ļ�������չ��  
	return csFileFullName;
}

//
int FaceDetector::processAndCopy() {
	int peopleIndex;                    //���

	CString fileName = getFileFullName(picPath);  

	CString trainDirPath = CString("D:\\FacesData\\TrainData\\P");

	if (peopleIndex = nameIsExist()) {
		CString peopleIndexString;
		peopleIndexString.Format(_T("%d"), peopleIndex);

		CString targetPath = trainDirPath + peopleIndexString + CString("\\")+ fileName;
		//�����ļ�
		if (CopyFile(picPath.GetBuffer(0),targetPath.GetBuffer(0),TRUE)) {
			MessageBox(TEXT("����ɹ�"));
			return 1;
		}else{
			MessageBox(TEXT("�ļ��Ѵ��ڣ�����ʧ�ܣ�"));
			return 0;
		}

	}
	else {
		int newPeopleIndex = nameList.GetCount() + 1;
		CString peopleIndexString;
		peopleIndexString.Format(_T("%d"), newPeopleIndex);

		//ӦΪ���˴���һ���µ����������ļ���
		CString newDirString = trainDirPath + peopleIndexString;
		CreateDirectory(newDirString.GetBuffer(0), NULL);

		CString targetPath = trainDirPath + peopleIndexString + CString("\\") +fileName;
		if (CopyFile(picPath.GetBuffer(0), targetPath.GetBuffer(0), TRUE)) {
			MessageBox(TEXT("����ɹ�"));

			//��������д���б�
			CStdioFile nameListFile;
			nameListFile.Open(nameLstPath.GetBuffer(0), CFile::modeWrite);
			nameListFile.SeekToEnd();
			nameListFile.WriteString(CString("\n")+name);
			return 1;
		}
		else {
			MessageBox(TEXT("�ļ��Ѵ��ڣ�����ʧ�ܣ�"));
			return 0;
		}
	}
	return 0;
}

int FaceDetector::nameIsExist() {
	int count = nameList.GetCount();
	//������������б��ж������Ƿ��Ѿ�����
	POSITION pos = nameList.GetHeadPosition();
	for (int i = 1; i < count + 1; i++) {
		if (name == nameList.GetNext(pos)) {
			MessageBox(TEXT("���ڣ�"));
			return i; //������ڣ����ش������������е����
		}
	}
	MessageBox(TEXT("�����ڣ�"));
	return 0;
}

BEGIN_MESSAGE_MAP(FaceDetector, CWnd)
END_MESSAGE_MAP()



// FaceDetector ��Ϣ�������


