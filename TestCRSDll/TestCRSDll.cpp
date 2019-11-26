#include "TestCRSDll.h"
#include <QDebug>

#define LOG qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"

TestCRSDll::TestCRSDll(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	strList << "CRS_GetErrorCode" << "CRS_GetDeviceInfo" << "CRS_MonitorDeviceStatus" << "CRS_SetDAQCallbackFunc" << "CRS_InitDevice" << "CRS_ConnectDevice"
		<< "CRS_CloseDevice" << "CRS_LoadCodeToDevice" << "CRS_StartBroadcast" << "CRS_StopBroadcast" << "CRS_SetCRSParams" << "CRS_SetAWGBiases"
		<< "CRS_SetDDSCommand" << "CRS_SetFIRCommand" << "CRS_SetDAQParams" << "CRS_SetASGDefauleLevel" << "CRS_ASGPulseDownload" << "CRS_ADCENSignalDownload"
		<< "CRS_SetDDSAWGMode" << "CRS_StartDDSBroadcast" << "CRS_SetTDDCallbackFunc" << "CRS_TDCDownloadCalibration" << "CRS_SetTDCParams" << "CRS_SetClockSource" 
		<< "CRS_SetStatusCallback" << "CRS_SetTDCCallbackFunc" << "AWG" << "DDS" << "ASG" << "DAQ" << "TDC";

	initUI();

	this->setFixedSize(this->size());
	//Open with PyCharm Community Edition
}

void TestCRSDll::initUI() {
	QVBoxLayout *vLayout = new QVBoxLayout(ui.widget);
	size_t index = 0;
	for (index = 0; index < 6; index++) {
		QPushButton *button = new QPushButton();
		button->setText(strList.at(index));
		button->setObjectName(strList.at(index));
		//button->setGeometry(200 * index, 0, 200, 30);
		connect(button, &QPushButton::clicked, this, &TestCRSDll::onAllPushButton);
		vLayout->addWidget(button);
	}

	QVBoxLayout *vLayout2 = new QVBoxLayout(ui.widget_2);
	for (; index < 12; index++) {
		QPushButton *button = new QPushButton();
		button->setText(strList.at(index));
		button->setObjectName(strList.at(index));
		connect(button, &QPushButton::clicked, this, &TestCRSDll::onAllPushButton);
		vLayout2->addWidget(button);
	}

	QVBoxLayout *vLayout3 = new QVBoxLayout(ui.widget_3);
	for (; index < 18; index++) {
		QPushButton *button = new QPushButton();
		button->setText(strList.at(index));
		button->setObjectName(strList.at(index));
		connect(button, &QPushButton::clicked, this, &TestCRSDll::onAllPushButton);
		vLayout3->addWidget(button);
	}

	QVBoxLayout *vLayout4 = new QVBoxLayout(ui.widget_4);
	for (; index < 24; index++) {
		QPushButton *button = new QPushButton();
		button->setText(strList.at(index));
		button->setObjectName(strList.at(index));
		connect(button, &QPushButton::clicked, this, &TestCRSDll::onAllPushButton);
		vLayout4->addWidget(button);
	}

	QVBoxLayout *vLayout5 = new QVBoxLayout(ui.widget_5);
	for (; index < strList.length(); index++) {
		QPushButton *button = new QPushButton();
		button->setText(strList.at(index));
		button->setObjectName(strList.at(index));
		connect(button, &QPushButton::clicked, this, &TestCRSDll::onAllPushButton);
		vLayout5->addWidget(button);
	}
}

void TestCRSDll::onStatus_Callback(int e) {
	LOG << "STATUS_CALLBACK:" << e;
}

void TestCRSDll::onDAQ_Callback(int type, char* data) {
	LOG << "DAQ_CALLBACK:" << type;
	LOG << data;
}

void TestCRSDll::onTDC_Callback(int grp, int countC, int countF) {
	LOG << "onTDC_Callback" << grp << countC << countF;
}


