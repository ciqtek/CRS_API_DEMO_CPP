// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� CRS_SDK_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// CRS_SDK_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef CRS_SDK_EXPORTS
#define CRS_SDK_API __declspec(dllexport)
#else
#define CRS_SDK_API __declspec(dllimport)
#endif

#include <Windows.h>


//���ڴ洢�����Ľṹ�壬�Է�ֹ���ֲ���������ܳ��ֵ�����
struct Params
{
    BOOL isContinuous; //AWG���β��ţ�1�������Ų��ܿ��ƣ�0��ʹ���źſ���
    unsigned short broadcastMode; //����ģʽ��1 trigger���ţ�0 ��������
    BOOL isDDSModeOpen; //DDSģʽ�����رգ�1������0�ر�        //ע��DDSģʽ��AWGģʽ����
    BOOL isDAQModeOpen; //DAQģʽ�����رգ�1������0�ر�
    BOOL isAWGModeOpen; //AWGģʽ�����رգ�1������0�ر�        //ע��DDSģʽ��AWGģʽ����
    //unsigned short collectionMode; //�ɼ�����ģʽ
    unsigned short ASGChannelState[8]; //ASG8��ͨ������� //ʾ��[0,1,1,1,0,0,1,1], 1��������0����ر�
    //unsigned short biasChannel1; //AWGͨ��1��ƫ��
    //unsigned short biasChannel2; //AWGͨ��2��ƫ��
};


