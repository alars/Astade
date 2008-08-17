#!/usr/local/bin/python
# Simple program to create a singleton classes that provide access to
# global configuration parameters.
# Written by Stefan Eilers

import sys, string
from xml.sax import handler, make_parser

# Bunch is a small class to gather information together
class Bunch:
    def __init__(self, **kwds):
        self.__dict__.update(kwds)


# XML-Parser that generates the C++ classes on the fly
class ConfigFileHandler(handler.ContentHandler): 
    def __init__(self, outfilePath):  
        self._outfilePath = outfilePath
        self._classElementFound  = 0
        self._settingsProperties = []  # Empty list
        self._includeElements    = []  # Empty list
        
    def get_interestList(self):
        return self.interestList
        
    def set_interestList(self, interestList):
        self.interestList = interestList
        
    def startDocument(self):                                    
        print "--------  Start Parsing --------"
        
    def endDocument(self):                                   
        print "--------  End Parsing --------"
        print "---  Start Code Generation ---"
        self.createHeaderProlog()
        for includeElement in self._includeElements:
            self.createIncludeInHeader( includeElement )
        self.createClassInHeader()
        for settingsProperty in self._settingsProperties:
            self.createMetaObjectPropertyInHeader( settingsProperty )
        self.createSelfFunctionInHeader()
        self.createClassInImpl()
        self.createSelfFunctionInImpl()     

        for settingsProperty in self._settingsProperties:
            self.createGetterInHeader( settingsProperty )
            self.createGetterInImpl( settingsProperty )
            self.createSetterInHeader( settingsProperty ) 
            self.createSetterInImpl( settingsProperty )
        
        self.closeClassInHeader();
        self._outHeaderFile.write('#endif // %s_H_\n' % self.className )
        print "--- End Code Generation ---"
        
    def startElement(self, name, attrs):
        if name.lower() == 'configuration':
            self.fileName     = attrs.get( 'filename' )
            self._headerFileName = self.fileName + '.h'
            self._implFileName   = self.fileName + '.cpp'
            self._outHeaderFile = open( self._outfilePath + '/' + self._headerFileName, 'w')
            self._outImplFile   = open( self._outfilePath + '/' + self._implFileName, 'w')
        elif name.lower() == 'class':
            self.className    = attrs.get( 'name' )
            self.organization = attrs.get( 'organization' )
            self.application  = attrs.get( 'application' )            
            self._classElementFound = 1
        elif name.lower() == 'settingsproperty':
            self.getterName = attrs.get( 'getter' )
            self.setterName = attrs.get( 'setter' )
            self.typeName   = attrs.get( 'type' )
            self.keyName    = attrs.get( 'key' )
            self.defaultName= attrs.get( 'default' )
            self.settingsProperty = Bunch( getterName = self.getterName, \
                                           setterName = self.setterName, \
                                           typeName   = self.typeName, \
                                           keyName    = self.keyName, \
                                           defaultName= self.defaultName )
            self._settingsProperties.append( self.settingsProperty )
        elif name.lower() == 'include':
            self.includeIsGlobal = attrs.get( 'global' )
            self.includeType      = attrs.get( 'type' )
            self.includeEntry = Bunch( includeIsGlobal = self.includeIsGlobal, \
                                       includeType     = self.includeType )
            self._includeElements.append( self.includeEntry )
            
    def endElement(self, name):  
        if name.lower() == 'class':
            pass
                        
    def characters(self, chrs):    
        pass #print('Characters: %s\n' % chrs)
        
        
    # The following lines are not called by the parser directly. They are just private
    def createHeaderProlog(self):
        self._outHeaderFile.write('// Automatic generated configuration file. Do not change anything here!\n')
        self._outHeaderFile.write('#ifndef %s_H_\n' % self.fileName) # TODO: Use self.className
        self._outHeaderFile.write('#define %s_H_\n\n' % self.fileName) # TODO: Use self.className
        self._outHeaderFile.write('#include <QSettings>\n');
        self._outHeaderFile.write('#include <QObject>\n' );
        
    def createIncludeInHeader(self, includeElement):
        if includeElement.includeIsGlobal == "1":
            self.leftIncludePattern = "<"
            self.rightIncludePattern = ">"
        else:
            self.leftIncludePattern = "\""
            self.rightIncludePattern = "\""
        
        self._outHeaderFile.write('#include %s%s%s\n' % (self.leftIncludePattern, includeElement.includeType, self.rightIncludePattern) )

    def createClassInHeader(self):
        self._outHeaderFile.write('\nclass %s: public QObject\n' % self.className)
        self._outHeaderFile.write('{\n')
        self._outHeaderFile.write('    Q_OBJECT\n')
    
    def createMetaObjectPropertyInHeader( self, settingsProperty ):
        if len( settingsProperty.getterName ) != 0:
            self._outHeaderFile.write('    Q_PROPERTY( %s %s READ %s' % (settingsProperty.typeName, settingsProperty.getterName, settingsProperty.getterName) )
            if len( settingsProperty.setterName ) != 0:
                self._outHeaderFile.write( ' WRITE %s' % settingsProperty.setterName )
            self._outHeaderFile.write( ' )\n' )
    
    def createSelfFunctionInHeader(self):
        self._outHeaderFile.write('public:\n' )
        self._outHeaderFile.write('    static %s& self();\n\n' % self.className )
        
    def createClassInImpl(self):
        self._outImplFile.write('// Automatic generated configuration file. Do not change anything here!\n')
        self._outImplFile.write('#include "%s"\n\n' % self._headerFileName)
        self._outImplFile.write('#include <QApplication>\n\n')
        self._outImplFile.write('%s* %s::m_p%s = NULL;\n' % ( self.className, self.className, self.className ) )
        self._outImplFile.write('QSettings Globals::m_appDataBase( "%s", "%s" );\n\n' % (self.organization, self.application ) )
        
    def createSelfFunctionInImpl(self):
        self._outImplFile.write( '%s& %s::self()\n' % (self.className, self.className) )
        self._outImplFile.write( '{\n' )
        self._outImplFile.write( '    if ( m_p%s == NULL ){\n' % self.className)
        self._outImplFile.write( '        m_p%s = new %s;\n' % (self.className, self.className) )
        self._outImplFile.write( '        m_p%s->setParent( QApplication::instance() );  // This factory should be destroyed if qApp dies.\n' % self.className )
        self._outImplFile.write( '    }\n' )
        self._outImplFile.write( '    Q_ASSERT( m_p%s );\n' % self.className )
        self._outImplFile.write( '    if ( !m_p%s )\n' % self.className )
        self._outImplFile.write( '    { qFatal( "%s::self(): Out of memory!!" ); }\n' % self.className)
        self._outImplFile.write( '    return *m_p%s;\n' % self.className )
        self._outImplFile.write( '}\n\n' )

        
    def createGetterInHeader( self, settingsProperty ):
        if len( settingsProperty.getterName ) != 0:
            self._outHeaderFile.write('    %s %s();\n' % (settingsProperty.typeName, settingsProperty.getterName ) ); 

    def createGetterInImpl( self, settingsProperty ):
        if len( settingsProperty.getterName ) != 0:
            self._outImplFile.write('%s %s::%s()\n' % (settingsProperty.typeName, self.className, settingsProperty.getterName) )
            self._outImplFile.write('{\n')
            self._outImplFile.write('    return m_appDataBase.value( "%s", "%s" ).value<%s>();\n' % (settingsProperty.keyName, settingsProperty.defaultName, settingsProperty.typeName) )
            self._outImplFile.write('}\n\n')

    def createSetterInHeader( self, settingsProperty ):
        if len( settingsProperty.setterName ) != 0:
#            if self.typeName.endswith( '*' ):
#                self.paramSuffix = ''
#            else:
            self.paramSuffix = '&'

            self._outHeaderFile.write('    void %s( const %s%s v );\n' % (settingsProperty.setterName, settingsProperty.typeName, self.paramSuffix ) ); 

    def createSetterInImpl( self, settingsProperty ):
        if len( settingsProperty.setterName ) != 0:
#            if self.typeName.endswith( '*' ):
#                self.paramSuffix = ''
#            else:
            self.paramSuffix = '&'
                
            self._outImplFile.write('void %s::%s( const %s%s v )\n' % (self.className, settingsProperty.setterName, settingsProperty.typeName, self.paramSuffix) )
            self._outImplFile.write('{\n')
            self._outImplFile.write('    return m_appDataBase.setValue( "%s", v );\n' % (settingsProperty.keyName) )
            self._outImplFile.write('}\n\n')


    def closeClassInHeader(self):
        self._outHeaderFile.write('\nprivate:\n')
        self._outHeaderFile.write('    static %s* m_p%s;\n' % (self.className, self.className) )
        self._outHeaderFile.write('    static QSettings m_appDataBase;\n};\n\n')

def main( argv ):
    # Handle Arguments
    if ( len( argv ) < 2 ):
        print "genConfig <path to xml file> <path to export dir>"
        sys.exit(2)

    outFile = sys.stdout
    handler = ConfigFileHandler(argv[1])

    parser = make_parser()
    parser.setContentHandler(handler)
    parser.parse(argv[0])


if __name__ == "__main__":
    main(sys.argv[1:])