void TestCRSDll::onAllPushButton() {
	QPushButton *button = qobject_cast<QPushButton *>(sender());
	QString name = button->objectName();
	LOG << name;
	if (name == strList.at(0)) {
		int result = CRS_GetErrorCode();
		LOG << result;
	}
	else if (name == strList.at(1))
	{
		char *result = CRS_GetDeviceInfo();
		LOG << result;
	}
	else if (name == strList.at(2))
	{
		BOOL result = CRS_MonitorDeviceStatus();
		LOG << result;
	}
	else if (name == strList.at(3))
	{
		BOOL result = CRS_SetDAQCallbackFunc(onDAQ_Callback);
		LOG << result;
	}
	else if (name == strList.at(4))
	{
		BOOL result = CRS_InitDevice();
		LOG << result;
	}
	else if (name == strList.at(5))
	{
		BOOL result = CRS_ConnectDievce();
		LOG << result;
	}
	else if (name == strList.at(6))
	{
		BOOL result = CRS_CloseDevice();
		LOG << result;
	}
	else if (name == strList.at(7))
	{
		const char *code = "";
		BOOL result = CRS_LoadCodeToDevice(code);
		LOG << result;
	}
	else if (name == strList.at(8))
	{
		unsigned int numRepeat = 4294967295;
		LOG << "最小值：" << (std::numeric_limits<unsigned int>::min)() << "最大值：" << (std::numeric_limits<unsigned int>::max)();
		BOOL result = CRS_StartBroadcast(numRepeat);
		LOG << result;
	}
	else if (name == strList.at(9))
	{
		BOOL result = CRS_StopBroadcast();
		LOG << result;
	}
	else if (name == strList.at(10))
	{
		LOG << "最小值：" << (std::numeric_limits<unsigned short>::min)() << "最大值：" << (std::numeric_limits<unsigned short>::max)();
		Params params;
		params.isContinuous = 0;
		params.broadcastMode = 65535;
		params.isDDSModeOpen = 0;
		params.isDAQModeOpen = 0;
		params.isAWGModeOpen = 0;
		for (int i = 0; i < 8; i++) {
			params.ASGChannelState[i] = 65535;
		}
		BOOL result = CRS_SetCRSParams(params);
		LOG << result;
	}
	else if (name == strList.at(11))
	{
		unsigned short ch1bias = 65535;
		unsigned short cha2bias = 65535;
		LOG << "最小值：" << (std::numeric_limits<unsigned short>::min)() << "最大值：" << (std::numeric_limits<unsigned short>::max)();
		BOOL result = CRS_SetAWGBiases(ch1bias, cha2bias);
		LOG << result;
	}
	else if (name == strList.at(12))
	{
		//CRS_SetDDSCommand()
	}
	else if (name == strList.at(13))
	{
		//CRS_SetFIRCommand()
	}
	else if (name == strList.at(14))
	{
		//-2147483648, 2147483647
		short positionAdjustment1 = 2147483647;
		short positionAdjustment2 = 2147483647;
		LOG << "最小值：" << (std::numeric_limits<int>::min)() << "最大值：" << (std::numeric_limits<int>::max)();
		BOOL result = CRS_SetDAQParams(positionAdjustment1, positionAdjustment2);
		LOG << result;
	}
	else if (name == strList.at(15))
	{
		unsigned char defaultLevel = 0xff;
		BOOL result = CRS_SetASGDefauleLevel(defaultLevel);
		LOG << result;
	}
	else if (name == strList.at(16))
	{
		LOG << "最小值：" << (std::numeric_limits<unsigned short>::min)() << "最大值：" << (std::numeric_limits<unsigned short>::max)();
		//double **pulses;
		//int length[8][8];//length[][8]
		//unsigned short* loop;
		//unsigned short segmentNum;

		int pulsesLen[8] = { 10, 10, 10, 10, 12, 10, 12, 10 };
		double **pulses;
		double pulses_1[10] = { 0, 20, 20, 20, 0, 100, 300, 220, 40, 40 };
		*(pulses + 0) = pulses_1;
		double pulses_2[10] = { 0, 20, 20, 20, 100, 100, 200, 220, 40, 40 };
		*(pulses + 1) = pulses_2;
		double pulses_3[10] = { 0, 20, 20, 20, 0, 100, 300, 220, 40, 40 };
		*(pulses + 2) = pulses_3;
		double pulses_4[10] = { 0, 20, 20, 20, 100, 100, 200, 220, 40, 40 };
		*(pulses + 3) = pulses_4;
		double pulses_5[12] = { 0, 20, 20, 20, 0, 100, 100, 200, 200, 20, 40, 40 };
		*(pulses + 4) = pulses_5;
		double pulses_6[10] = { 0, 20, 20, 20, 100, 300, 200, 20, 40, 40 };
		*(pulses + 5) = pulses_6;
		double pulses_7[12] = { 0, 20, 20, 20, 0, 100, 100, 200, 200, 20, 40, 40 };
		*(pulses + 6) = pulses_7;
		double pulses_8[10] = { 0, 20, 20, 20, 100, 300, 200, 20, 40, 40 };
		*(pulses + 7) = pulses_8;
		int length[3][8] = {
			{ 4, 4, 4, 4, 4, 4, 4, 4 },
			{ 4, 4, 4, 4, 6, 4, 6, 4 },
			{ 2, 2, 2, 2, 2, 2, 2, 2 }
		};
		unsigned short loop[3] = { 1, 4, 2 };
		unsigned short segmentNum = 3;

		BOOL result = CRS_ASGPulseDownload(pulses, length, loop, segmentNum);
		LOG << result;
	}
	else if (name == strList.at(17))
	{
		LOG << "最小值：" << (std::numeric_limits<long long>::min)() << "最大值：" << (std::numeric_limits<long long>::max)();
		LOG << "最小值：" << (std::numeric_limits<int>::min)() << "最大值：" << (std::numeric_limits<int>::max)();
		LOG << "最小值：" << (std::numeric_limits<unsigned short>::min)() << "最大值：" << (std::numeric_limits<unsigned short>::max)();
		//long long* enableSignal;
		//int* length;
		//unsigned short* loop;
		//unsigned short segmentNum;

		long long enableSignal[6] = { 100, 100, 200, 20000, 40, 50000 };
		int length[2] = { 4, 2 };
		unsigned short loop[2] = { 4, 2 };
		unsigned short segmentNum = 2;

		BOOL result = CRS_ADCENSignalDownload(enableSignal, length, loop, segmentNum);
		LOG << result;
	}
	else if (name == strList.at(18))
	{
		double frequencyChannel1 = 1.79769e+308;//1.79769e+308
		double frequencyChannel2 = 1.79769e+308;
		double phaseChannel1 = 1.79769e+308;
		double phaseChannel2 = 1.79769e+308;
		unsigned short amplitudeValue1 = 65535; // 65535
		unsigned short amplitudeValue2 = 65535;
		short biasChannel1 = 32767;//32767
		short biasChannel2 = 32767;
		LOG << "最小值：" << (std::numeric_limits<double>::min)() << "最大值：" << (std::numeric_limits<double>::max)();
		LOG << "最小值：" << (std::numeric_limits<unsigned short>::min)() << "最大值：" << (std::numeric_limits<unsigned short>::max)();
		LOG << "最小值：" << (std::numeric_limits<short>::min)() << "最大值：" << (std::numeric_limits<short>::max)();
		BOOL result = CRS_SetDDSAWGMode(frequencyChannel1, frequencyChannel2, phaseChannel1, phaseChannel2,
			amplitudeValue1, amplitudeValue2, biasChannel1, biasChannel2);
		LOG << result;
	}
	else if (name == strList.at(19))
	{
		BOOL result = CRS_StartDDSBroadcast();
		LOG << result;
	}
	else if (name == strList.at(20))
	{
		BOOL result = CRS_SetDAQCallbackFunc(onDAQ_Callback);
		LOG << result;
	}
	else if (name == strList.at(21))
	{
		unsigned char data[4][200];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 200; j++) {
				data[i][j] = 0x80;
			}
		}
		BOOL result = CRS_TDCDownloadCalibration(data);
		LOG << result;
	}
	else if (name == strList.at(22))
	{
		LOG << "最小值：" << (std::numeric_limits<unsigned int>::min)() << "最大值：" << (std::numeric_limits<unsigned int>::max)();
		LOG << "最小值：" << (std::numeric_limits<int>::min)() << "最大值：" << (std::numeric_limits<int>::max)();
		unsigned int grp1Length = 4294967295;
		unsigned int grp2Length = 4294967295;
		bool grp1Sw = 1;
		bool grp2Sw = 1;
		int grp1Mode = 2147483647;
		int grp2Mode = 2147483647;//2147483647
		BOOL result = CRS_SetTDCParams(grp1Length, grp2Length,
			grp1Sw, grp2Sw, grp1Mode, grp2Mode);
		LOG << result;
	}
	else if (name == strList.at(23))
	{
		LOG << "最小值：" << (std::numeric_limits<int>::min)() << "最大值：" << (std::numeric_limits<int>::max)();
		int src = -2147483648; //2147483647
		BOOL result = CRS_SetClockSource(src);
		LOG << result;
	}
	else if (name == strList.at(24)) {
		BOOL reslut = CRS_SetStatusCallback(onStatus_Callback);
		LOG << reslut;
	}
	else if (name == strList.at(25)) {
		CRS_SetTDCCallbackFunc(onTDC_Callback);
		LOG << "CRS_SetTDCCallbackFunc" << "无返回值";
	}
	else
	{
		doIntegrationFunc(name);
	}
}

