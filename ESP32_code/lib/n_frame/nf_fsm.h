#ifndef NF_FSM_H
#define NF_FSM_H

#include <nf_type.h>
#include <nf_signal.h>

// #include "H:\GeXingHuaLAB_TeacherPAN\ESP32_v2.x\ESP32_LVGL_V7.1.x\lib\n_frame\nf_type.h"
// #include "H:\GeXingHuaLAB_TeacherPAN\ESP32_v2.x\ESP32_LVGL_V7.1.x\lib\n_frame\nf_signal.h"

/* �������� */
typedef NF_CString NF_FSM_Name;
typedef NF_CString NF_Event_Name;

/* �¼��������� */
typedef struct _nf_event
{
    NF_Event_Name Name;
}NF_Event;

/* ״̬�������� */
typedef struct _nf_state_machine NF_FSM;
/* ����״̬����������״̬ת������ص����� */
typedef void (*NF_FSM_Handler)(NF_FSM* me, NF_Event event);
typedef struct _nf_state
{
	NF_FSM_Handler Dispatch;
}NF_State;

/* ״̬���������� */
typedef struct _nf_state_machine
{
    NF_State State;
}NF_FSM;

/* ״̬ת���� */
#define NF_FSM_TRAN(_sta) NF_FSM_Translate(me, NF_FSM_State(_sta))
 
/* �ӿں����б� */
extern void     NF_FSM_Dispatch  (NF_FSM* me, NF_Event event);           // ���¼��ɷ���״̬����ͬһ״̬����Dispatch�����䲻�ܻ�����
extern void     NF_FSM_Translate (NF_FSM* me, NF_State state);           // ת��״̬��״̬
extern NF_Event NF_FSM_Event     (NF_Event_Name name);                   // �﷨�ǣ������¼���ֵ
extern NF_State NF_FSM_State     (NF_FSM_Handler handler);               // �﷨�ǣ�����״̬��ֵ
extern NF_Bool  NF_FSM_NameIs    (NF_FSM_Name name1, NF_FSM_Name name2); // �﷨�ǣ������ж�״̬��

#endif