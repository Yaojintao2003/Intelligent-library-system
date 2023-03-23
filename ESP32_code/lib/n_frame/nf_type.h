#ifndef NF_TYPE_H
#define NF_TYPE_H

/* ����ʹ��stdint.hͷ�ļ������������Ͷ��� */
#include <stdint.h>



/* ��ƽ̨�������� */
/* ��ֲʱ���滻Ϊ��ƽ̨�������� */
typedef uint8_t  NF_Int8U;
typedef uint16_t NF_Int16U;
typedef uint32_t NF_Int32U;

typedef int8_t   NF_Int8S;
typedef int16_t  NF_Int16S;
typedef int32_t  NF_Int32S;

/* ID������,�ɰ������޸� */
typedef NF_Int32U NF_ID;

/* C�����ַ��� */
typedef const char* NF_CString;

/* �������� */
typedef enum _nf_bool
{
	NF_Bool_True = 1,
	NF_Bool_False = 0
}NF_Bool;

/* ��ָ�� */
#define NF_NULL_PTR ((void*)0)

#endif