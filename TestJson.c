#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"


int MakeJsonNameAge(char *pszJsonContent, int iJsonLen);
int MakeJsonPersonInfo(char *pszJsonContent, int iJsonLen);
int MakeJsonTwoPersonInfo(char *pszJsonContent, int iJsonLen);
int MakeJsonIDPersonInfo(char *pszJsonContent, int iJsonLen);
int MakeJsonPersonNameInfo(char *pszJsonContent, int iJsonLen);
int MakeJsonIDPersonNameInfo(char *pszJsonContent, int iJsonLen);
int MakeJsonAgePersonNameInfo(char *pszJsonContent, int iJsonLen);
int MakeJsonPersonsInfo(char *pszJsonContent, int iJsonLen);



/****************************************************************
* ��������: ������
* �������: ��
* �������: ��
* ��  ��  ֵ : 0-ִ�����
* ����˵��: ��
* �޸�����      �汾��        �޸���         �޸�����
*-------------------------------------------------------------
* 20170427               V1.0              Zhou Zhaoxiong          ����
****************************************************************/
int main(void)
{
    int  iRetVal         = 0;
    char szJsonData[500] = {0};

    iRetVal = MakeJsonNameAge(szJsonData, sizeof(szJsonData)-1);
    if (iRetVal == 0)
    {
        printf("JsonData=%s\n", szJsonData);
    }
    else
    {
        printf("Exec MakeJsonNameAge failed!\n");

        return -1;
    }   

    // -----------
    memset(szJsonData, 0x00, sizeof(szJsonData));
    iRetVal = MakeJsonPersonInfo(szJsonData, sizeof(szJsonData)-1);
    if (iRetVal == 0)
    {
        printf("JsonData=%s\n", szJsonData);
    }
    else
    {
        printf("Exec MakeJsonPersonInfo failed!\n");

        return -1;
    }

    // -----------
    memset(szJsonData, 0x00, sizeof(szJsonData));
    iRetVal = MakeJsonTwoPersonInfo(szJsonData, sizeof(szJsonData)-1);
    if (iRetVal == 0)
    {
        printf("JsonData=%s\n", szJsonData);
    }
    else
    {
        printf("Exec MakeJsonTwoPersonInfo failed!\n");

        return -1;
    }

    // -----------
    memset(szJsonData, 0x00, sizeof(szJsonData));
    iRetVal = MakeJsonIDPersonInfo(szJsonData, sizeof(szJsonData)-1);
    if (iRetVal == 0)
    {
        printf("JsonData=%s\n", szJsonData);
    }
    else
    {
        printf("Exec MakeJsonIDPersonInfo failed!\n");

        return -1;
    }

    // -----------
    memset(szJsonData, 0x00, sizeof(szJsonData));
    iRetVal = MakeJsonPersonNameInfo(szJsonData, sizeof(szJsonData)-1);
    if (iRetVal == 0)
    {
        printf("JsonData=%s\n", szJsonData);
    }
    else
    {
        printf("Exec MakeJsonPersonNameInfo failed!\n");

        return -1;
    }

    // -----------
    memset(szJsonData, 0x00, sizeof(szJsonData));
    iRetVal = MakeJsonIDPersonNameInfo(szJsonData, sizeof(szJsonData)-1);
    if (iRetVal == 0)
    {
        printf("JsonData=%s\n", szJsonData);
    }
    else
    {
        printf("Exec MakeJsonIDPersonNameInfo failed!\n");

        return -1;
    }

    // -----------
    memset(szJsonData, 0x00, sizeof(szJsonData));
    iRetVal = MakeJsonAgePersonNameInfo(szJsonData, sizeof(szJsonData)-1);
    if (iRetVal == 0)
    {
        printf("JsonData=%s\n", szJsonData);
    }
    else
    {
        printf("Exec MakeJsonAgePersonNameInfo failed!\n");

        return -1;
    }

    // -----------
    memset(szJsonData, 0x00, sizeof(szJsonData));
    iRetVal = MakeJsonPersonsInfo(szJsonData, sizeof(szJsonData)-1);
    if (iRetVal == 0)
    {
        printf("JsonData=%s\n", szJsonData);
    }
    else
    {
        printf("Exec MakeJsonPersonsInfo failed!\n");

        return -1;
    }

    return 0;
}


