// ****************************************************************************
// *                                                                          *
// *   (C)  Hottinger Baldwin Messtechnik GmbH                                *
// *        Im Tiefen See 45,                                                 *
// *        D-64293 Darmstadt                                                 *
// *        www.hbm.com                                                       *
// *                                                                          *
// *        Module generated with Rational Rose ANSI C++                      *
// *                                                                          *
// ******* MODULE HISTORY *****************************************************
// *                                                                          *
// *   Ver     Date     Author      Remarks                                   *
// *   ---------------------------------------------------------------------- *
// *   000     18.03.05             implemented                               *
// ****************************************************************************

#include "DSS_Com/clTransMsgs.h"
#include "PCK_Util/clTxTelContainer.h"
#include "DSS_Com/clTransHandler.h"
#include "PCK_Util/clErrorHandler.h"
#include "DSS_Com/clTcpServer.h"
#include "DSS_Com/TransMsgs.h"
#include "DSS_Com/clTransFrame.h"
#include "DSS_Com/clComMsgHndlr.h"

//##ModelId=4381AD1102BF
clTransMsgs::clTransMsgs():
m_MsgHndlr(NULL),
m_Connections(NULL),
m_Server(NULL),
m_TransHndlr(NULL),
m_EvFlag(),
m_GenConModuleRes(ERR_SUCCESS)
{
	NOTIFY_CONSTRUCTOR("clTransMsgs","ERR_SUCCESS")
}

//##ModelId=4381AD1E009C
clTransMsgs::~clTransMsgs()
{
	NOTIFY_DESTRUCTOR("clTransMsgs")
  // fuer Lint
  m_MsgHndlr = NULL;
  m_Connections = NULL;
  m_Server = NULL;
  m_TransHndlr = NULL;
}

INT32 clTransMsgs::putMsg(clMessage* pMsg)
{
	NOTIFY_FUNCTION_CALL("clTransMsgs","clMessage* pMsg","putMsg","")
  INT32 err;

  if(pMsg != NULL)
  {
    //lint -e{613}  possible use of NULL-Pointer
    err = m_MsgHndlr->putMsg(pMsg);
    if(err != ERR_SUCCESS)
      pMsg->discard();
  }
  else
  {
    clErrorHandler::add(ERRLVL_DEBUG,ERR_TRANS_CREATE_MSG);
    err = ERR_TRANS_CREATE_MSG;
  }
  
  return err;
}

INT32 clTransMsgs::sendRequest(void* Handle,tHBM_UUID DestinationAddr,
                               clTxTelContainer* Telegram)
{
	NOTIFY_FUNCTION_CALL("clTransMsgs","...","sendRequest","")
  clSendReqMsg *pMsg;
  INT32 err;
  
  HBM_ASSERT(m_MsgHndlr != NULL,"clTransMsgs::m_MsgHndlr not initialized");

  pMsg = clSendReqMsg::create(m_TransHndlr,Handle,DestinationAddr,Telegram);

  err = putMsg(pMsg);

  return err;
}

//##ModelId=437C7DE3003E
INT32 clTransMsgs::sendResponse(void *Handle, clTxTelContainer* Telegram)
{
	NOTIFY_FUNCTION_CALL("clTransMsgs","...","sendResponse","")
  clSendRespMsg *pMsg;
  INT32 err;
  
  HBM_ASSERT(m_MsgHndlr != NULL,"clTransMsgs::m_MsgHndlr not initialized");

  pMsg = clSendRespMsg::create(m_TransHndlr,Handle,Telegram);
  
  err = putMsg(pMsg);

  return err;
}

//##ModelId=437C7DE300AB
INT32 clTransMsgs::sendRespPndg(void *Handle, tTime_ms TimeToGo)
{
	NOTIFY_FUNCTION_CALL("clTransMsgs","...","sendRespPndg","")
  clSendRespPndgMsg *pMsg;
  INT32 err = ERR_SUCCESS;
  
  

  HBM_ASSERT(m_MsgHndlr != NULL,"clTransMsgs::m_MsgHndlr not initialized");

  pMsg = clSendRespPndgMsg::create(m_TransHndlr,Handle,TimeToGo);
  
  err = putMsg(pMsg); 
  
  return err;
}

