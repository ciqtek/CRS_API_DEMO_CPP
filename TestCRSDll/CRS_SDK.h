// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 CRS_SDK_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// CRS_SDK_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef CRS_SDK_EXPORTS
#define CRS_SDK_API __declspec(dllexport)
#else
#define CRS_SDK_API __declspec(dllimport)
#endif

#include <Windows.h>


//用于存储参数的结构体，以防止出现参数过多可能出现的问题
struct Params
{
    BOOL isContinuous; //AWG波形播放，1连续播放不受控制，0受使能信号控制
    unsigned short broadcastMode; //播放模式，1 trigger播放，0 连续播放
    BOOL isDDSModeOpen; //DDS模式开启关闭，1开启，0关闭        //注意DDS模式和AWG模式互斥
    BOOL isDAQModeOpen; //DAQ模式开启关闭，1开启，0关闭
    BOOL isAWGModeOpen; //AWG模式开启关闭，1开启，0关闭        //注意DDS模式和AWG模式互斥
    //unsigned short collectionMode; //采集数据模式
    unsigned short ASGChannelState[8]; //ASG8个通道的情况 //示例[0,1,1,1,0,0,1,1], 1代表开启，0代表关闭
    //unsigned short biasChannel1; //AWG通道1的偏置
    //unsigned short biasChannel2; //AWG通道2的偏置
};