/****************************************************************
* ��������: ����ֻ���������������JSON��Ϣ
* �������: iJsonLen-JSON��Ϣ�峤��
* �������: pszJsonContent-JSON��Ϣ��
* ��  ��  ֵ : 0-ִ�гɹ�  -1-ִ��ʧ��
* ����˵��: ��
* �޸�����      �汾��        �޸���         �޸�����
*-------------------------------------------------------------
* 20170427               V1.0              Zhou Zhaoxiong          ����
****************************************************************/
/*
{
    name:"zhou",
    age:30
}

*/
int MakeJsonNameAge(char *pszJsonContent, int iJsonLen)
{
    cJSON *root = NULL;
    char  *out  = NULL;

    // �жϺ��������Ƿ�Ϸ�
    if (pszJsonContent == NULL)
    {
        printf("MakeJsonNameAge: pszJsonContent is NULL!");
    
        return -1;
    }
    
    root = cJSON_CreateObject();
    if(NULL == root)
    {
        printf("MakeJsonNameAge: exec cJSON_CreateObject to get root failed!");
        
        return -1;
    }
    
    cJSON_AddStringToObject(root, "name", "zhou");

    cJSON_AddNumberToObject(root, "age", 30);
    
    out=cJSON_Print(root);
    strncpy(pszJsonContent, out, iJsonLen - 1);
    pszJsonContent[iJsonLen - 1] = '\0';

    cJSON_Delete(root);
    free(out);

    return 0;
}


/****************************************************************
* ��������: ����ֻ����1����Ա��Ϣ��JSON��Ϣ
* �������: iJsonLen-JSON��Ϣ�峤��
* �������: pszJsonContent-JSON��Ϣ��
* ��  ��  ֵ : 0-ִ�гɹ�  -1-ִ��ʧ��
* ����˵��: ��
* �޸�����      �汾��        �޸���         �޸�����
*-------------------------------------------------------------
* 20170428               V1.0              Zhou Zhaoxiong          ����
****************************************************************/
/*
{
    personinfo:{
        name:"zhou",
        age:30
    }
}
*/
int MakeJsonPersonInfo(char *pszJsonContent, int iJsonLen)
{
    cJSON *root        = NULL;
    cJSON *JsonLevel1  = NULL;
    char  *out         = NULL;

    // �жϺ��������Ƿ�Ϸ�
    if (pszJsonContent == NULL)
    {
        printf("MakeJsonPersonInfo: pszJsonContent is NULL!");
    
        return -1;
    }
    
    root = cJSON_CreateObject();
    if(NULL == root)
    {
        printf("MakeJsonPersonInfo: exec cJSON_CreateObject to get root failed!");
        
        return -1;
    }
    
    JsonLevel1 = cJSON_CreateObject();
    if(NULL == JsonLevel1)
    {
        printf("MakeJsonPersonInfo: exec cJSON_CreateObject to get JsonLevel1 failed!");
        
        cJSON_Delete(root);
        return -1;
    }   

    cJSON_AddStringToObject(JsonLevel1, "name", "zhou");

    cJSON_AddNumberToObject(JsonLevel1, "age", 30);

    cJSON_AddItemToObject(root, "personinfo", JsonLevel1);
    
    out=cJSON_Print(root);
    strncpy(pszJsonContent, out, iJsonLen - 1);
    pszJsonContent[iJsonLen - 1] = '\0';

    cJSON_Delete(root);
    free(out);

    return 0;
}


/****************************************************************
* ��������: ����ֻ����2����Ա��Ϣ��JSON��Ϣ
* �������: iJsonLen-JSON��Ϣ�峤��
* �������: pszJsonContent-JSON��Ϣ��
* ��  ��  ֵ : 0-ִ�гɹ�  -1-ִ��ʧ��
* ����˵��: ��
* �޸�����      �汾��        �޸���         �޸�����
*-------------------------------------------------------------
* 20170428               V1.0              Zhou Zhaoxiong          ����
****************************************************************/
/*
{
    personinfo1:{
        name:"zhou",
        age:30
    },
    personinfo2:{
        name:"zhang",
        age:41
    }
}
*/
int MakeJsonTwoPersonInfo(char *pszJsonContent, int iJsonLen)
{
    cJSON *root        = NULL;
    cJSON *JsonLevel1  = NULL;
    char  *out         = NULL;

    // �жϺ��������Ƿ�Ϸ�
    if (pszJsonContent == NULL)
    {
        printf("MakeJsonTwoPersonInfo: pszJsonContent is NULL!");
    
        return -1;
    }
    
    root = cJSON_CreateObject();
    if(NULL == root)
    {
        printf("MakeJsonTwoPersonInfo: exec cJSON_CreateObject to get root failed!");
        
        return -1;
    }

    //---------------
    JsonLevel1 = cJSON_CreateObject();
    if(NULL == JsonLevel1)
    {
        printf("MakeJsonTwoPersonInfo: exec cJSON_CreateObject to get JsonLevel1 failed 1!");
        
        cJSON_Delete(root);
        return -1;
    }   

    cJSON_AddStringToObject(JsonLevel1, "name", "zhou");

    cJSON_AddNumberToObject(JsonLevel1, "age", 30);

    cJSON_AddItemToObject(root, "personinfo1", JsonLevel1);

    //---------------
    JsonLevel1 = cJSON_CreateObject();
    if(NULL == JsonLevel1)
    {
        printf("MakeJsonTwoPersonInfo: exec cJSON_CreateObject to get JsonLevel1 failed 2!");
        
        cJSON_Delete(root);
        return -1;
    }   

    cJSON_AddStringToObject(JsonLevel1, "name", "zhang");

    cJSON_AddNumberToObject(JsonLevel1, "age", 40);

    cJSON_AddItemToObject(root, "personinfo2", JsonLevel1);
    
    out=cJSON_Print(root);
    strncpy(pszJsonContent, out, iJsonLen - 1);
    pszJsonContent[iJsonLen - 1] = '\0';

    cJSON_Delete(root);
    free(out);

    return 0;
}


