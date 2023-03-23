//#include <n_frame.h>
#include <fsm_fsm.h>
// #include <chipsets.h>

//#include "dev_port\dsp_dev.h"
//#include "dev_port\in_dev.h"
//udp
// #include "udp_rtc.h"
//ADC



/* ״̬���������� */
void FSM_fsm_Light_mode_keep(NF_FSM* me, NF_Event event);
void FSM_fsm_Light_mode_change(NF_FSM* me, NF_Event event);
void FSM_fsm_Light_mode_OFF(NF_FSM* me, NF_Event event);
void FSM_fsm_Light_mode_ON(NF_FSM* me, NF_Event event);

// void Light_OFF(void)
// {
//   ledcWrite(0, 0);
//   Serial.println("���Ʋ���ȷ���صƣ�");

// }

//  void LED_adc_work(void)
//  {

//    Serial.println("PWM���仯��:1-������ȷ");
//    dutyCycle_int= adc_button_filter();

//    ledcWrite(0, dutyCycle_int);

//  }
//  void LED_adc_keep(void){
//    Serial.println("PWM��������:");
//    dutyCycle_int_keep= adc_button_filter();
//    ledcWrite(0, dutyCycle_int_keep);

//  }
//  void Light_ON(void){
//    Serial.println("1-������ȷ");
//  }



/* ״̬������ */
NF_FSM FSM_fsm = {
   // FSM_fsm_IDLEyjt
    FSM_fsm_Light_mode_keep
   //FSM_fsm
};

/* Light_mode_keep״̬������ */
void FSM_fsm_Light_mode_keep(NF_FSM* me, NF_Event event)
{

    if (NF_FSM_NameIs(event.Name, "Botton_flag1"))
    {
        LED_adc_work();
        NF_FSM_TRAN(FSM_fsm_Light_mode_change);
        return ;
    }

    if (NF_FSM_NameIs(event.Name, "people_flag0"))
    {
        Light_OFF();
        NF_FSM_TRAN(FSM_fsm_Light_mode_OFF);
        return ;
    }
}

/* Light_mode_change״̬������ */
void FSM_fsm_Light_mode_change(NF_FSM* me, NF_Event event)
{

    if (NF_FSM_NameIs(event.Name, "people_flag0"))
    {
        Light_OFF();
        NF_FSM_TRAN(FSM_fsm_Light_mode_OFF);
        return ;
    }

    if (NF_FSM_NameIs(event.Name, "Botton_flag0"))
    {
        LED_adc_keep();
        NF_FSM_TRAN(FSM_fsm_Light_mode_keep);
        return ;
    }
}

/* Light_mode_OFF״̬������ */
void FSM_fsm_Light_mode_OFF(NF_FSM* me, NF_Event event)
{

    if (NF_FSM_NameIs(event.Name, "people_flag0"))
    {
        Light_ON();
        NF_FSM_TRAN(FSM_fsm_Light_mode_ON);
        return ;
    }
}

/* Light_mode_ON״̬������ */
void FSM_fsm_Light_mode_ON(NF_FSM* me, NF_Event event)
{

    if (NF_FSM_NameIs(event.Name, "people_flag1"))
    {
        LED_adc_keep();
        NF_FSM_TRAN(FSM_fsm_Light_mode_keep);
        return ;
    }

    if (NF_FSM_NameIs(event.Name, "people_flag1"))
    {
        LED_adc_work();
        NF_FSM_TRAN(FSM_fsm_Light_mode_change);
        return ;
    }

    if (NF_FSM_NameIs(event.Name, "people_flag1"))
    {
        Light_OFF();
        NF_FSM_TRAN(FSM_fsm_Light_mode_OFF);
        return ;
    }
}


