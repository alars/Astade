#include <QMetaType>

Q_DECLARE_METATYPE(AQF_Message);

static int unsused_id_unly_for_declaration = qRegisterMetaType<AQF_Message>();
