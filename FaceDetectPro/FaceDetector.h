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
	CList<CString> nameList;        //����������ȡ���ֿ⽫���������
	CString name;					//��View�㴫�������ֽ����������
	CString picPath;				//��View�㴫����·����������
	CString nameLstPath;			//RT
	int nameIsExist();				//�ж������Ƿ����
	int processAndCopy();			//����ͼƬ���������ݿ�
	CString getFileFullName(CString csFilePath);	//ͨ��·���õ��ļ�ȫ��
	DECLARE_MESSAGE_MAP()
};


