#!/bin/sh
VIEWER=display
IMGTYPE=png
IMGDIR=/tmp

if [ $# == 0 ]; then
   # Without Parameter
   echo "Please use one of old or new style calls."
   echo "Old Style: $0 DIRNAME/ModelNode.ini"
   echo "           this will display the statechart in $IMGTYPE - Format"
   echo "New Style: $0 -m DIRNAME/ModelNode.ini" 
   echo "           [-o Directory\Output_File] (/$IMGDIR/sc.$IMGTYPE)" 
   echo "           [-f Imageformat] png|gif|... ($IMGTYPE) "
   echo "           [-v Viewer] ($VIEWER)"

else  
   if [ $# == 1 ]; then
      # Parametercount == 1 -> Old Style Call
      
      : "$@"
      NAME=$_
      BASE=${NAME%/*}
      CHART=${IMGDIR}/${BASE##*/}.${IMGTYPE}
   else
      while getopts "m:o:i:v:" optname
      do
         case "$optname" in
            "i")
#                echo "using Imageformat : $OPTARG"
               IMGTYPE=$OPTARG
               ;;
            "o")
#                echo "using Outputfile : $OPTARG"
               CHART_TMP=$OPTARG
               ;;
            "v")
#                echo "using viewer : $OPTARG"
               VIEWER=$OPTARG
               ;;
            "m")
#                echo "using Model Directory : $OPTARG"
               NAME=$OPTARG
               ;;
            "?")
               echo "Unknown option $OPTARG"
               ;;
            ":")
               echo "No argument value for option $OPTARG"
               ;;
            *)
               # Should not occur
               echo "Unknown error while processing options"
               ;;
            esac
      done
      if [[ -n $CHART_TMP ]]; then
         # if $CHART_TMP is not zero

         # is the extension ot the Outfile the same than the Imagetype?
         if [[ ${CHART_TMP##*.} == ${IMGTYPE} ]]; then
                  CHART=${CHART_TMP}
         else
                  CHART=${CHART_TMP}.${IMGTYPE}
         fi
      else
         BASE=${NAME%/*}
         CHART=${IMGDIR}/${BASE##*/}.${IMGTYPE}
      fi
      echo "using Outputfile : $CHART"
   fi
   StateChartDrawer ${NAME} |dot -T${IMGTYPE} -o ${CHART}
   ${VIEWER} ${CHART}
fi