/****************************************************************
* ��������: �������id��personinfo��JSON��Ϣ
* �������: iJsonLen-JSON��Ϣ�峤��
* �������: pszJsonContent-JSON��Ϣ��
* ��  ��  ֵ : 0-ִ�гɹ�  -1-ִ��ʧ��
* ����˵��: ��
* �޸�����      �汾��        �޸���         �޸�����
*-------------------------------------------------------------
* 20170428               V1.0              Zhou Zhaoxiong          ����
****************************************************************/
/*
{
    id:"123456",
    personinfo:{
        name:"zhou",
        age:30
    }
}
*/
int MakeJsonIDPersonInfo(char *pszJsonContent, int iJsonLen)
{
    cJSON *root        = NULL;
    cJSON *JsonLevel1  = NULL;
    char  *out         = NULL;

    // �жϺ��������Ƿ�Ϸ�
    if (pszJsonContent == NULL)
    {
        printf("MakeJsonIDPersonInfo: pszJsonContent is NULL!");
    
        return -1;
    }
    
    root = cJSON_CreateObject();
    if(NULL == root)
    {
        printf("MakeJsonIDPersonInfo: exec cJSON_CreateObject to get root failed!");
        
        return -1;
    }

    cJSON_AddStringToObject(root, "id", "123456");
    
    JsonLevel1 = cJSON_CreateObject();
    if(NULL == JsonLevel1)
    {
        printf("MakeJsonIDPersonInfo: exec cJSON_CreateObject to get JsonLevel1 failed!");
        
        cJSON_Delete(root);
        return -1;
    }   

    cJSON_AddStringToObject(JsonLevel1, "name", "zhou");

    cJSON_AddNumberToObject(JsonLevel1, "age", 30);

    cJSON_AddItemToObject(root, "personinfo", JsonLevel1);
    
    out=cJSON_Print(root);
    strncpy(pszJsonContent, out, iJsonLen - 1);
    pszJsonContent[iJsonLen - 1] = '\0';

    cJSON_Delete(root);
    free(out);

    return 0;
}


/****************************************************************
* ��������: �������personname��JSON��Ϣ
* �������: iJsonLen-JSON��Ϣ�峤��
* �������: pszJsonContent-JSON��Ϣ��
* ��  ��  ֵ : 0-ִ�гɹ�  -1-ִ��ʧ��
* ����˵��: ��
* �޸�����      �汾��        �޸���         �޸�����
*-------------------------------------------------------------
* 20170428               V1.0              Zhou Zhaoxiong          ����
****************************************************************/
/*
{
    personname:[
        "zhou",
        "zhang"
    ]
}
*/
int MakeJsonPersonNameInfo(char *pszJsonContent, int iJsonLen)
{
    cJSON *root        = NULL;
    cJSON *JsonLevel1  = NULL;
    cJSON *JsonLevel2  = NULL;
    char  *out         = NULL;

    // �жϺ��������Ƿ�Ϸ�
    if (pszJsonContent == NULL)
    {
        printf("MakeJsonPersonNameInfo: pszJsonContent is NULL!");
    
        return -1;
    }
    
    root = cJSON_CreateObject();
    if (NULL == root)
    {
        printf("MakeJsonPersonNameInfo: exec cJSON_CreateObject to get root failed!");
        
        return -1;
    }

    JsonLevel1 = cJSON_CreateArray();
    if (NULL == JsonLevel1)
    {
        printf("MakeJsonPersonNameInfo: exec cJSON_CreateArray to get JsonLevel1 failed!");
        
        cJSON_Delete(root);
        return -1;
    }
    
    cJSON_AddItemToObject(root, "personname", JsonLevel1);

    JsonLevel2 = cJSON_CreateString("zhou");
    cJSON_AddItemToArray(JsonLevel1, JsonLevel2);

    JsonLevel2 = cJSON_CreateString("zhang");
    cJSON_AddItemToArray(JsonLevel1, JsonLevel2);
    
    out=cJSON_Print(root);
    strncpy(pszJsonContent, out, iJsonLen - 1);
    pszJsonContent[iJsonLen - 1] = '\0';

    cJSON_Delete(root);
    free(out);

    return 0;
}