/************************************************************************/
/* 整合操作方法
/*
/* 流程：
/* AWG: CRS_InitDevice -> CRS_ConnectDievce -> CRS_SetCRSParams(启用AWG，关闭DDS) -> CRS_SetAWGBiases -> CRS_LoadCodeToDevice -> CRS_StartBroadcast -> CRS_StopBroadcast
/* DDS: CRS_InitDevice -> CRS_ConnectDievce -> CRS_SetCRSParams(启用DDS，关闭AWG) -> CRS_SetDDSAWGMode -> CRS_StartDDSBroadcast -> CRS_StopBroadcast
/* ASG: CRS_InitDevice -> CRS_ConnectDievce -> CRS_SetCRSParams -> CRS_SetASGDefauleLevel(不一定要设置) -> CRS_ASGPulseDownload -> CRS_StartBroadcast -> CRS_StopBroadcast
/* DAQ: CRS_InitDevice -> CRS_ConnectDievce -> CRS_SetCRSParams(启用DAQ，SDK内部会关闭TDC) -> CRS_SetDAQParams(可以不设置) -> CRS_SetDAQCallbackFunc -> CRS_SetStatusCallback -> CRS_ADCENSignalDownload -> CRS_StartBroadcast -> CRS_StopBroadcast
/* TDC: CRS_InitDevice -> CRS_ConnectDievce -> CRS_TDCDownloadCalibration -> CRS_SetTDCParams(启用TDC，SDK自动关闭DAQ) -> CRS_SetTDCCallbackFunc -> CRS_SetStatusCallback -> CRS_StartBroadcast -> CRS_StopBroadcast
/************************************************************************/
void TestCRSDll::doIntegrationFunc(QString name) {
	//"AWG" << "DDS" << "ASG" << "DAQ" << "TDC"
	LOG << name;
	int resultInt;
	BOOL resultBool;
	resultBool = CRS_InitDevice();
	LOG << "CRS_InitDevice:" << resultBool;
	resultBool = CRS_ConnectDievce();
	LOG << "CRS_ConnectDievce:" << resultBool;
	if (name == strList.at(26)) 
	{
		onAWG();
	}
	else if (name == strList.at(27)) 
	{
		onDDS();
	}
	else if (name == strList.at(28)) 
	{
		onASG();
	} 
	else if (name == strList.at(29))
	{
		onDAQ();
	}
	else if (name == strList.at(30)) 
	{
		onTDC();
	}
	else
	{
		LOG << "无方法？";
	}

}

