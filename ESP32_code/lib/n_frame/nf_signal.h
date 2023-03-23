#ifndef NF_SIGNAL_H
#define NF_SIGNAL_H

#include <nf_type.h>
#include <nf_conf.h>
// #include "H:\GeXingHuaLAB_TeacherPAN\ESP32_v2.x\ESP32_LVGL_V7.1.x\lib\n_frame\nf_type.h"
// #include "H:\GeXingHuaLAB_TeacherPAN\ESP32_v2.x\ESP32_LVGL_V7.1.x\lib\n_frame\nf_conf.h"

/* �ź�ֵ���� */
/* �ɰ������޸��������� */
typedef NF_Int8U NF_SignalValue;

/* �ź������� */
typedef NF_CString NF_SignalName;

/* �ź�ID */
typedef NF_ID NF_SignalID;

/* �ӿں����б� */
extern NF_SignalID    NF_Signal_Set   (NF_SignalName name, NF_SignalValue val); // ͨ���ַ������Ƹ��źŸ�ֵ�����źŲ������򴴽���ʱ��O(n)
extern void           NF_Signal_SetID (NF_SignalID id, NF_SignalValue val);     // ͨ��ID���źŸ�ֵ�����źŲ���������Ч��ʱ��O(1)
extern NF_SignalValue NF_Signal_Get   (NF_SignalName name); // ͨ���ַ������ƻ���ź�ֵ�����źŲ����ڷ���0��ʱ��O(n)
extern NF_SignalValue NF_Signal_GetID (NF_SignalID id);     // ͨ��ID����ź�ֵ�����źŲ����ڷ���0��ʱ��O(1)


#endif