#include "nf_signal.h"
#include "string.h"

#include "nf_assert.h"

/* �źŶ������� */
typedef struct _nf_sig
{
    NF_SignalName  Name;
    NF_SignalValue Value;
}NF_Signal;

/* �洢�źŵı� */
static NF_Signal NF_Signal_SigList[NF_MAX_SIGNAL_NUM] = {0};
static NF_Int32U NF_Signal_SigListCnt = 0;


/* ���ź����ڱ��в����źŶ��� */
static NF_Signal* NF_Signal_Search(NF_SignalName name, NF_SignalID* id_ret)
{
    NF_Int32U i;

    /* �ź�������Ϊ�� */
    NF_ASSERT( name != NF_NULL_PTR );

    for (i = 0; i < NF_Signal_SigListCnt; i ++)
    {
        if ( strcmp( NF_Signal_SigList[i].Name, name ) == 0 )
        {
            /* ͨ���ص���������ID�� */
            if (id_ret != NF_NULL_PTR)
            {
                *id_ret = i;
            }

            return &(NF_Signal_SigList[i]);
        }
    }

    /* û���ҵ������ؿ�ָ�� */
    return NF_NULL_PTR;
}

/* ����һ�����ź� */
static NF_Signal* NF_Signal_Create(NF_SignalName name, NF_SignalValue val, NF_SignalID* id_ret)
{
    /* �ź�������Ϊ�� */
    NF_ASSERT( name != NF_NULL_PTR );
    
    if (NF_Signal_SigListCnt < NF_MAX_SIGNAL_NUM)
    {
        NF_Signal_SigList[NF_Signal_SigListCnt].Name  = name;
        NF_Signal_SigList[NF_Signal_SigListCnt].Value = val;
        NF_Signal_SigListCnt ++;

        /* ͨ���ص���������ID�� */
        if (id_ret != NF_NULL_PTR)
        {
            *id_ret = NF_Signal_SigListCnt - 1;
        }
        
        return &(NF_Signal_SigList[NF_Signal_SigListCnt - 1]);
    }
    else
    {
        /* �ź��б���������ʧ�� */
        /* ��ʱӦ�Ӵ�ͷ�ļ�������ź�������NF_MAX_SIGNAL_NUM */
        return NF_NULL_PTR;
    }
}


/* ͨ���ַ������Ƹ���ֵ�źţ��粻�����򴴽���ʱ�临�Ӷ����O(n) */
NF_SignalID NF_Signal_Set(NF_SignalName name, NF_SignalValue val)
{
    NF_Signal* sig = NF_NULL_PTR;
    NF_SignalID id;

    /* �ź�������Ϊ�� */
    NF_ASSERT( name != NF_NULL_PTR );
    
    sig = NF_Signal_Search(name, &id);
    if (sig != NF_NULL_PTR)
    {
        sig->Value = val;
        return id;
    }
    else
    {
        sig = NF_Signal_Create(name, val, &id);

        /* ����ʧ�����ź��б�����������NF_MAX_SIGNAL_NUM */
        NF_ASSERT( sig != NF_NULL_PTR );

        return id;
    }
}

/* ͨ�������ź�ʱ��õ�ID�Ÿ�ֵ�źţ��粻��������Ч��ʱ�临�Ӷ�O(1) */
void NF_Signal_SetID(NF_SignalID id, NF_SignalValue val)
{
    /* ID������Ч */
    NF_ASSERT( id < NF_Signal_SigListCnt );

    if (id < NF_Signal_SigListCnt)
    {
        NF_Signal_SigList[id].Value = val;
    }
}

/* ͨ���ַ������ƻ�ȡ�ź�ֵ���粻���ڷ���0��ʱ�临�Ӷ����O(n) */
NF_SignalValue NF_Signal_Get(NF_SignalName name)
{
    NF_Signal* sig = NF_NULL_PTR;

    /* �ź�������Ϊ�� */
    NF_ASSERT( name != NF_NULL_PTR );
    
    sig = NF_Signal_Search(name, NF_NULL_PTR);

    if (sig != NF_NULL_PTR)
    {
        /* �����ɹ������ź�ֵ */
        return sig->Value;
    }
    else
    {
        /* ����ʧ�ܷ���0 */
        return 0;
    }
}

/* ͨ�������ź�ʱ��õ�ID��ȡ�ź�ֵ���粻���ڷ���0��ʱ�临�Ӷ�O(1) */
NF_SignalValue NF_Signal_GetID(NF_SignalID id)
{
    /* ID������Ч */
    NF_ASSERT( id < NF_Signal_SigListCnt );

    if (id < NF_Signal_SigListCnt)
    {
        return NF_Signal_SigList[id].Value;
    }
	else
	{
		return 0;
	}
}