UINT32 clTransMsgs::getDataPos()
{
	NOTIFY_FUNCTION_CALL("clTransMsgs","","getDataPos","")
  HBM_ASSERT(m_Connections != NULL,"clTransMsgs Connections not initialized");
  //lint -e{613} Warning -- Possible use of null pointer
  return (m_Connections->getDataPos() + clTransFrame::getHdrSize());
}

//##ModelId=437C7DE300EA
INT32 clTransMsgs::getConModules(tHBM_UUID IgnoreUUID,tConModulInfoList& ModuleList)
{
	NOTIFY_FUNCTION_CALL("clTransMsgs","...","getConModules","")
  clGetConModulesMsg *pMsg;
  INT32 err = ERR_SUCCESS;
  
  HBM_ASSERT(m_MsgHndlr != NULL,"clTransMsgs::m_MsgHndlr not initialized");
  
  pMsg = clGetConModulesMsg::create(m_TransHndlr,IgnoreUUID,ModuleList);
  if(pMsg != NULL)
  {
    m_EvFlag.reset();
    //lint -e{613}  possible use of NULL-Pointer
    err =  m_MsgHndlr->putMsg(pMsg);
    if(err == ERR_SUCCESS)
    {
      // warten, bis der ComMsgHndlr die Message bearbeitet hat
      //lint -e{534} Warning -- Ignoring return value of function  
      m_EvFlag.wait();
      err = m_GenConModuleRes;
    }
    else
      pMsg->discard();
  }
  else
  {
    clErrorHandler::add(ERRLVL_DEBUG,ERR_TRANS_CREATE_MSG);
    err = ERR_TRANS_CREATE_MSG;
  }
  return err;
}

void clTransMsgs::recGetConModulesCb(INT32 err)
{
	NOTIFY_FUNCTION_CALL("clTransMsgs","INT32 err","recGetConModulesCb","")
   m_GenConModuleRes = err;
  // die Message ist abgearbeitet!
  m_EvFlag.signal();
}

INT32 clTransMsgs::getModuleInfos(tHBM_UUID ModuleUUID,stConModulInfo& ModuleInfo)
{
	NOTIFY_FUNCTION_CALL("clTransMsgs","...","getModuleInfos","")
  clGetModuleInfoMsg *pMsg;
  INT32 err = ERR_SUCCESS;
  
  HBM_ASSERT(m_MsgHndlr != NULL,"clTransMsgs::m_MsgHndlr not initialized");
  
  pMsg = clGetModuleInfoMsg::create(m_TransHndlr,ModuleUUID,ModuleInfo);
  if(pMsg != NULL)
  {
    m_EvFlag.reset();
    //lint -e{613}  possible use of NULL-Pointer
    err =  m_MsgHndlr->putMsg(pMsg);
    if(err == ERR_SUCCESS)
    {
      // warten, bis der ComMsgHndlr die Message bearbeitet hat
      //lint -e{534} Warning -- Ignoring return value of function  
      m_EvFlag.wait();
      err = m_GenModuleInfoRes;
    }
    else
      pMsg->discard();
  }
  else
  {
    clErrorHandler::add(ERRLVL_DEBUG,ERR_TRANS_CREATE_MSG);
    err = ERR_TRANS_CREATE_MSG;
  }
  return err;
}

void clTransMsgs::recGetModuleInfoCb(INT32 err)
{
	NOTIFY_FUNCTION_CALL("clTransMsgs","INT32 err","recGetModuleInfoCb","")
   m_GenModuleInfoRes = err;
  // die Message ist abgearbeitet!
  m_EvFlag.signal();
}

