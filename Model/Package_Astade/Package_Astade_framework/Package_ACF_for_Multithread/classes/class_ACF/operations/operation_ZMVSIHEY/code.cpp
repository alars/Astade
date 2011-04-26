//~~ void staticSendMessage(ACF_MessageReceiver* Source, ACF_MessageReceiver* Destination, const char* ID, ACF_MessageData* Data) [ACF] ~~
Destination->myACF->sendMessage(Source, Destination, ID, Data);
