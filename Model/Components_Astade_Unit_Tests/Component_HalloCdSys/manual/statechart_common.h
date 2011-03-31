/*******************************************************************************
(c) 2008 by dSys e.K.

$Id: $ $Name: $
*******************************************************************************/

/*!
********************************************************************************
@file statechart_common.h

@moduleinformation
  MODULNAME EINTRAGEN !

@moduledescription
  #

@moduleglossary
  .

@preprocessor
  .

@verbatim
$Id: $ $Name: $
@endverbatim
RCS-Logs: 
@ref rcslog_statechart_common_h
********************************************************************************
*/

#ifndef STATECHART_COMMON_H
#define	STATECHART_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include-Dateien ************************************************************/
#include <stdio.h>

#include "pdt.h"
#include "timeout/timeout.h"

/* Konstanten *****************************************************************/
#define	STATECHART_COMMON_NAMELEN	20	/* Laenge des Namens fuer einen Automaten*/

/* Makros *********************************************************************/
/*! @brief timer starten.*/
#define	STATECHART_COMMON_TMR_START(tmr, timeout_ms) \
	{ 						\
		timeout_start(&((tmr)->timeout), timeout_ms); \
	}


/*! @brief timer stoppen.*/
#define	STATECHART_COMMON_TMR_STOP(tmr) \
	{				\
		timeout_stop(&((tmr)->timeout));	\
	}


/*! @brief Erzeugt eine Meldung, wenn ein Zustandswechsel stattgefunden hat.*/
#define	STATECHART_COMMON_STATE_CHANGE_MSG(sm, statename)	                                      \
         {                                                                                   \
            if (sm->usr.dbg_state_last != (void*) sm->next_state)                            \
            {                                                                                \
               /*_DBGF(VOID, NOTICE, "Statemachine %s, new state %s\r\n", sm->usr.name,  # statename); */ \
               printf("Statemachine %s, new state %s\r\n", sm->usr.name,  # statename);	     \
               sm->usr.dbg_state_last = (void*) sm->next_state;                              \
            }                                                                                \
         }

/*! @brief Bestimmt, ob ein Event eingetreten ist, liefert einen Wahrheitswert zurueck*/
#define	STATECHART_COMMON_IS_EVT(evt, event_id)	(evt->id == STATECHART_SM_EVTID_ ## event_id)

/* Typen **********************************************************************/
/*! @brief Beschreibung der Rueckgabewerte */
typedef enum
{
	STATECHART_COMMON_RET_OK,		//!< erfolgreich beendet
	STATECHART_COMMON_RET_E,		//!< .
	STATECHART_COMMON_RET_E_NOT_INIT,	//!< Modul nicht initialisiert
	STATECHART_COMMON_RET_E_ALREADY_INIT,	//!< Modul bereits initialisiert
	STATECHART_COMMON_RET_NOT_TAKEN,	//!< Event ist im aktuellen Zustand nicht vorgesehen
	STATECHART_COMMON_RET_E_CREATE_TIMEOUT,	//!< Probleme beim Timeout anlegen
	
} STATECHART_COMMON_RET;

struct statechart_sm_ctrl;	// Forward deklaration
struct statechart_common_evt; // Forward deklaration

/*! @brief Beschreibung einer Callback Funktion bei eingetretenem Timer*/
typedef void 			(*STATECHART_COMMON_TMR_CB) (
	struct	statechart_sm_ctrl	*sm);

/*! @brief Beschreibung eines Timers */
typedef struct statechart_common_tmr
{
#if 0
	....	architecture dependend things
	like :
	OS_TIMER_HANDLE		tmr_os;
# else
	TIMEOUT_HDL	timeout;
# endif	
} STATECHART_COMMON_TMR;

/*! @brief Beschreibung der Daten zum Timer Starten, wird nur zur Initialisierung benoetigt*/
typedef struct statechart_common_tmr_init
{	
	char			name[STATECHART_COMMON_NAMELEN];	//!< Name des Timers der Zustandsmaschine
} STATECHART_COMMON_TMR_INIT;

/*! @brief Beschreibung der Daten zu einem Event*/
typedef union statechart_common_evt_data
{
	char  key;
} STATECHART_COMMON_EVT_DATA;

/*! @brief Beschreibung der anwenderspezifischen Struktur, wird in der Zustandsmaschine gehalten*/
typedef struct statechart_common_usr
{
	char	name[STATECHART_COMMON_NAMELEN];	//!< Name der Zustandsmaschine
	void*	dbg_state_last;
} STATECHART_COMMON_USR;

#include "../auto/statechart_sm.h"

/*! @brief Beschreibung eines Events */
typedef	struct statechart_common_evt
{
	STATECHART_SM_EVTID		id;  	/*!< Event ID \ref: STATECHART_COMMON_IS_EVT */
	STATECHART_COMMON_EVT_DATA	data;	/*!< Daten zum Event */
} STATECHART_COMMON_EVT;

/* Prototypen *****************************************************************/
extern	STATECHART_COMMON_RET      	statechart_common_init (void);

extern	STATECHART_COMMON_RET	statechart_common_evt_key (
	char			*key);


#ifdef __RCS		
extern	char		*statechart_common_getrcsid (void);
#endif

#ifdef __cplusplus
}
#endif

/* Aenderungsjournal **********************************************************/
#ifdef __DOCGEN
/*!
@page revisions Revisions

@subsection rcslog_statechart_common_h statechart_common.h
@verbatim
 * $Log: $
@endverbatim
*/
#endif
#endif