void TestCRSDll::onAWG() {
	BOOL resultBool;
	Params p;
	p.isContinuous = 1;
	p.broadcastMode = 0;
	p.isDDSModeOpen = 0;
	p.isAWGModeOpen = 1;
	p.isDAQModeOpen = 0;
	for (int i = 0; i < 8; ++i)
	{
		p.ASGChannelState[i] = 0;
	}
	resultBool = CRS_SetCRSParams(p);
	LOG << "CRS_SetCRSParams:" << resultBool;
	unsigned short ch1bias = 65535;
	unsigned short cha2bias = 65535;
	resultBool = CRS_SetAWGBiases(ch1bias, cha2bias);
	LOG << "CRS_SetAWGBiases:" << resultBool;

	//todo:: 这里读.cw文件，用户更具自己的需求修改
	QFile file("E:\\project\\CPP\\TestCRSDll\\TestCRSDll\\example-add.cw");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;

	QString content;
	QTextStream in(&file);
	in.setCodec("UTF-8");
	while (!in.atEnd())
	{
		QString line = in.readLine();
		content.append(line + "\n");
	}
	file.close();

	QByteArray bArray = content.toLatin1();
	LOG << "code:" << content;
	resultBool = CRS_LoadCodeToDevice(content.toLatin1().data());
	LOG << "CRS_LoadCodeToDevice:" << resultBool;
	unsigned int numRepeat = 4294967295;
	resultBool = CRS_StartBroadcast(numRepeat);
	LOG << "CRS_StartBroadcast:" << resultBool;
	//resultBool = CRS_StopBroadcast();
	//LOG << "CRS_StopBroadcast:" << resultBool;
}

