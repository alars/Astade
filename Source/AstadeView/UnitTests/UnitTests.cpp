#include "UnitTests.h"

#include <modeltest.h>
#include <AstadeDataModel.h>

void UnitTests::validateModel()
{
    AstadeDataModel* model = new AstadeDataModel( this );
    QVERIFY( model != NULL );
    model->setModelRootDir( "testdata/Model" );
    new ModelTest( model, this );
}

QTEST_MAIN(UnitTests)