/****************************************************************
* ��������: �������id/personname/personinfo��JSON��Ϣ
* �������: iJsonLen-JSON��Ϣ�峤��
* �������: pszJsonContent-JSON��Ϣ��
* ��  ��  ֵ : 0-ִ�гɹ�  -1-ִ��ʧ��
* ����˵��: ��
* �޸�����      �汾��        �޸���         �޸�����
*-------------------------------------------------------------
* 20170428               V1.0              Zhou Zhaoxiong          ����
****************************************************************/
/*
{
    id:"123456",
    personname:[
        "zhou",
        "zhang"
    ],
    personinfo:{
        phonenumber:"15696192591",
        age:30
    }
}

*/
int MakeJsonIDPersonNameInfo(char *pszJsonContent, int iJsonLen)
{
    cJSON *root        = NULL;
    cJSON *JsonLevel1  = NULL;
    cJSON *JsonLevel2  = NULL;
    char  *out         = NULL;

    // �жϺ��������Ƿ�Ϸ�
    if (pszJsonContent == NULL)
    {
        printf("MakeJsonIDPersonNameInfo: pszJsonContent is NULL!");
    
        return -1;
    }
    
    root = cJSON_CreateObject();
    if (NULL == root)
    {
        printf("MakeJsonIDPersonNameInfo: exec cJSON_CreateObject to get root failed!");
        
        return -1;
    }

    cJSON_AddStringToObject(root, "id", "123456");

    JsonLevel1 = cJSON_CreateArray();
    if (NULL == JsonLevel1)
    {
        printf("MakeJsonIDPersonNameInfo: exec cJSON_CreateArray to get JsonLevel1 failed 1!");
        
        cJSON_Delete(root);
        return -1;
    }
    
    cJSON_AddItemToObject(root, "personname", JsonLevel1);

    JsonLevel2 = cJSON_CreateString("zhou");
    cJSON_AddItemToArray(JsonLevel1, JsonLevel2);

    JsonLevel2 = cJSON_CreateString("zhang");
    cJSON_AddItemToArray(JsonLevel1, JsonLevel2);

    //-----------------
    JsonLevel1 = cJSON_CreateObject();
    if(NULL == JsonLevel1)
    {
        printf("MakeJsonIDPersonNameInfo: exec cJSON_CreateObject to get JsonLevel1 failed 2!");
        
        cJSON_Delete(root);
        return -1;
    }   

    cJSON_AddStringToObject(JsonLevel1, "name", "zhou");

    cJSON_AddNumberToObject(JsonLevel1, "age", 30);

    cJSON_AddItemToObject(root, "personinfo", JsonLevel1);
    
    out=cJSON_Print(root);
    strncpy(pszJsonContent, out, iJsonLen - 1);
    pszJsonContent[iJsonLen - 1] = '\0';

    cJSON_Delete(root);
    free(out);

    return 0;
}