void TestCRSDll::onDDS() {
	BOOL resultBool;
	Params p;
	p.isContinuous = 1;
	p.broadcastMode = 0;
	p.isDDSModeOpen = 0;
	p.isAWGModeOpen = 1;
	p.isDAQModeOpen = 0;
	for (int i = 0; i < 8; ++i)
	{
		p.ASGChannelState[i] = 0;
	}
	resultBool = CRS_SetCRSParams(p);
	LOG << "CRS_SetCRSParams:" << resultBool;
	double frequencyChannel1 = 1000;//1.79769e+308
	double frequencyChannel2 = 1000;
	double phaseChannel1 = 1;
	double phaseChannel2 = 1;
	unsigned short amplitudeValue1 = 0; // 65535
	unsigned short amplitudeValue2 = 0;
	short biasChannel1 = -32768;//32767
	short biasChannel2 = -32768;
	resultBool = CRS_SetDDSAWGMode(frequencyChannel1, frequencyChannel2, phaseChannel1, phaseChannel2,
		amplitudeValue1, amplitudeValue2, biasChannel1, biasChannel2);
	LOG << "CRS_SetDDSAWGMode:" << resultBool;
	resultBool = CRS_StartDDSBroadcast();
	LOG << "CRS_StartDDSBroadcast:" << resultBool;
	//resultBool = CRS_StopBroadcast();
	//LOG << "CRS_StopBroadcast:" << resultBool;
}

void TestCRSDll::onASG() {
	BOOL resultBool;
	Params p;
	p.isContinuous = 1;
	p.broadcastMode = 0;
	p.isDDSModeOpen = 0;
	p.isAWGModeOpen = 1;
	p.isDAQModeOpen = 0;
	for (int i = 0; i < 8; ++i)
	{
		p.ASGChannelState[i] = 0;
	}
	resultBool = CRS_SetCRSParams(p);
	LOG << "CRS_SetCRSParams:" << resultBool;
	resultBool = CRS_SetASGDefauleLevel(0x80);	// 不一定每次都需要设置
	LOG << "CRS_SetASGDefauleLevel:" << resultBool;

	int pulsesLen[8] = { 10, 10, 10, 10, 12, 10, 12, 10 };
	double **pulses;
	double pulses_1[10] = { 0, 20, 20, 20, 0, 100, 300, 220, 40, 40 };
	*(pulses + 0) = pulses_1;
	double pulses_2[10] = { 0, 20, 20, 20, 100, 100, 200, 220, 40, 40 };
	*(pulses + 1) = pulses_2;
	double pulses_3[10] = { 0, 20, 20, 20, 0, 100, 300, 220, 40, 40 };
	*(pulses + 2) = pulses_3;
	double pulses_4[10] = { 0, 20, 20, 20, 100, 100, 200, 220, 40, 40 };
	*(pulses + 3) = pulses_4;
	double pulses_5[12] = { 0, 20, 20, 20, 0, 100, 100, 200, 200, 20, 40, 40 };
	*(pulses + 4) = pulses_5;
	double pulses_6[10] = { 0, 20, 20, 20, 100, 300, 200, 20, 40, 40 };
	*(pulses + 5) = pulses_6;
	double pulses_7[12] = { 0, 20, 20, 20, 0, 100, 100, 200, 200, 20, 40, 40 };
	*(pulses + 6) = pulses_7;
	double pulses_8[10] = { 0, 20, 20, 20, 100, 300, 200, 20, 40, 40 };
	*(pulses + 7) = pulses_8;
	int length[3][8] = {
		{ 4, 4, 4, 4, 4, 4, 4, 4 },
		{ 4, 4, 4, 4, 6, 4, 6, 4 },
		{ 2, 2, 2, 2, 2, 2, 2, 2 }
	};
	unsigned short loop[3] = { 1, 4, 2 };
	unsigned short segmentNum = 3;

	resultBool = CRS_ASGPulseDownload(pulses, length, loop, segmentNum);
	LOG << "CRS_ASGPulseDownload:" << resultBool;
	unsigned int numRepeat = 4294967295;
	resultBool = CRS_StartBroadcast(numRepeat);
	LOG << "CRS_StartBroadcast:" << resultBool;
	//resultBool = CRS_StopBroadcast();
	//LOG << "CRS_StopBroadcast:" << resultBool;
}

