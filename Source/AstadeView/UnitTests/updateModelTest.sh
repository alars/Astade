if test -d modeltest ; 
then
        echo "Update TT-Modeltest"
        cd modeltest
        svn up
else
        echo "Fetching TT-Modeltest"
        svn co svn://labs.trolltech.com/svn/itemviews/modeltest
fi
