#include <nf_fsm.h>
#include <nf_assert.h>

// #include "string.h"
// #include "H:\GeXingHuaLAB_TeacherPAN\ESP32_v2.x\ESP32_LVGL_V7.1.x\lib\n_frame\nf_fsm.h"
// #include "H:\GeXingHuaLAB_TeacherPAN\ESP32_v2.x\ESP32_LVGL_V7.1.x\lib\n_frame\nf_assert.h"

#include "string.h"
/* ���¼��ɷ���״̬����ִ��ת������ */
/* ��ע:��֧��ͬһ״̬��ͬʱ���жϺ����������ɷ� */
/* ͬһ��״̬����Dispatch�������ܻ����� */
void NF_FSM_Dispatch(NF_FSM* me, NF_Event event)
{
	/* ����ָ�벻��Ϊ�� */
	NF_ASSERT( me != NF_NULL_PTR );

	me->State.Dispatch(me, event);
}

/* �﷨�ǣ������¼���ֵ */
NF_Event NF_FSM_Event(NF_Event_Name name)
{
	NF_Event event;

	/* ����ָ�벻��Ϊ�� */
	NF_ASSERT(name != NF_NULL_PTR);

	event.Name = name;
	return event;
}

/* ת��״̬��״̬ */
void NF_FSM_Translate(NF_FSM* me, NF_State state) 
{
    /* ����ָ�벻��Ϊ�� */
    NF_ASSERT( me != NF_NULL_PTR );

    me->State = state;
}   

/* �﷨�ǣ�����״̬��ֵ */
NF_State NF_FSM_State(NF_FSM_Handler handler)
{
	NF_State state;
	
	/* ����ָ�벻��Ϊ�� */
	NF_ASSERT(handler != NF_NULL_PTR);

	state.Dispatch = handler;
	return state;
}

/* �﷨�ǣ������ж�״̬�� */
NF_Bool NF_FSM_NameIs(NF_FSM_Name name1, NF_FSM_Name name2)
{
	/* ����ָ�벻��Ϊ�� */
	NF_ASSERT( (name1 != NF_NULL_PTR) && (name2 != NF_NULL_PTR) );

	if ( strcmp(name1, name2) == 0 )
	{
		return NF_Bool_True;
	} 
	else
	{
		return NF_Bool_False;
	}
}
