/*******************************************************************************
(c) 2008 by dSys e.K.

$Id: $ $Name: $
*******************************************************************************/

/*!
********************************************************************************
@file main.c

@moduleinformation
  MODULNAME EINTRAGEN !

@preprocessor
  .

@verbatim
$Id: $ $Name: $
@endverbatim
RCS-Logs: 
@ref rcslog_main_c
********************************************************************************
*/

#ifdef __RCS
/* Name der Funktion, die die RCS-Information ermittelt */
#define	GETLOCALRCSID	main_getrcsid
#endif

#define	MAIN_C

/* Include-Dateien ************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "pdt.h"
// #include "main.h"
#include "prjset.h"

#include "statechart_common.h"
#include "timeout/timeout.h"

/* Konstanten *****************************************************************/
/*! @brief Debugstufen fuer die jeweiligen Modulbereiche */
#define	_DBG_LEVEL_VOID		DBG_LEVEL_INFO		//!< Standardbereich

/*! @brief interne Modulzustaende */
#define	_MSTATE_INIT		0x01			//!< Modul initialisiert

/* Makros *********************************************************************/
// Debugausgaben
#if 1
#define	_DBGF(part,level,...) printf("%s, %d: ", __FILE__, __LINE__); printf(__VA_ARGS__); printf("\r\n");
#define	_DBG(part,level,msg) printf("%s, %d: ", __FILE__, __LINE__); printf(msg); printf("\r\n");
#else
#define	_DBGF(part,level,...)
#define	_DBG(part,level,msg)
#endif

/* Typen **********************************************************************/

/* Prototypen *****************************************************************/

/* Variablen ******************************************************************/
static int	_iMaxFdNum;
static fd_set	_fdsetRead;

/* Funktionen *****************************************************************/

void  _fd_zero(void)
{
	FD_ZERO( &_fdsetRead );
	_iMaxFdNum = 0;
}

void  _fd_set( int fd )
{
	if (fd >= 0  &&  fd < FD_SETSIZE) {

		FD_SET( fd, &_fdsetRead );
		if (_iMaxFdNum < fd) {
			_iMaxFdNum = fd;
		}
	}
}


int  _fd_isset( int fd )
{
	if (fd >= 0  &&  fd < FD_SETSIZE)
	{
		return FD_ISSET( fd, &_fdsetRead );
	}
	else
	{
		return 0;
	}
}


/*!
********************************************************************************
@brief	Modul initialisieren

Diese Funktion initialisiert das Modul und muss vor dem Aufruf jeder anderen
Modulfunktion einmal aufgerufen werden.

@usage
\code
-
\endcode

@warning 	-
@bug 		-
@see		-

@return	-
********************************************************************************
*/
extern	int	main (int argc, char * const argv[])
{
	STATECHART_COMMON_RET	ret;
	char		c;
	int		iRet;
	struct timespec	*timeout;
	
	timeout_init();
	
	if ((ret = statechart_common_init()) != STATECHART_COMMON_RET_OK)
	{
		_DBGF(VOID, ERROR, "ERROR (%d) init Statechart", ret);
		return -1;
	}

	printf("press 'p' || 'q' + <ENTER> !\r\n");

	do {
		_fd_zero();
		_fd_set(STDIN_FILENO);

		timeout_check(&timeout);

		iRet = pselect(_iMaxFdNum+1, &_fdsetRead, NULL, NULL, timeout, NULL);

		if (_fd_isset(STDIN_FILENO))
		{
			read(STDIN_FILENO, &c, sizeof(c));
			if (c != '\n') // supress <ENTER>
			{
				_DBGF(VOID, ERROR, "Key : 0x%02x", c);
				ret = statechart_common_evt_key(&c);
				if (ret != STATECHART_COMMON_RET_OK)
				{
					_DBGF(VOID, ERROR, "STATECHART_COMMON_RET : %u", ret);
				}
			}
		}
	} while (1);


	return 0;
}

/*!
********************************************************************************
@brief	#

#

@usage
\code
-
\endcode

@warning 	-
@bug 		-
@see		-

@return	-
********************************************************************************
*/


#ifdef __RCS
/*!
********************************************************************************
@brief	Diese Funktion ermittelt die RCS-Information des Moduls

@return	Zeiger auf die RCS-Information des Moduls oder,
@return	falls \c __RCS_INFO nicht definiert, NULL
********************************************************************************
*/
extern	char	*main_getrcsid (void)
{
#ifdef __RCS_INFO
	return "$Id:$";
#else
	return NULL;
#endif
}
#endif

/* Aenderungsjournal **********************************************************/
#ifdef __DOCGEN
/*!
@page revisions Revisions

@subsection rcslog_main_c main.c
@verbatim
 * $Log: $
@endverbatim
*/
#endif