void TestCRSDll::onDAQ() {
	BOOL resultBool;
	Params p;
	p.isContinuous = 1;
	p.broadcastMode = 0;
	p.isDDSModeOpen = 0;
	p.isAWGModeOpen = 1;
	p.isDAQModeOpen = 0;
	for (int i = 0; i < 8; ++i)
	{
		p.ASGChannelState[i] = 0;
	}
	resultBool = CRS_SetCRSParams(p);
	LOG << "CRS_SetCRSParams:" << resultBool;
	short positionAdjustment1 = 2147483647;
	short positionAdjustment2 = 2147483647;
	resultBool = CRS_SetDAQParams(positionAdjustment1, positionAdjustment2);	// 可以不设
	LOG << "CRS_SetDAQParams:" << resultBool;
	resultBool = CRS_SetDAQCallbackFunc(onDAQ_Callback);
	LOG << "CRS_SetDAQCallbackFunc:" << resultBool;
	resultBool = CRS_SetStatusCallback(onStatus_Callback);
	LOG << "CRS_SetStatusCallback:" << resultBool;

	long long enableSignal[6] = { 100, 100, 200, 20000, 40, 50000 };
	int length[2] = { 4, 2 };
	unsigned short loop[2] = { 4, 2 };
	unsigned short segmentNum = 2;
	BOOL result = CRS_ADCENSignalDownload(enableSignal, length, loop, segmentNum);
	LOG << result;

	unsigned int numRepeat = 4294967295;
	resultBool = CRS_StartBroadcast(numRepeat);
	LOG << "CRS_StartBroadcast:" << resultBool;
	//resultBool = CRS_StopBroadcast();
	//LOG << "CRS_StopBroadcast:" << resultBool;
}

void TestCRSDll::onTDC() {
	BOOL resultBool;
	unsigned char data[4][200];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 200; j++) {
			data[i][j] = 0x80;
		}
	}
	resultBool = CRS_TDCDownloadCalibration(data);
	LOG << "CRS_TDCDownloadCalibration" << resultBool;
	unsigned int grp1Length = 4294967295;
	unsigned int grp2Length = 4294967295;
	bool grp1Sw = 1;
	bool grp2Sw = 1;
	int grp1Mode = 2147483647;
	int grp2Mode = 2147483647;//2147483647
	resultBool = CRS_SetTDCParams(grp1Length, grp2Length,
		grp1Sw, grp2Sw, grp1Mode, grp2Mode);
	LOG << resultBool;
	CRS_SetTDCCallbackFunc(onTDC_Callback);
	resultBool = CRS_SetStatusCallback(onStatus_Callback);
	LOG << "CRS_SetStatusCallback:" << resultBool;
	unsigned int numRepeat = 4294967295;
	resultBool = CRS_StartBroadcast(numRepeat);
	LOG << "CRS_StartBroadcast:" << resultBool;
	//resultBool = CRS_StopBroadcast();
	//LOG << "CRS_StopBroadcast:" << resultBool;
}





