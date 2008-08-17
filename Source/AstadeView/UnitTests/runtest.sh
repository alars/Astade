
if ( test "$1" == "--help" );
then
        echo "Usage:"
        echo "$0 [--dryrun]"
        exit 0
fi

sh ./updateModelTest.sh
sh ./create.sh

LOGNAME=log/test_`echo $USER`_`date +%F_%H:%M:%S_%Z.log`

if (./UnitTests > $LOGNAME)
then
        echo "===> Test executed successfully!"
else
        echo "===> Test had errors! See: $LOGNAME for details."
fi

if (test "$1" != "--dryrun");
then
        # Add log file to svn and commit it
        svn add $LOGNAME
        svn commit $LOGNAME -m "Test log committed automatically"
fi