#ifdef __cplusplus
extern "C"
{
#endif
    // 
    typedef void(*STATUS_CALLBACK)(int e);

    CRS_SDK_API BOOL CRS_SetStatusCallback(STATUS_CALLBACK func);

    // DAQ 数据回调函数类型
    typedef void(*DAQ_CALLBACK)(int type, char* data);

    /*************************************************
    **Function:         CRS_GetErrorCode
    **Description:      获取 SDK 使用过程中的错误码
    **Output:
    **Return:           int, 对应错误枚举里面的错误类型
    **Others:
    *************************************************/
    CRS_SDK_API int CRS_GetErrorCode();

    /*************************************************
    **Function:         CRS_GetDeviceInfo
    **Description:      获取设备基本信息，以json格式字符串返回
    **Output:
    **Return:           char*
    **Others:           当连接设备成功时, 会附带设备信息, 当未连接时, 会返回单纯 SDK 信息
    *************************************************/
    CRS_SDK_API char* CRS_GetDeviceInfo();

    /*************************************************
    **Function: 		CRS_MonitorDeviceStatus
    **Description:		监控设备状态
    **Output:
    **Return: 			BOOL TRUE代表设备在线，FALSE表示函数离线
    **Others:
    *************************************************/
    CRS_SDK_API BOOL CRS_MonitorDeviceStatus();

    /*************************************************
    **Function: 		CRS_SetCallBackFun
    **Description:		获取DAQ返回的数据
    **Input: 			DATA_CALLBACK func
    **Output:			
    **Return: 			BOOL TRUE代表函数执行成功，FALSE表示函数执行失败
    **Others:			当DAQ打开的时候，开始播放，将可以获取到此数据
    *************************************************/
    CRS_SDK_API BOOL CRS_SetDAQCallbackFunc(DAQ_CALLBACK func);

    /*************************************************
    **Function: 		CRS_InitDevice
    **Description:		初始化设备
    **Output:			
    **Return: 			BOOL TRUE代表函数执行成功，FALSE表示函数执行失败
    **Others:			
    *************************************************/
    CRS_SDK_API BOOL CRS_InitDevice();

    /*************************************************
    **Function: 		CRS_ConnectDievce
    **Description:		连接设备
    **Output:			
    **Return: 			BOOL TRUE代表函数执行成功，FALSE表示函数执行失败
    **Others:			
    *************************************************/
    CRS_SDK_API BOOL CRS_ConnectDievce();

    /*************************************************
    **Function: 		CRS_CloseDevice
    **Description:		关闭设备
    **Output:			
    **Return: 			BOOL TRUE代表函数执行成功，FALSE表示函数执行失败
    **Others:			
    *************************************************/
    CRS_SDK_API BOOL CRS_CloseDevice();

    /*************************************************
    **Function: 		CRS_LoadCodeToDevice
    **Description:		处理代码
    **Input: 			const char * code 前端的代码代码
    **Output:
    **Return: 			BOOL TRUE代表函数执行成功，FALSE表示函数执行失败
    **Others:
    *************************************************/
    CRS_SDK_API BOOL CRS_LoadCodeToDevice(const char* code);

    /*************************************************
    **Function:         CRS_StartBroadcast
    **Description:      开始播放
    **Input: 	        unsigned int numRepeat 播放重复次数
    **Output:
    **Return: 	        BOOL TRUE代表函数执行成功，FALSE表示函数执行失败
    **Others:
    *************************************************/
    CRS_SDK_API BOOL CRS_StartBroadcast(unsigned int numRepeat);

    /*************************************************
    **Function: 		CRS_StopBroadcast
    **Description:		停止播放
    **Output:			
    **Return: 			BOOL TRUE代表函数执行成功，FALSE表示函数执行失败
    **Others:			
    *************************************************/
    CRS_SDK_API BOOL CRS_StopBroadcast();

    /*********************************** 参数下载操作 *********************************/
    /*************************************************
    **Function:         CRS_SetDDSCommand
    **Description:      下载数字下变频的DDS的控制指令
    **Input: 	        double frequency DDS频率控制字
    **Input: 	        double phase DDS初始相位
    **Output:
    **Return: 	        BOOL TRUE代表函数执行成功，FALSE表示函数执行失败
    **Others:
    *************************************************/
    //CRS_SDK_API BOOL CRS_SetDDSCommand(double frequency, double phase);

    /*************************************************
    **Function: CRS_SetFIRCommand
    **Description: 下载FIR滤波器配置的控制指令
    **Input: 	unsigned short type 滤波器参数选择
    **Output:
    **Return: 	BOOL TRUE代表函数执行成功，FALSE表示函数执行失败
    **Others:
    *************************************************/
    //CRS_SDK_API BOOL CRS_SetFIRCommand(unsigned short type);

    /*************************************************
    **Function:         CRS_SetDAQParams
    **Description:      对DAQ的参数进行设置
    **Input: 	        short positionAdjustment ADC采集信号的偏置调节
    **Output:
    **Return: 	        BOOL TRUE代表函数执行成功，FALSE表示函数执行失败
    **Others:
    *************************************************/
    CRS_SDK_API BOOL CRS_SetDAQParams(short positionAdjustment1, short positionAdjustment2);

    //************************************
    // Method:    CRS_SetASGDefauleLevel
    // FullName:  CRS_SetASGDefauleLevel
    // Access:    public 
    // Returns:   CRS_SDK_API BOOL
    // Qualifier:
    // Parameter: unsigned char defaultLevel, 8个通道默认电平，1高0低
    //************************************
    CRS_SDK_API BOOL CRS_SetASGDefauleLevel(unsigned char defaultLevel);

    /*************************************************
    **Function: CRS_ASGPulseDownload
    **Description: ASG输出数据的下载
    **Input: 	pulses 8个通道的序列数据
    **Input: 	length 每个通道的数据长度
    **Output:
    **Return: 	TRUE代表函数执行成功，FALSE表示函数执行失败
    **Others:   必须是4的整数倍
    *************************************************/
    CRS_SDK_API BOOL CRS_ASGPulseDownload(double **pulses, int length[][8], unsigned short* loop, unsigned short segmentNum);

    /*************************************************
    **Function: 		CRS_ADCENSignalDownload
    **Description:		下载ADC使能信号
    **Input: 			long long * enableSignal 使能信号
    **Input: 			int* length 使能信号数据长度
    **Input: 			unsigned short * loop 每段segment重复次数
    **Input: 			unsigned short segmentNum 每个
    **Output:			
    **Return: 			CRS_SDK_API BOOL
    **Others:			
    *************************************************/
    CRS_SDK_API BOOL CRS_ADCENSignalDownload(long long* enableSignal, int* length, unsigned short* loop, unsigned short segmentNum);

    /*************************************************
    **Function:         CRS_SetDDSAWGMode
    **Description:      DDS模式AWG播放指令
    **Input: 	        double frequencyChannel1 通道1：DDS频率控制字
    **Input: 	        double frequencyChannel2 通道2：DDS频率控制字
    **Input: 	        double phaseChannel1 通道1：DDS初始相位
    **Input: 	        double phaseChannel2 通道2：DDS初始相位
    **Input: 	        unsigned short amplitudeValue1 通道1：幅度设置
    **Input: 	        unsigned short amplitudeValue2 通道2：幅度设置
    **Input: 	        short biasChannel1 通道1：偏置设置
    **Input: 	        short biasChannel2 通道2：偏置设置
    **Output:
    **Return: 	        BOOL TRUE代表函数执行成功，FALSE表示函数执行失败
    **Others:
    *************************************************/
    CRS_SDK_API BOOL CRS_SetDDSAWGMode(double frequencyChannel1, double frequencyChannel2, double phaseChannel1, double phaseChannel2,
        unsigned short amplitudeValue1, unsigned short amplitudeValue2, short biasChannel1, short biasChannel2);

    /*************************************************
    **Function: 		CRS_StartDDSBroadcast
    **Description:		开始播放DDS
    **Output:			
    **Return: 			BOOL TRUE代表函数执行成功，FALSE表示函数执行失败
    **Others:			
    *************************************************/
    CRS_SDK_API BOOL CRS_StartDDSBroadcast();
    
    /*************************************************
    **Function: 		CRS_AWG_SetParams
    **Description:		下载部分AWG需要的配置参数
    **Input: 			Params params 包含AWG参数的结构体
    **Output:			
    **Return: 			BOOL TRUE代表函数执行成功，FALSE表示函数执行失败
    **Others:			
    *************************************************/
    CRS_SDK_API BOOL CRS_SetCRSParams(Params params);

    /*************************************************
    **Function: 		CRS_SetAWGBiases
    **Description:		设置 AWG 通道偏置
    **Input: 			ch1bias, ch2bias OUT1 和 OUT2 的偏置
    **Output:
    **Return: 			BOOL TRUE代表函数执行成功，FALSE表示函数执行失败
    **Others:
    *************************************************/
    CRS_SDK_API BOOL CRS_SetAWGBiases(unsigned short ch1bias, unsigned short cha2bias);



    //************************************
    // Type:      TDC_CALLBACK
    // FullName:  DAQ::TDC_CALLBACK
    // Access:    public 
    // Returns:   void
    // Qualifier: 
    // Parameter: int grp       组别， 0: 第一组, 1: 第二组
    // Parameter: int countC    粗计数
    // Parameter: int countF    细计数, 总时长 countC * 4ns + countF * 20ps
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
    // Parameter: unsigned char data[4][200] 个通道的校准数据
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
    // Parameter: int src, 0: 内部时钟，1: 外部时钟
    //************************************
    CRS_SDK_API BOOL CRS_SetClockSource(int src);

#ifdef __cplusplus
}
#endif