//##ModelId=437C7A9100AB
void clTransMsgs::recRespTransTimerCb(void *Handle,void* pData)
{
	NOTIFY_FUNCTION_CALL("clTransMsgs","...","recRespTransTimerCb","")
  clRespTimerCbMsg *pMsg;
  clTransMsgs *pThis = reinterpret_cast<clTransMsgs*>(Handle);
  INT32 err;
  
  
  if(pThis != NULL)
  {
    HBM_ASSERT(pThis->m_MsgHndlr != NULL,"clTransMsgs::m_MsgHndlr not initialized");
    pMsg = clRespTimerCbMsg::create(pThis->m_TransHndlr,pData);
    if(pMsg != NULL)
    {
      err = pThis->m_MsgHndlr->putMsg(pMsg);
      if(err != ERR_SUCCESS)
        pMsg->discard();
    }
    else
     clErrorHandler::add(ERRLVL_DEBUG,ERR_TRANS_CREATE_MSG);   
  }
  else
  {
    clErrorHandler::add(ERRLVL_DEBUG,ERR_TRANS_DISP_MSG);
  }
}

void clTransMsgs::recReqTransTimerCb(void *Handle,void* pData)
{
	NOTIFY_FUNCTION_CALL("clTransMsgs","...","recReqTransTimerCb","")
  clReqTimerCbMsg *pMsg;
  clTransMsgs *pThis = reinterpret_cast<clTransMsgs*>(Handle);
  INT32 err;
  
  
  if(pThis != NULL)
  {
    HBM_ASSERT(pThis->m_MsgHndlr != NULL,"clTransMsgs::m_MsgHndlr not initialized");
    pMsg = clReqTimerCbMsg::create(pThis->m_TransHndlr,pData);
    if(pMsg != NULL)
    {
      err = pThis->m_MsgHndlr->putMsg(pMsg);
      if(err != ERR_SUCCESS)
        pMsg->discard();
    }
    else
     clErrorHandler::add(ERRLVL_DEBUG,ERR_TRANS_CREATE_MSG);   
  }
  else
  {
    clErrorHandler::add(ERRLVL_DEBUG,ERR_TRANS_DISP_MSG);
  }
}

INT32 clTransMsgs::connectToTCPDev(tHBM_String& TCP_IP_Adr, UINT16 Port, tHBM_UUID &DevUUID)
{
	NOTIFY_FUNCTION_CALL("clTransMsgs","...","connectToTCPDev","")
  HBM_ASSERT(m_Server != NULL,"clTransMsgs Server not initialized");
  //lint -e{613} Warning -- Possible use of null pointer
  return m_Server->connectToTCPDev(TCP_IP_Adr,Port,DevUUID);
}

INT32 clTransMsgs::setupTcpServer(bool Enable, UINT16 Port)
{
	NOTIFY_FUNCTION_CALL("clTransMsgs","...","setupTcpServer","")
  HBM_ASSERT(m_Server != NULL,"clTransMsgs Server not initialized");
  //lint -e{613} Warning -- Possible use of null pointer
  return m_Server->setup(Enable, Port);
}

UINT16 clTransMsgs::getTcpServerPort()
{
	NOTIFY_FUNCTION_CALL("clTransMsgs","","getTcpServerPort","")
  HBM_ASSERT(m_Server != NULL,"clTransMsgs Server not initialized");
  //lint -e{613} Warning -- Possible use of null pointer
  return m_Server->getPort();
}

INT32 clTransMsgs::disconnectFromTCPDev(tHBM_String& TCP_IP_Adr, UINT16 Port)
{
	NOTIFY_FUNCTION_CALL("clTransMsgs","...","disconnectFromTCPDev","")
  HBM_ASSERT(m_Server != NULL,"clTransMsgs Server not initialized");
  //lint -e{613} Warning -- Possible use of null pointer
  return m_Server->disconnetFromTCPDev(TCP_IP_Adr,Port);
}