#ifdef __cplusplus
extern "C"
{
#endif
    // 
    typedef void(*STATUS_CALLBACK)(int e);

    CRS_SDK_API BOOL CRS_SetStatusCallback(STATUS_CALLBACK func);

    // DAQ ���ݻص���������
    typedef void(*DAQ_CALLBACK)(int type, char* data);

    /*************************************************
    **Function:         CRS_GetErrorCode
    **Description:      ��ȡ SDK ʹ�ù����еĴ�����
    **Output:
    **Return:           int, ��Ӧ����ö������Ĵ�������
    **Others:
    *************************************************/
    CRS_SDK_API int CRS_GetErrorCode();

    /*************************************************
    **Function:         CRS_GetDeviceInfo
    **Description:      ��ȡ�豸������Ϣ����json��ʽ�ַ�������
    **Output:
    **Return:           char*
    **Others:           �������豸�ɹ�ʱ, �ḽ���豸��Ϣ, ��δ����ʱ, �᷵�ص��� SDK ��Ϣ
    *************************************************/
    CRS_SDK_API char* CRS_GetDeviceInfo();

    /*************************************************
    **Function: 		CRS_MonitorDeviceStatus
    **Description:		����豸״̬
    **Output:
    **Return: 			BOOL TRUE�����豸���ߣ�FALSE��ʾ��������
    **Others:
    *************************************************/
    CRS_SDK_API BOOL CRS_MonitorDeviceStatus();

    /*************************************************
    **Function: 		CRS_SetCallBackFun
    **Description:		��ȡDAQ���ص�����
    **Input: 			DATA_CALLBACK func
    **Output:			
    **Return: 			BOOL TRUE������ִ�гɹ���FALSE��ʾ����ִ��ʧ��
    **Others:			��DAQ�򿪵�ʱ�򣬿�ʼ���ţ������Ի�ȡ��������
    *************************************************/
    CRS_SDK_API BOOL CRS_SetDAQCallbackFunc(DAQ_CALLBACK func);

    /*************************************************
    **Function: 		CRS_InitDevice
    **Description:		��ʼ���豸
    **Output:			
    **Return: 			BOOL TRUE������ִ�гɹ���FALSE��ʾ����ִ��ʧ��
    **Others:			
    *************************************************/
    CRS_SDK_API BOOL CRS_InitDevice();

    /*************************************************
    **Function: 		CRS_ConnectDievce
    **Description:		�����豸
    **Output:			
    **Return: 			BOOL TRUE������ִ�гɹ���FALSE��ʾ����ִ��ʧ��
    **Others:			
    *************************************************/
    CRS_SDK_API BOOL CRS_ConnectDievce();

    /*************************************************
    **Function: 		CRS_CloseDevice
    **Description:		�ر��豸
    **Output:			
    **Return: 			BOOL TRUE������ִ�гɹ���FALSE��ʾ����ִ��ʧ��
    **Others:			
    *************************************************/
    CRS_SDK_API BOOL CRS_CloseDevice();

    /*************************************************
    **Function: 		CRS_LoadCodeToDevice
    **Description:		�������
    **Input: 			const char * code ǰ�˵Ĵ������
    **Output:
    **Return: 			BOOL TRUE������ִ�гɹ���FALSE��ʾ����ִ��ʧ��
    **Others:
    *************************************************/
    CRS_SDK_API BOOL CRS_LoadCodeToDevice(const char* code);

    /*************************************************
    **Function:         CRS_StartBroadcast
    **Description:      ��ʼ����
    **Input: 	        unsigned int numRepeat �����ظ�����
    **Output:
    **Return: 	        BOOL TRUE������ִ�гɹ���FALSE��ʾ����ִ��ʧ��
    **Others:
    *************************************************/
    CRS_SDK_API BOOL CRS_StartBroadcast(unsigned int numRepeat);

    /*************************************************
    **Function: 		CRS_StopBroadcast
    **Description:		ֹͣ����
    **Output:			
    **Return: 			BOOL TRUE������ִ�гɹ���FALSE��ʾ����ִ��ʧ��
    **Others:			
    *************************************************/
    CRS_SDK_API BOOL CRS_StopBroadcast();

    /*********************************** �������ز��� *********************************/
    /*************************************************
    **Function:         CRS_SetDDSCommand
    **Description:      ���������±�Ƶ��DDS�Ŀ���ָ��
    **Input: 	        double frequency DDSƵ�ʿ�����
    **Input: 	        double phase DDS��ʼ��λ
    **Output:
    **Return: 	        BOOL TRUE������ִ�гɹ���FALSE��ʾ����ִ��ʧ��
    **Others:
    *************************************************/
    //CRS_SDK_API BOOL CRS_SetDDSCommand(double frequency, double phase);

    /*************************************************
    **Function: CRS_SetFIRCommand
    **Description: ����FIR�˲������õĿ���ָ��
    **Input: 	unsigned short type �˲�������ѡ��
    **Output:
    **Return: 	BOOL TRUE������ִ�гɹ���FALSE��ʾ����ִ��ʧ��
    **Others:
    *************************************************/
    //CRS_SDK_API BOOL CRS_SetFIRCommand(unsigned short type);

    /*************************************************
    **Function:         CRS_SetDAQParams
    **Description:      ��DAQ�Ĳ�����������
    **Input: 	        short positionAdjustment ADC�ɼ��źŵ�ƫ�õ���
    **Output:
    **Return: 	        BOOL TRUE������ִ�гɹ���FALSE��ʾ����ִ��ʧ��
    **Others:
    *************************************************/
    CRS_SDK_API BOOL CRS_SetDAQParams(short positionAdjustment1, short positionAdjustment2);

    //************************************
    // Method:    CRS_SetASGDefauleLevel
    // FullName:  CRS_SetASGDefauleLevel
    // Access:    public 
    // Returns:   CRS_SDK_API BOOL
    // Qualifier:
    // Parameter: unsigned char defaultLevel, 8��ͨ��Ĭ�ϵ�ƽ��1��0��
    //************************************
    CRS_SDK_API BOOL CRS_SetASGDefauleLevel(unsigned char defaultLevel);

    /*************************************************
    **Function: CRS_ASGPulseDownload
    **Description: ASG������ݵ�����
    **Input: 	pulses 8��ͨ������������
    **Input: 	length ÿ��ͨ�������ݳ���
    **Output:
    **Return: 	TRUE������ִ�гɹ���FALSE��ʾ����ִ��ʧ��
    **Others:   ������4��������
    *************************************************/
    CRS_SDK_API BOOL CRS_ASGPulseDownload(double **pulses, int length[][8], unsigned short* loop, unsigned short segmentNum);

    /*************************************************
    **Function: 		CRS_ADCENSignalDownload
    **Description:		����ADCʹ���ź�
    **Input: 			long long * enableSignal ʹ���ź�
    **Input: 			int* length ʹ���ź����ݳ���
    **Input: 			unsigned short * loop ÿ��segment�ظ�����
    **Input: 			unsigned short segmentNum ÿ��
    **Output:			
    **Return: 			CRS_SDK_API BOOL
    **Others:			
    *************************************************/
    CRS_SDK_API BOOL CRS_ADCENSignalDownload(long long* enableSignal, int* length, unsigned short* loop, unsigned short segmentNum);

    /*************************************************
    **Function:         CRS_SetDDSAWGMode
    **Description:      DDSģʽAWG����ָ��
    **Input: 	        double frequencyChannel1 ͨ��1��DDSƵ�ʿ�����
    **Input: 	        double frequencyChannel2 ͨ��2��DDSƵ�ʿ�����
    **Input: 	        double phaseChannel1 ͨ��1��DDS��ʼ��λ
    **Input: 	        double phaseChannel2 ͨ��2��DDS��ʼ��λ
    **Input: 	        unsigned short amplitudeValue1 ͨ��1����������
    **Input: 	        unsigned short amplitudeValue2 ͨ��2����������
    **Input: 	        short biasChannel1 ͨ��1��ƫ������
    **Input: 	        short biasChannel2 ͨ��2��ƫ������
    **Output:
    **Return: 	        BOOL TRUE������ִ�гɹ���FALSE��ʾ����ִ��ʧ��
    **Others:
    *************************************************/
    CRS_SDK_API BOOL CRS_SetDDSAWGMode(double frequencyChannel1, double frequencyChannel2, double phaseChannel1, double phaseChannel2,
        unsigned short amplitudeValue1, unsigned short amplitudeValue2, short biasChannel1, short biasChannel2);

    /*************************************************
    **Function: 		CRS_StartDDSBroadcast
    **Description:		��ʼ����DDS
    **Output:			
    **Return: 			BOOL TRUE������ִ�гɹ���FALSE��ʾ����ִ��ʧ��
    **Others:			
    *************************************************/
    CRS_SDK_API BOOL CRS_StartDDSBroadcast();
    
    /*************************************************
    **Function: 		CRS_AWG_SetParams
    **Description:		���ز���AWG��Ҫ�����ò���
    **Input: 			Params params ����AWG�����Ľṹ��
    **Output:			
    **Return: 			BOOL TRUE������ִ�гɹ���FALSE��ʾ����ִ��ʧ��
    **Others:			
    *************************************************/
    CRS_SDK_API BOOL CRS_SetCRSParams(Params params);

    /*************************************************
    **Function: 		CRS_SetAWGBiases
    **Description:		���� AWG ͨ��ƫ��
    **Input: 			ch1bias, ch2bias OUT1 �� OUT2 ��ƫ��
    **Output:
    **Return: 			BOOL TRUE������ִ�гɹ���FALSE��ʾ����ִ��ʧ��
    **Others:
    *************************************************/
    CRS_SDK_API BOOL CRS_SetAWGBiases(unsigned short ch1bias, unsigned short cha2bias);



    //************************************
    // Type:      TDC_CALLBACK
    // FullName:  DAQ::TDC_CALLBACK
    // Access:    public 
    // Returns:   void
    // Qualifier: 
    // Parameter: int grp       ��� 0: ��һ��, 1: �ڶ���
    // Parameter: int countC    �ּ���
    // Parameter: int countF    ϸ����, ��ʱ�� countC * 4ns + countF * 20ps
    //************************************
    typedef void(*TDC_CALLBACK)(int grp, int countC, int countF);


    //************************************
    // Method:    CRS_SetTDCCallbackFunc
    // FullName:  CRS_SetTDCCallbackFunc
    // Access:    public 
    // Returns:   void
    // Qualifier:
    // Parameter: TDC_CALLBACK func
    //************************************
    CRS_SDK_API void CRS_SetTDCCallbackFunc(TDC_CALLBACK func);

    //************************************
    // Method:    TDC_DownloadCalibratingData
    // FullName:  DAQ::TDC_DownloadCalibratingData
    // Access:    public 
    // Returns:   BOOL
    // Qualifier:
    // Parameter: unsigned char data[4][200] ��ͨ����У׼����
    //************************************
    CRS_SDK_API BOOL CRS_TDCDownloadCalibration(unsigned char data[4][200]);


    //************************************
    // Method:    CRS_SetTDCParams
    // FullName:  CRS_SetTDCParams
    // Access:    public 
    // Returns:   CRS_SDK_API BOOL
    // Qualifier:
    // Parameter: unsigned short grp1Length
    // Parameter: unsigned short grp2Length
    // Parameter: bool grp1Sw
    // Parameter: bool grp2Sw
    // Parameter: int grp1Mode
    // Parameter: int grp2Mode
    //************************************
    CRS_SDK_API BOOL CRS_SetTDCParams(unsigned int grp1Length, unsigned int grp2Length,
        bool grp1Sw, bool grp2Sw, int grp1Mode, int grp2Mode);

    //************************************
    // Method:    CRS_SetClockSource
    // FullName:  CRS_SetClockSource
    // Access:    public 
    // Returns:   CRS_SDK_API BOOL
    // Qualifier:
    // Parameter: int src, 0: �ڲ�ʱ�ӣ�1: �ⲿʱ��
    //************************************
    CRS_SDK_API BOOL CRS_SetClockSource(int src);

#ifdef __cplusplus
}
#endif
