#include <QMetaType>

Q_DECLARE_METATYPE(AQF_Message);

const static int unsused_id_only_for_declaration __attribute__((__unused__)) = qRegisterMetaType<AQF_Message>();