/****************************************************************
* ��������: �������age/personname/personinfo��JSON��Ϣ
* �������: iJsonLen-JSON��Ϣ�峤��
* �������: pszJsonContent-JSON��Ϣ��
* ��  ��  ֵ : 0-ִ�гɹ�  -1-ִ��ʧ��
* ����˵��: ��
* �޸�����      �汾��        �޸���         �޸�����
*-------------------------------------------------------------
* 20170428               V1.0              Zhou Zhaoxiong          ����
****************************************************************/
/*
{
    personinfo:{
        personname:[
        "zhou",
        "zhang"
        ],
        age:30
    }
}
*/
int MakeJsonAgePersonNameInfo(char *pszJsonContent, int iJsonLen)
{
    cJSON *root        = NULL;
    cJSON *JsonLevel1  = NULL;
    cJSON *JsonLevel2  = NULL;
    cJSON *JsonLevel3  = NULL;
    char  *out         = NULL;

    // �жϺ��������Ƿ�Ϸ�
    if (pszJsonContent == NULL)
    {
        printf("MakeJsonAgePersonNameInfo: pszJsonContent is NULL!");
    
        return -1;
    }
    
    root = cJSON_CreateObject();
    if (NULL == root)
    {
        printf("MakeJsonAgePersonNameInfo: exec cJSON_CreateObject to get root failed!");
        
        return -1;
    }

    JsonLevel1 = cJSON_CreateObject();
    if(NULL == JsonLevel1)
    {
        printf("MakeJsonAgePersonNameInfo: exec cJSON_CreateObject to get JsonLevel1 failed!");
        
        cJSON_Delete(root);
        return -1;
    }   

    cJSON_AddItemToObject(root, "personinfo", JsonLevel1);

    //------------------
    JsonLevel2 = cJSON_CreateArray();
    if (NULL == JsonLevel2)
    {
        printf("MakeJsonAgePersonNameInfo: exec cJSON_CreateArray to get JsonLevel2 failed!");
        
        cJSON_Delete(root);
        return -1;
    }
    
    cJSON_AddItemToObject(JsonLevel1, "personname", JsonLevel2);

    JsonLevel3 = cJSON_CreateString("zhou");
    cJSON_AddItemToArray(JsonLevel2, JsonLevel3);

    JsonLevel3 = cJSON_CreateString("zhang");
    cJSON_AddItemToArray(JsonLevel2, JsonLevel3);

    //------------------
    cJSON_AddNumberToObject(JsonLevel1, "age", 30);
    
    
    out=cJSON_Print(root);
    strncpy(pszJsonContent, out, iJsonLen - 1);
    pszJsonContent[iJsonLen - 1] = '\0';

    cJSON_Delete(root);
    free(out);

    return 0;
}


/****************************************************************
* ��������: �������personinfo�����JSON��Ϣ
* �������: iJsonLen-JSON��Ϣ�峤��
* �������: pszJsonContent-JSON��Ϣ��
* ��  ��  ֵ : 0-ִ�гɹ�  -1-ִ��ʧ��
* ����˵��: ��
* �޸�����      �汾��        �޸���         �޸�����
*-------------------------------------------------------------
* 20170503               V1.0              Zhou Zhaoxiong          ����
****************************************************************/
/*
{
    personinfo:[
    {
        name:"zhou",
        age:30
    },
    {
        name:"zhang",
        age:41
    }
    ]
}
*/
int MakeJsonPersonsInfo(char *pszJsonContent, int iJsonLen)
{
    cJSON *root        = NULL;
    cJSON *JsonLevel1  = NULL;
    cJSON *JsonLevel2  = NULL;
    char  *out         = NULL;

    // �жϺ��������Ƿ�Ϸ�
    if (pszJsonContent == NULL)
    {
        printf("MakeJsonPersonsInfo: pszJsonContent is NULL!");
    
        return -1;
    }
    
    root = cJSON_CreateObject();
    if (NULL == root)
    {
        printf("MakeJsonPersonsInfo: exec cJSON_CreateObject to get root failed!");
        
        return -1;
    }

    JsonLevel1 = cJSON_CreateArray();
    if (NULL == JsonLevel1)
    {
        printf("MakeJsonPersonsInfo: exec cJSON_CreateArray to get JsonLevel1 failed!");
        
        cJSON_Delete(root);
        return -1;
    }
    
    cJSON_AddItemToObject(root, "personinfo", JsonLevel1);

    //---------------
    JsonLevel2 = cJSON_CreateObject();
    if(NULL == JsonLevel2)
    {
        printf("MakeJsonPersonsInfo: exec cJSON_CreateObject to get JsonLevel2 failed 1!");
        
        cJSON_Delete(root);
        return -1;
    }   

    cJSON_AddItemToArray(JsonLevel1, JsonLevel2);

    cJSON_AddStringToObject(JsonLevel2, "name", "zhou");
    
    cJSON_AddNumberToObject(JsonLevel2, "age", 30);

    //---------------
    JsonLevel2 = cJSON_CreateObject();
    if(NULL == JsonLevel2)
    {
        printf("MakeJsonPersonsInfo: exec cJSON_CreateObject to get JsonLevel2 failed 2!");
        
        cJSON_Delete(root);
        return -1;
    }   

    cJSON_AddItemToArray(JsonLevel1, JsonLevel2);

    cJSON_AddStringToObject(JsonLevel2, "name", "zhang");
    
    cJSON_AddNumberToObject(JsonLevel2, "age", 41);     

    //---------------
    out=cJSON_Print(root);
    strncpy(pszJsonContent, out, iJsonLen - 1);
    pszJsonContent[iJsonLen - 1] = '\0';

    cJSON_Delete(root);
    free(out);

    return 0;
}


